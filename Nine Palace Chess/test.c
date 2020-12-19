// 测试三子棋游戏
#include "game.c"
#include "game.h"

void menu()
{
    printf("******************************\n");
    printf("*******1.play    0.exit*******\n");
    printf("******************************\n");
}
// 游戏的整个算法实现
void game()
{
    char ret =0;
    // 数组 - 存放走出的棋盘信息
    char board[ROW][COL]={0};//全部空格
    // 初始化棋盘
    InitBoard(board,ROW,COL);
    // 打印棋盘
    DisplayBoard(board,ROW,COL);
    // 下棋
    while (1)
    {
        // 玩家下棋
        PlayerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        // 判断玩家是否赢
        ret=IsWin(board,ROW,COL);
        if (ret !='C')
        {
            break;
        }
        // 电脑下棋
        ComputerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        // 判断电脑是否赢
        ret=IsWin(board,ROW,COL);
        if (ret !='C')
        {
            break;
        }
    }
    if (ret =='*')
    {
        printf("player win\n");
    }
    else if (ret == '#')
    {
        printf("computer win\n");
    }
    else
    {
        printf("it's no winner...");
    }
    
}
void test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("please choose:>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("exit\n");
            break;           
        
        default:
            printf("please choose 0 or 1\n");
            break;
        }
    } while (input);
    
}
int main()
{
    test();
    return 0;
}