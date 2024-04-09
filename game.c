/*
 * @Date: 2023-12-18 09:41:16
 * @LastEditTime: 2023-12-25 14:20:47
 * @FilePath: \share\2048\game.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ts.h"
#include "lcd.h"
#include "bmp.h"
#include "play.h"
#include "color.h"
#include "score.h"

int score = 0;

void play_2048_game(int num[][4])
{
    // 设置随机数种子
    srand(time(NULL));

    // 随机在任意空白位置添加2/4,2出现的概率为9/10,4出现的概率为1/10
    // 随机生成两个数字
    add_num(num);
    add_num(num);

    // 显示游戏界面
    show_interface(num);

    // 当flag == 0 时,为无效滑动，不需要再添加数字
    // 当flag == 1 时，为有效滑动，此时需要添加一个数字
    int flag = 0;

    while (check_over(num)) // 游戏是否失败
    {
        move_dir_t dir = get_ts_direction();
        if (dir == MOVE_UP)
        {
            flag = up(num);
        }
        else if (dir == MOVE_DOWN)
        {
            flag = down(num);
        }
        else if (dir == MOVE_LEFT)
        {
            flag = left(num);
        }
        else if (dir == MOVE_RIGHT)
        {
            flag = right(num);
        }

        if (flag == 1)
        {
            add_num(num);
        }

        show_interface(num);

        if (Game_success(num))
        {
            // 设置背景色为纯黑色
            set_background_color();
            printf("game success\n");
            bmp_display("/sarff/dragon.bmp", 100, 0); // 纯属是游戏成功的标志，具体显示什么你自己决定
            break;
        }

        else if (!check_over(num)) // 如果游戏失败了，直接跳出循环，不执行后面的代码
        {
            // 设置背景色为纯黑色
            set_background_color();
            printf("GAME OVER!,zako~❤️\n");
            bmp_display("/sarff/zako.bmp", 176, 0); // 游戏失败的标志
            break;
        }
    }
}

int main()
{
    int num[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};


    // 初始化LCD屏幕
    lcd_open();

    // 设置背景为原神
    bmp_display("/sarff/image2", -10, 0);

    // 开始游戏
    play_2048_game(num);

    lcd_close();

    return 0;
}
