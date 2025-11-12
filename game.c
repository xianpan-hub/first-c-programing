#include"game.h"

//打印菜单
int Menu(int row)
{
	int i = 0;
	system("cls");
		do 
		{printf("\n");
		if (row - 8 == 3)
		{
			printf("                      三子棋                         \n");
		}
		else if (row - 8 == 15)
		{
			printf("                      五子棋                         \n");
		}
		printf("*****************************************************\n");
		printf("*******1.开始游戏***************2.退出游戏***********\n");
		printf("*****************************************************\n");
		printf("\n");
		printf("请选择：>");
		
		scanf("%d", &i);
		while (getchar() != '\n');
		if (i == 1)
		{
			system("cls");
			printf("开始游戏\n");
			return 1;
		}
		else if (i == 2)
		{
			printf("退出游戏\n");
			return 0;
		}
		else
		{
			printf("无效选择\n");
			Sleep(2000);
			system("cls");
		}
		} while (1);
}

//重置棋盘
void Board_int(char board[ROW][COL], int row, int col, char set)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col;j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void Board_print(char board[ROW][COL], int row, int col)
{
	printf("\n");
	for (int k = 4; k < col - 4; k++)
	{
		if (k == 4)
		{
			printf("    ");
		}
		printf("  %2d", k-3);
		if (k == col - 5)
		{
			printf("\n");
		}
	}
	for (int i = 4; i < row-4; i++)
	{
		int is = 0;
		printf(" %2d  ", i-3);
		for (int j = 4; j < col-4; j++)
		{	

			if (i != row - 5&&j!=col-5)
			{
				printf(" %c ", board[i][j]);
				printf("|");
				is = 1;
			}
			else if (j == col - 5&&i!=row-5)
			{
				printf(" %c ", board[i][j]);
				is = 1;
			}
			else if (j != col - 5 && i == row - 5)
			{
				printf(" %c ", board[i][j]);
				printf("|");
			}
			else
			{
				printf(" %c ", board[i][j]);
			}
		}
		printf("\n");
		if (is == 1)
		{
			printf("     ");
			for (int j = 4; j < col-4; j++)
			{
				
				printf("----");
			}
		}
		printf("\n");
	}
}

//判断谁赢
int Win_who(char board[ROW][COL], int row, int col,int i,int j,char set)
{
	int m = 0;
	//判断五子棋
	if(row - 8 == 15)
	{
		m = 5;
	}
	//判断三子棋
	else if (row - 8 == 3)
	{
		m = 3;
	}
	//标记是否胜利，0未分胜负，其他分胜负‘1’你，‘2’电脑，‘ ’平局
	int is = 0;
	//标记是否有空格，0为无，1为有
	int is_planket = 0;
	//判断行
	is = Win(board, row, col, i, j, set,m,1);
	if (is == 0)
	//判断列
	{
		is = Win(board, row, col, i, j, set, m,2); 
		if (is == 0)
			//判断主对角线
		{
			is = Win(board, row, col, i, j, set, m,3); 
				//判断副对角线
			if (is == 0)
			{
				is = Win(board, row, col, i, j, set, m, 4); 
				if (is == 0)
					//判断平局
				{
					for (int q = 4; q < row - 4; q++)
					{
						for (int w = 4; w < col - 4; w++)
						{
							if (board[q][w] == ' ')
							{
								is_planket = 1;
								break;
							}
							else if (q == row - 5 && w == col - 5)
							{
								is = ' ';
							}
						}
						if (is_planket == 1)
						{
							break;
						}
                      
					}
				}
			}
		}
	}
	return is;
}

//判断赢的分函数
int Win(char board[ROW][COL], int row, int col, int i, int j, char set,int m,int o)
{
	//同色连续棋子数
    int l = 0;
	int p = 0;
	switch (o)
	{
	case 1:	
		for (int k = j - 4; k <= j + 4; k++)
	{
		if (board[i][k] == set)
		{
			l++; 
		}
		else
		{
			l = 0;
		}
		if (l == m)
		{
			p = set;
		}
	}
		l = 0;
		break;
	case 2:
		for (int k = i - 4; k <= i + 4; k++)
		{
			if (board[k][j] == set)
			{
				l++; 
			}
			else
			{
				l = 0;
			}
			if (l == m)
			{
				p = set;
			}
		}
		l = 0;
		break;
	case 3:
		for (int k = i - 4, k1=j-4; k <= i + 4; k++,k1++)
		{
			
			if (board[k][k1] == set)
			{
				l++; 
			}
			else
			{
				l = 0;
			}
			if (l == m)
			{
				p = set;
			}
		}
		l = 0;
		break;
	case 4:
		for (int k = i - 4, k1 = j + 4; k <= i + 4; k++, k1--)
		{

			if (board[k][k1] == set)
			{
				l++; 
			}
			else
			{
				l = 0;
			}
			if (l == m)
			{
				p = set;
			}
		}
		l = 0;
		break;
	}
	return p;
}

