#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("************    1.piay    **********\n");
	printf("************    0.exit    **********\n");
	printf("************************************\n");
}
void game()
{
	//储存信息
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 }; //11*11
	//2.排查出雷的信息
	char show[ROWS][COLS] = { 0 };//11*11
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();	//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{

	text();
	return 0;
}