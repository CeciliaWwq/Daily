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
		player_move(arr);//�������
		if ((ret = check_win(arr)) != ' ')//������������˵��˭Ӯ�˻�ƽ�֣��Ǿ�����ѭ���ж�
			break;

		computer_move(arr);//��������
		if ((ret = check_win(arr)) != ' ')//������������˵��˭Ӯ�˻�ƽ�֣��Ǿ�����ѭ���ж�
		break;
		print_board(arr);//��ӡ�������͵��Ե���λ
		printf("\n");
    }
	if (ret == 'x')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '0')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'q')
	{
		printf("ƽ��\n");
	}
	print_board(arr);
}
int main()
{
	srand((unsigned int)time(NULL));//���������������
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