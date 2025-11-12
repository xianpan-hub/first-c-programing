//五子棋
#include"game.h"



int main()
{
	//棋盘元素
	char board[ROW][COL] = { 0 };

	int row = ROW;
	int col = COL;
	//1为你先手，-1为电脑先手
	int hand = 0;
	//'1'为你赢，'2'为电脑y赢，0为平局
	int is = 0;
	srand((unsigned int)time(NULL));
	
	while (Menu(row))
	{
			Board_int(board, row, col, ' ');	
			Board_print(board, row, col);
			hand = Pre(board, row, col);
			//board[6][4] = '2';
			//board[6][5] = '2';
			//board[4][6] = '2';
			//board[5][5] = '2';
			//你先手
			is = 0;
			if (hand == 1)
			{
				while (1)
				{
					is = Play_you(board, row, col);
					if (is != 0)
					{
						break;
					}
					//is = Play_com_ra(board, row, col);
					//if (is != 0)
					//{
					//	break;
					//}
				}
			}
			//电脑先手
			else if (hand == 2)
			{
				printf("到电脑下了\n");
				board[ROW/2][COL/2] = '2';
				Sleep(2000);
				while (1)
				{				
					//is = Play_com_ra(board, row, col);
					//if (is != 0)
					//{
					//	break;
					//}
					is = Play_you(board, row, col);
					if (is != 0)
					{
						break;
					}
				}
			}
		Print_end(board, row, col,is);
	}
	return 0;
}