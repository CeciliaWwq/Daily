#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()

{
	printf("*********************************\n");
	printf("************* 1.play ************\n");
	printf("************* 0.exit ************\n");
	printf("*********************************\n");
}

void init_board(char board[row][col])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}
void print_board(char board[row][col])
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("  %c | %c | %c  \n", board[i][0], board[i][1], board[i][2]);
		if (i != row-1)
		{
			printf(" ---|---|--- \n");
		}
	}
}

void player_move(char arr[row][col])
{
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if ((x >= 1) && (x <= row) && (y >= 1) && (y <= row) && (arr[x - 1][y - 1] == ' '))
		{
			arr[x - 1][y - 1] = 'X';
			break;
		}
		else
		{
			printf("坐标错误,请重新输入\n");
		}
	}
}

void computer_move(char arr[row][col])
{
	while (1)
	{
		int x = rand() % 3;//产生0到2的随机数组，刚好对应arr的下标；
		int y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			break;
		}
	}
}
int is_full(char arr[row][col])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char check_win(char arr[row][col])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//检测行是否相同；
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ');
		{
			return arr[i][0];
		}
	}
	for (j = 0; j < col;j++)//检测列是否相同；
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return arr[0][j];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')//检测对角线;
	{
		return arr[0][0];
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')//检测对角线;
	{
		return arr[0][2];
	}
	if (is_full(arr))
	{
		return'q';
	}
	return ' ';
}