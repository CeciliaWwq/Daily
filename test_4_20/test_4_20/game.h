#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME__H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define col 3
#define row 3
void meun();
void Init_borad(char arr[row][col]);
void print_borad(char arr[row][col]);
void player_move(char arr[row][col]);
void computer_move(char arr[row][col]);
char check_win(char arr[row][col]);
int is_full(char arr[row][col]);
char check_win(char arr[row][col]);

#endif  //__GAME_H__