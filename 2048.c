/*
 * @Date: 2023-12-13 11:16:52
 * @LastEditTime: 2023-12-17 19:41:02
 * @FilePath: \share\2048\2048.c
 */
#include <stdio.h>

// 左滑操作
// 返回0表示没有合并或者平移（无效滑动），返回1表示存在合并或者平移（有效滑动）
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
// 打印棋盘
void print(int num[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        printf("+----+----+----+----+\n");
        for (j = 0; j < 4; j++)
        {
            printf("|");
            if (num[i][j] == 0)
            {
                printf("    ");
            }
            else
            {
                printf("%4d", num[i][j]);
            }
        }
        printf("|\n");
    }
    printf("+----+----+----+----+\n");
}

// 判断游戏是否结束
// 返回0表示游戏结束，返回1表示游戏未结束
int isOver(int num[][4])
{
    int i, j;
    // 1.判断是否有空格
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (num[i][j] == 0)
            {
                return 1;
            }
        }
    }
    // 2.判断是否有相邻且相等的数字
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (num[i][j] == num[i][j + 1])
            {
                return 1;
            }
        }
    }
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (num[i][j] == num[i + 1][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

// 生成随机数
void randNum(int num[][4])
{
    int i, j;
    int x, y;
    do
    {
        x = rand() % 4;
        y = rand() % 4;
    } while (num[x][y] != 0);
    num[x][y] = 2;
}

int main()
{
    int num[4][4] = {0};
    int i, j;
    int flag = 0;
    int score = 0;
    char ch;
    srand(time(NULL));
    randNum(num);
    randNum(num);
    print(num);
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'a')
        {
            flag = left(num);
            score++;
        }
        else if (ch == 'd')
        {
            flag = right(num);
            score++;
        }
        else if (ch == 'w')
        {
            flag = up(num);
            score++;
        }
        else if (ch == 's')
        {
            flag = down(num);
            score++;
        }
        else if (ch == 'q')
        {
            break;
        }
        else
        {
            continue;
        }
        if (flag == 1)
        {
            randNum(num);
            print(num);
        }
        if (isOver(num) == 0)
        {
            printf("GAME OVER!\n");
            printf("Your score is %d,zako~❤️\n", score);
            break;
        }
    }
    return 0;
}