/*
 * @Date: 2023-12-25 10:55:19
 * @LastEditTime: 2023-12-25 14:13:18
 * @FilePath: \share\2048\score.h
 */
#ifndef __SCORE_H__
#define __SCORE_H__

extern unsigned char word[2][16 * 16 / 8];
extern unsigned char int_num[][42];
extern unsigned char Point[];

void zh_display(const char zh[], int x0, int y0, int w, int h);
void display_integer(int number, int x0, int y0);

#endif