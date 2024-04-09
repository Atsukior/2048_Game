/*
 * @Date: 2023-12-18 10:27:27
 * @LastEditTime: 2023-12-25 14:15:22
 * @FilePath: \share\2048\play.c
 */

#include "play.h"
#include "lcd.h"
#include "color.h"

extern int score;

int left(int num[][4])
{
    int flag = 0; // 当前这种情况不存在有效滑动
    int i, j;
    for (i = 0; i < 4; i++)
    {
        // 1.把当前行的所有的数字向左移动
        int k = 0;
        int a[4] = {0};
        for (j = 0; j < 4; j++)
        {
            if (num[i][j] != 0)
            {
                a[k++] = num[i][j];
            }
        }
        // 2.合并，遍历当前行，是否有相邻且相等的数字
        for (j = 0; j < 3; j++)
        {
            if (a[j] == a[j + 1])
            {
                a[j] = a[j] * 2;
                a[j + 1] = 0;
                score += a[j];
            }
        }
        // 3.判断是否发生有效滑动
        for (j = 0; j < 4; j++)
        {
            if (a[j] != num[i][j])
            {
                flag = 1;
                break;
            }
        }

        // 4.把合并之后的数据向左移动，同时赋值回二维数组中去
        k = 0;
        for (j = 0; j < 4; j++)
        {
            if (a[j] != 0)
            {
                num[i][k++] = a[j];
            }
        }
        // 补0
        for (j = k; j < 4; j++)
        {
            num[i][j] = 0;
        }
    }
    return flag;
}

// 右滑操作
// 返回0表示没有合并或者平移（无效滑动），返回1表示存在合并或者平移（有效滑动）
int right(int num[][4])
{
    int flag = 0; // 当前这种情况不存在有效滑动
    int i, j;
    for (i = 0; i < 4; i++)
    {
        // 1.把当前行的所有的数字向右移动
        int k = 3;
        int a[4] = {0};
        for (j = 3; j >= 0; j--)
        {
            if (num[i][j] != 0)
            {
                a[k--] = num[i][j];
            }
        }
        // 2.合并，遍历当前行，是否有相邻且相等的数字
        for (j = 3; j > 0; j--)
        {
            if (a[j] == a[j - 1])
            {
                a[j] = a[j] * 2;
                a[j - 1] = 0;
                score += a[j];
            }
        }
        // 3.判断是否发生有效滑动
        for (j = 0; j < 4; j++)
        {
            if (a[j] != num[i][j])
            {
                flag = 1;
                break;
            }
        }

        // 4.把合并之后的数据向右移动，同时赋值回二维数组中去
        k = 3;
        for (j = 3; j >= 0; j--)
        {
            if (a[j] != 0)
            {
                num[i][k--] = a[j];
            }
        }
        // 补0
        for (j = k; j >= 0; j--)
        {
            num[i][j] = 0;
        }
    }
    return flag;
}

// 上滑操作
// 返回0表示没有合并或者平移（无效滑动），返回1表示存在合并或者平移（有效滑动）
int up(int num[][4])
{
    int flag = 0; // 当前这种情况不存在有效滑动
    int i, j;
    for (j = 0; j < 4; j++)
    {
        // 1.把当前列的所有的数字向上移动
        int k = 0;
        int a[4] = {0};
        for (i = 0; i < 4; i++)
        {
            if (num[i][j] != 0)
            {
                a[k++] = num[i][j];
            }
        }
        // 2.合并，遍历当前列，是否有相邻且相等的数字
        for (i = 0; i < 3; i++)
        {
            if (a[i] == a[i + 1])
            {
                a[i] = a[i] * 2;
                a[i + 1] = 0;
                score += a[i];
            }
        }
        // 3.判断是否发生有效滑动
        for (i = 0; i < 4; i++)
        {
            if (a[i] != num[i][j])
            {
                flag = 1;
                break;
            }
        }

        // 4.把合并之后的数据向上移动，同时赋值回二维数组中去
        k = 0;
        for (i = 0; i < 4; i++)
        {
            if (a[i] != 0)
            {
                num[k++][j] = a[i];
            }
        }
        // 补0
        for (i = k; i < 4; i++)
        {
            num[i][j] = 0;
        }
    }
    return flag;
}

