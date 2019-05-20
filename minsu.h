#pragma once
#include <stdio.h>
#include <Windows.h>

void all();
void gotoxy(int x, int y);
void draw_basic_square(int x, int y);
void draw_score(int x, int y);
void draw_yutpan(int x, int y);
void board(int x, int y);
void mal_pan(int x, int y);
void draw_large_square(int x, int y);
void YutNori();
void setcolor(unsigned short text, unsigned short back);
void unsetcolor();
void yut(int x, int y);
void whatyut(int x, int y);
void explain(int x, int y);
void Print_Game();

