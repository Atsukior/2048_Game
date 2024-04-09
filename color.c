/*
 * @Date: 2023-12-18 16:07:57
 * @LastEditTime: 2023-12-18 16:08:00
 * @FilePath: \share\2048\color.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void set_background_color()
{
    int fd = open("/dev/fb0", O_RDWR);
    if (fd == -1)
    {
        printf("open error!\n");
        return;
    }

    int buf[480][800] = {0};
    int i, j;
    for (i = 0; i < 480; i++)
    {
        for (j = 0; j < 800; j++)
        {
            buf[i][j] = 0x000000; // 设置为纯黑色
        }
    }

    int ret = write(fd, buf, 800 * 480 * 4);
    if (ret == -1)
    {
        printf("write error!\n");
        return;
    }

    close(fd);
}