//预备下棋
int Pre(char board[ROW][COL], int row, int col)
{
	int i = 0;
	do
	{
	printf("1表示你下的棋子，2表示电脑下的棋子\n");
	printf("\n");
	printf("*****************************************************\n");
	printf("***********1.先手*******************2.后手***********\n");
	printf("*****************************************************\n");
	printf("\n");
	printf("请选择：>");
	scanf("%d", &i);
	while (getchar() != '\n');
	if (i == 1)
	{
		printf("你先手\n");
		break;
	}
	else if (i == 2)
	{
		printf("电脑先手\n");
		break;
	}
	else
	{
		printf("无效选择\n");
		Sleep(2000);
		system("cls");
	}} while (1);
	Sleep(2000);
	return i;
}

//你下
int Play_you(char board[ROW][COL], int row, int col)
{
	int o = 0;
	system("cls");
	Board_print(board, row, col);
	printf("到你下了,请输入如“3，6”的坐标：>");
	int i = 0;
	int j = 0;
	do
	{	
		scanf("%d，%d", &i, &j);

		while (getchar() != '\n');
		if (i > row-8 || i < 1 || j>col-8 || j < 1)
		{
			printf("坐标非法，请重新输入如“3，6”的坐标：>");
		}
		else if (board[i+3][j+3] != ' ')
		{
			printf("该格已被占用，请重新输入如“3，6”的坐标：>");
		}
		else
		{
			i += 3;
		    j += 3;
			board[i][j] = '1';
			break;
		}
	} while (1);
	o=Win_who(board, row, col, i, j, '1');
	if (o == 0)
	{
		o = Greed_all(board, row, col, i, j);
	}
	return o;
}

//电脑下,随机
int Play_com_ra(char board[ROW][COL], int row, int col)
{
	system("cls");
	printf("到电脑下了\n");
	int i = 0;
	int j = 0;
	do {
		i = rand() % (row - 8)+4;
		j = rand() % (col - 8) + 4;
		if (board[i][j] == ' ')
		{
			board[i][j] = '2';
			break;
		}
	} while (1);
	Sleep(2000);
	return Win_who(board, row, col, i, j, '2');
}

//打印胜负
void Print_end(char board[ROW][COL], int row, int col,int is)
{
	system("cls");
	if (is == '1')
	{
		printf("你赢了！！！\n");
	}
	else if (is == '2')
	{
		printf("电脑赢了！！！\n");
	}
	else if(is==' ')
	{
		printf("平局！！！\n");
	}

	Board_print(board, row, col);
	Sleep(2000);
	system("cls");
}

//贪心，总
int Greed_all(char board[ROW][COL], int row, int col,int i,int j)
{
	int m = 0;
	//判断五子棋
	if (row - 8 == 15)
	{
		m = 5;
	}
	//判断三子棋
	else if (row - 8 == 3)
	{
		m = 3;
	}
	if (m == 3)
	{
		return Greed_a(board, row, col, i, j, m);
	}
	else if (m == 5)
	{
		return Greed_b( board,  row,  col,  i,  j,  m);
	}
	return 0;
}