// 下滑操作
// 返回0表示没有合并或者平移（无效滑动），返回1表示存在合并或者平移（有效滑动）
int down(int num[][4])
{
    int flag = 0; // 当前这种情况不存在有效滑动
    int i, j;
    for (j = 0; j < 4; j++)
    {
        // 1.把当前列的所有的数字向下移动
        int k = 3;
        int a[4] = {0};
        for (i = 3; i >= 0; i--)
        {
            if (num[i][j] != 0)
            {
                a[k--] = num[i][j];
            }
        }
        // 2.合并，遍历当前列，是否有相邻且相等的数字
        for (i = 3; i > 0; i--)
        {
            if (a[i] == a[i - 1])
            {
                a[i] = a[i] * 2;
                a[i - 1] = 0;
                score += a[i];
            }
        }
        // 3.判断是否发生有效滑动
        for (i = 0; i < 4; i++)
        {
            if (a[i] != num[i][j])
            {
                flag = 1;
                break;
            }
        }

        // 4.把合并之后的数据向下移动，同时赋值回二维数组中去
        k = 3;
        for (i = 3; i >= 0; i--)
        {
            if (a[i] != 0)
            {
                num[k--][j] = a[i];
            }
        }
        // 补0
        for (i = k; i >= 0; i--)
        {
            num[i][j] = 0;
        }
    }
    return flag;
}

void add_num(int num[][4])
{
    // 找到所有的空白位置并且记录下来
    int row[16] = {0}; // 保存横坐标
    int cow[16] = {0}; // 保存纵坐标
    int count = 0;     // 记录空白处有多少个

    // 遍历
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (num[i][j] == 0)
            {
                row[count] = i; // 保存当前0的横坐标
                cow[count] = j; // 保存当前0的纵坐标
                count++;
            }
        }
    }

    // 如果整个二维数组没有空白的地方，不需要添加数字
    if (count == 0)
    {
        return;
    }

    // 有count个0
    // 在随机位置添加随机数
    int r = rand() % count; // r的范围为[0,count)

    // 随机生成2或者4
    num[row[r]][cow[r]] = (rand() % 10 == 0) ? 4 : 2;
}

// 显示游戏界面
void show_interface(int num[][4])
{
    // 注意我设计的图片的像素是100 x 100的图片
    int coord_x[4] = {160, 280, 400, 520};
    int coord_y[4] = {20, 140, 260, 380};
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            char bmp_path_arr[255] = {0}; // 用来保存要显示图片的文件路径
            sprintf(bmp_path_arr, "/sarff/2048/%d.bmp", num[i][j]);
            // 显示对应数字的bmp图片
            bmp_display(bmp_path_arr, coord_x[j], coord_y[i]);
            display_integer(score, 0, 0);
        }
    }
}
// 判断游戏失败
int check_over(int num[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            // 1.存在空白位置
            if (num[i][j] == 0)
            {
                return 1; // 返回1表示游戏继续
            }
            // 2.存在相邻且相等的数字(横向)
            if (num[i][j] == num[i][j + 1] && j < 3)
            {
                return 1;
            }
            // 3.纵向存在相邻相等数字
            if (num[i][j] == num[i + 1][j] && i < 3)
            {
                return 1;
            }
        }
    }

    return 0; // 返回0表示游戏结束
}

// 判断游戏成功
int Game_success(int num[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (num[i][j] == 2048)
            {
                return 1; // 返回1表示游戏成功
            }
        }
    }
    return 0; // 返回0表示游戏还未成功，还需要努力。
}