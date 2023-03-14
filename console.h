#pragma once
#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<io.h>
#include<fcntl.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include "resource.h"
//#include <ctime>

using namespace std;

void gotoxy(int x, int y);
void setColor(int color, int bgColor);
void fullScreen();
void WINDOWEDScreen();
void CursorHide();
int OriginalCurX();
int OriginalCurY();
//void CursorHide();