//贪心，分，三子棋
int Greed_a(char board[ROW][COL], int row, int col,  int i, int j,int m)
{
	//模拟二十五宫格，统计得分
	int board_[(ROW-8)*2-1][(COL-8)*2-1] = {0};
	//再下一子能连三/连二
	for (int q = 0; q < 2*m-1; q++)
	{
		for (int w = 0; w < 2*m-1; w++)
		{//同色连续棋子数
			int l = 0;
			int p = 0;
			//假设下一子
			if (board[i - m + 1 + q][j - m + 1 + w] == ' '&& i - m + 1 + q>=4&& i - m + 1 + q<=6
				&& j- m + 1 + w >= 4 && j - m + 1 + w <= 6)	
			{
				board[i - m + 1 + q][j - m + 1 + w] = '1';
					for (int k = j - 4; k <= j + 4; k++)
					{   int max = 0;
						if (board[i][k] == '1')
						{
							l++;
							if (l > max)
							{
								max = l; /*printf("max=%d\n", max);*/
							}
						}
						else
						{
							l = 0;
						}
						if (max==m)
						{
							p += 100;
						}
						else if (max == m - 1)
						{
							p += 10;
						}
						
					}
					l = 0;
					for (int k = i - 4; k <= i + 4; k++)
					{
						int max = 0;
						if (board[k][j] == '1')
						{
							l++;
							if (l > max)
							{
								max = l; /*printf("max=%d\n", max);*/
							}
						}
						else
						{
							l = 0;
						}
						if (max == m)
						{
							p += 100;
						}
						else if (max == m - 1)
						{
							p += 10;
						}
					}
					l = 0;
					for (int k = i - 4, k1 = j - 4; k <= i + 4; k++, k1++)
					{
						int max = 0;
						if (board[k][k1] == '1')
						{
							l++;
							if (l > max) 
							{
								max = l; /*printf("max=%d\n", max);*/
							}
						}
						else
						{
							l = 0;
						}
						if (max == m)
						{
							p += 100;
						}
						else if (max == m - 1)
						{
							p += 10;
						}
					}
					l = 0;
					for (int k = i - 4, k1 = j + 4; k <= i + 4; k++, k1--)
					{
						int max = 0;
						if (board[k][k1] == '1')
						{
							l++;
							if (l > max)
							{
								max = l; /*printf("max=%d\n", max);*/
							}
						}
						else
						{
							l = 0;
						}
						if (max == m)
						{
							p += 100;
						}
						else if (max == m - 1)
						{
							p += 10;
						}
						//printf("p=%d\n", p);
					}
					l = 0;
				board[i - m + 1 + q][j - m + 1 + w] = ' ';
				board_[q][w] = p;
			}
		}
	}
	int max=board_[0][0];
	int q_max = 0;
	int w_max = 0;
	for (int q = 0; q < 2*m-1; q++)
	{
		for (int w = 0; w < 2*m-1; w++)
		{
			//printf("board_[%d][%d]=%d ", q, w, board_[q][w]);
			if (board_[q][w] > max)
			{
				max = board_[q][w];
			    q_max = q;
				w_max = w;
			}
			//if (w == 2 * m - 2)
			//{
			//	printf("\n");
			//}
		}
	}
	board[q_max+i-m+1][w_max+j-m+1] = '2';
	//printf("board[%d][%d] = %c\n", q_max + i - m + 1, w_max + j - m + 1, board[q_max + i - m + 1][w_max + j - m + 1]);
	return Win_who(board, row, col, q_max + i - m + 1, w_max + j - m + 1, '2');
}

//贪心，分，五子棋
int Greed_b(char board[ROW][COL], int row, int col, int i, int j, int m)
{
	//模拟八十一宫格，统计得分
	int board_[9][9] = { 0 };
	for (int q = 0; q < 2 * m - 1; q++)
	{
		for (int w = 0; w < 2 * m - 1; w++)
		{
			//分数
			int p = 0;
			//假设各下一子
			if (board[i - m + 1 + q][j - m + 1 + w] == ' ' && i - m + 1 + q >= 4 && i - m + 1 + q <= 18
				&& j - m + 1 + w >= 4 && j - m + 1 + w <= 18)
			{	
				board[i - m + 1 + q][j - m + 1 + w] = '1';
				p +=Greed(board ,i - m + 1 + q, j - m + 1 + w,'1', 1);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '1', 2);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '1', 3);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '1', 4);
				board[i - m + 1 + q][j - m + 1 + w] = '2';
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '2', 1);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '2', 2);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '2', 3);
				p += Greed(board, i - m + 1 + q, j - m + 1 + w, '2', 4);
				board[i - m + 1 + q][j - m + 1 + w] = ' ';
				board_[q][w] = p;
			}
		}
	}
	int max = board_[0][0];
	int q_max = 0;
	int w_max = 0;
	for (int q = 0; q < 2 * m - 1; q++)
	{
		for (int w = 0; w < 2 * m - 1; w++)
		{
			printf("board_[%d][%d]=%d ", q, w, board_[q][w]);
			if (board_[q][w] > max)
			{
				max = board_[q][w];
				q_max = q;
				w_max = w;
			}
			if (w == 2 * m - 2)
			{
				printf("\n");
			}
		}
	
	}		
	printf("到电脑下了\n");
		Sleep(2000);
	if (board[i - m + 1 + q_max][j - m + 1 + w_max] == ' ' && i - m + 1 + q_max >= 4 && i - m + 1 + q_max <= 18
		&& j - m + 1 + w_max >= 4 && j - m + 1 + w_max <= 18)
	{
		board[q_max + i - m + 1][w_max + j - m + 1] = '2';
	}
	else
	{
		Play_com_ra(board, row, col);
	}
	return Win_who(board, row, col, q_max + i - m + 1, w_max + j - m + 1, '2');
}

