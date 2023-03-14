#include "console.h"

COORD cur;

void gotoxy(int x, int y) 
{
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(hout, cur);
}

int OriginalCurX()
{
	return cur.X;
}

int OriginalCurY()
{
	return cur.Y;
}


void setColor(int color, int bgColor) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | color);
}
void fullScreen() 
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void WINDOWEDScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
}

void CursorHide()
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
