/*
 * @Date: 2023-12-18 10:27:33
 * @LastEditTime: 2023-12-18 10:30:04
 * @FilePath: \share\2048\play.h
 */
#ifndef __PLAY_H__
#define __PLAY_H__

int left(int num[][4]);
int right(int num[][4]);
int up(int num[][4]);
int down(int num[][4]);
void add_num(int num[][4]);
void show_interface(int num[][4]);
int check_over(int num[][4]);
int Game_success(int num[][4]);

#endif