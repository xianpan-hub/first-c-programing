#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#define _CRT_SECURE_NO_WARNINGS
//11为三子棋，23为五子棋
#define ROW 23
#define COL 23

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>

//2.五子棋
int Menu(int row);
void Board_int(char board[ROW][COL], int row, int col,char set);
void Board_print(char board[ROW][COL], int row, int col);
int Win_who(char board[ROW][COL], int row, int col,int i,int j,char set);
int Win(char board[ROW][COL], int row, int col, int i, int j, char set,int m,int o);
int Pre(char board[ROW][COL], int row, int col);
int Play_you(char board[ROW][COL], int row, int col);
int Play_com_ra(char board[ROW][COL], int row, int col);
void Print_end(char board[ROW][COL], int row, int col,int is);
//贪心，一步，简单模型，少量误差
int Greed_all (char board[ROW][COL], int row, int col, int i, int j);
int Greed_a(char board[ROW][COL], int row, int col, int i, int j,int m);
int Greed_b(char board[ROW][COL], int row, int col, int i, int j, int m);
int Greed(char board[ROW][COL], int q, int w,char set,int c);

#endif