//贪心，五子棋，分方向
//连四，连五
int Greed(char board[ROW][COL], int a, int b,char set,int c)
{
	//分数
	int p = 0;
	int e, d = 0;
	//记录，1为本方，0为空格，-1为敌方
		int cheek[9] = { 0 };
		for (int i = a, k = a + 8, j = b; i < a + 9; i++, j++, k--)
		{
			switch (c)
			{
			case 1:
				e = a;
				d = j-4;
				break;
			case 2:
				e = i-4;
				d = b;
				break;
			case 3:
				e = i-4;
				d = j-4;
				break;
			case 4:
				e = k-4;
				d = j-4;
				break;
			}
				if (e >= 0 && e <= 22 && d >= 0 && d <= 22&&board[e][d] == set)
				{
					cheek[i - a] = 1;
				}
				if (e >= 0 && e <= 22 && d >= 0 && d <= 22 && board[e][d] != set && board[e][d] != ' ')
				{
					cheek[i - a] = -1;
				}
				if (i - a >= 5)
				{
					//活四，‘’表示在这判断
					//01111'0'，
					if (cheek[i - a - 5] == 0 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 0)
					{
						p += 10000;
					}
					else if (
						//连四
						//-1111'1'0
						(cheek[i - a - 5] == -1 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 0)
						//0111'1'-1
						|| (cheek[i - a - 5] == 0 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == -1)
						)
					{
						p += 1000;
					}
					//活三，	
					else if (
						//01110'0'
						(cheek[i - a - 5] == 0 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 0 && cheek[i - a] == 0)
						//或00111'0'
						|| (cheek[i - a - 5] == 0 && cheek[i - a - 4] == 0 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 0)
						//或01101'0'
						|| (cheek[i - a - 5] == 0 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 0 && cheek[i - a - 1] == 1 && cheek[i - a] == 0)
						//或01011'0'
						|| (cheek[i - a - 5] == 0 && cheek[i - a - 4] == 1 && cheek[i - a - 3] == 0 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 0)
						)
					{
						p += 1001;
					}
				}
				if (i - a >= 4)
				{
					//连五，1111'1'，
					if (cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 1)
					{
						p += 100000;
					}
					if (
						//连四
						//1110'1'
						(cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 0 && cheek[i - a] == 1)
						//1011'1'
						|| (cheek[i - a - 4] == 1 && cheek[i - a - 3] == 0 && cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 1)
						//1101'1'
						|| (cheek[i - a - 4] == 1 && cheek[i - a - 3] == 1 && cheek[i - a - 2] == 0 && cheek[i - a - 1] == 1 && cheek[i - a] == 1)
						)
					{
						p += 1000;
					}
				}
				if (i - a >= 3)
				{
					//活二
					if (
						//！11'1'
						(cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] != 1)
						//11'！1'
						|| (cheek[i - a - 2] != 1 && cheek[i - a - 1] == 1 && cheek[i - a] == 1)
						)
					{
						p += 100;
					}
				}
				if (i - a >= 2)
				{
					//连二
					if (
						//-11'1'
						(cheek[i - a - 2] == 1 && cheek[i - a - 1] == 1 && cheek[i - a] != 1)
						//11'-1'
						|| (cheek[i - a - 2] != 1 && cheek[i - a - 1] == 1 && cheek[i - a] == -1)
						)
					{
						p += 10;
					}
				}
			

		}
		//for (int h = 0; h < 9; h++)
		//{
		//	printf("cheek[%d]=%d\n", h, cheek[h]);
		//}
		return p;
}