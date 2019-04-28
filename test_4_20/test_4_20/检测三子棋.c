#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char arr[row][col];
	int x = 0;
	int y = 0;
	char ret = 0;
	init_board(arr);
	print_board(arr);
	printf("\n");
	while (1)
	{
		player_move(arr);//玩家下棋
		if ((ret = check_win(arr)) != ' ')//里面条件成立说明谁赢了或平局，那就跳出循环判断
			break;

		computer_move(arr);//电脑下棋
		if ((ret = check_win(arr)) != ' ')//里面条件成立说明谁赢了或平局，那就跳出循环判断
		break;
		print_board(arr);//打印出这次你和电脑的走位
		printf("\n");
    }
	if (ret == 'x')
	{
		printf("玩家赢\n");
	}
	else if (ret == '0')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'q')
	{
		printf("平局\n");
	}
	print_board(arr);
}
int main()
{
	srand((unsigned int)time(NULL));//设置随机数生成器
	int choise = 0;

	do
	{
		menu();
		printf("please input your choise:\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			game();
			break;
		case 2:
				break;
		defaulf:
				printf("input error!please try again");
				break;
		}
	} 
	while (1);
	system("pause");
	return 0;
}