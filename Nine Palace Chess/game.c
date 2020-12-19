#include "game.h"

void InitBoard(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }  
}

// void DisplayBoard(char board[ROW][COL],int row,int col)
// {
//     int i=0;
//     for ( i = 0; i < row; i++)
//     {
//         // 1.打印一行的数据
//         printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//         // 2.打印分割行
//         if (i<row-1)
//         {
//             printf("---|---|---|\n");
//         } 
//     } 
// }

void DisplayBoard(char board[ROW][COL],int row,int col)
{
    int i=0;
    for ( i = 0; i < row; i++)
    {
        int j=0;
        for ( j = 0; j < col; j++)
        {
            // 1.打印一行的数据
            printf(" %c ",board[i][j]);
            if (j<col-1)
                printf("|");
        }
        printf("\n");
        // 2.打印分割行
        if (i<row-1)
        {
            for ( j = 0; j < col; j++)
            {
                printf("---");
                if (j<col-1)
                    printf("|");
            }
        }
        printf("\n");
    } 
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    printf("player go:>\n");
    while (1)
    {
        printf("please input your x y:>");
        scanf("%d%d",&x,&y);
        // 判断x,y坐标的合法性
        if (x>= 1 && x<=row && y>=1 && y<=col)
        {
            if (board[x-1][y-1] ==' ')
            {
                board[x-1][y-1] ='*';
                break;
            }
            else
            {
                printf("this is areadly\n");
            }
        }
        else
        {
            printf("it's not,please input again\n");
        }
    }  
}

void ComputerMove (char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    printf("computer go>:\n");
    while (1)
    {
        x=rand()%row;
        y=rand()%col;
        if (board[x][y]== ' ')
        {
        board[x][y] ='#';
        break;
        }
    } 
}
// 返回1表示棋盘满了
// 返回0，表示棋盘满了
int IsFull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (board[i][j] ==' ')
            {
                return 0;//没满
            }
        }
    }
    return 1;//满了
}

char IsWin(char board[ROW][COL],int row,int col)
{
    int i = 0;
    // 横三行
    for (i = 0; i < row; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] &&board[i][1]!=' ')
        {
            return board[i][1];
        }
    }
    //竖三列
    for ( i = 0; i < col; i++)
    {
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i] &&board[1][i]!=' ')
        {
            return board[1][i];
        }
    }
    //两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] !=' ')
    {
        return board[1][1];
    } 
    if (board[2][0] == board[1][1] && board[2][1] == board[0][2] && board[1][1] !=' ')
    {
        return board[1][1];
    } 
    if (1==IsFull(board,ROW,COL))
    {
        return 'Q';
    }
    return 'C';

}