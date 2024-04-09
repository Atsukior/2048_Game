/*
 * @Date: 2023-12-13 09:42:25
 * @LastEditTime: 2023-12-16 19:08:28
 * @FilePath: \share\2048\srand.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    scanf("%d", &num);

    srand(time(NULL));

    printf("%d\n", rand() % num);
    return 0;
}