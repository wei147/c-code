#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_CODE 80

void InitBoard(char board[ROWS][COLS],int row,int col,char set);
void DisplayBorad(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row,int col);
FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);