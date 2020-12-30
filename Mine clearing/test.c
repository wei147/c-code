
#include "game.h"
#include "game.c"

void menu()
{
    printf("*********************************\n");
    printf("**********   1.play   ***********\n");
    printf("**********   0.exit   ***********\n");
    printf("*********************************\n");
}

void game()
{
    // 雷的信息存储
    //1.布置好雷的信息 
    char mine[ROWS][COLS]={0}; //11 * 11
    // 2.排查出雷的信息
    char show[ROWS][COLS]={0}; //展示给用户的
    // 初始化
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    // 打印棋盘
    DisplayBorad(mine,ROW,COL);
    // 布置雷
    SetMine(mine,ROW,COL);
    DisplayBorad(mine,ROW,COL);
    // 扫雷
    FindMine(mine,show,ROW,COL);
}
void test()
{
    int input =0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("please input choose:>");
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
            printf("please input 1 or 0\n");
            break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}