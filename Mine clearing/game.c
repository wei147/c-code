#include "game.h"

void InitBoard(char board[ROWS][COLS],int row,int col,char set)
{
    int j=0;
    int i=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            board[i][j]=set;
        }
    }
}

void DisplayBorad(char board[ROWS][COLS],int row,int col)
{
    int i =0;
    int j =0;
    // 打印列号
    for ( i = 0; i <= col; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    
    for ( i = 1; i <= row; i++)
    {
        // 打印行号
        printf("%d ",i);
        for ( j = 1; j <= col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS],int row,int col)
{
    int count=EASY_CODE;
    while (count)
    {
        int x=rand()%row+1;//1-9
        int y=rand()%col+1;
        if (board[x][y] =='0')
        {
            board[x][y] = '1';
            count--;
        }  
    }
}

get_mine_count(char mine[ROWS][COLS],int x,int y)
{
    return mine[x-1][y] +
    mine[x-1][y-1] +
    mine[x][y-1] +
    mine[x+1][y-1] +
    mine[x+1][y] +
    mine[x+1][y+1] +
    mine[x][y+1] +
    mine[x-1][y+1] -8*'0';
}

FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    int win=0;
    while (win<row*col-EASY_CODE)
    {
    printf("please input LEI x y:>\n");
    scanf("%d%d",&x,&y);
    if (x>=1 && x<=row && y>=1 && y<= col)
    {
        // 坐标合法
        //1.踩雷
        if (mine[x][y]=='1')
        {
            printf("sorry,you are fail\n");
            DisplayBorad(mine,row,col);
            break;
        }
        else//不是雷
        {
            // 计算x，y坐标周围有几个雷
            int count= get_mine_count(mine,x,y);
            show[x][y] =count+'0';
            DisplayBorad(show,row,col);
            win++;
        }
    }
    else
    {
        printf("it's not,please input again\n");
    }
    }
    if (win==row*col-EASY_CODE)
    {
        printf("lucky,you win!\n");
        printf("about the LEI image:\n");
        DisplayBorad(mine,ROW,COL);
    } 
}