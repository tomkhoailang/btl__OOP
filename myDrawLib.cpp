#include "myDrawLib.h"
#include<windows.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<unistd.h>
#include<conio.h>
using namespace std;

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void drawBox(int x, int y, int w, int h, int b_color, int t_color, string content, string align) {
	if (h < 1 || w < 1) return;
	
	SetColor(b_color);
	
	for(short ix = x; ix <= x + w; ix++){
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y+h);
		cout << char(196);
	}
	
	for(short iy = y; iy <= y + h; iy++){
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + w, y); 
	cout << char(191);
	gotoXY(x, y + h);
	cout << char(192);
	gotoXY(x + w, y + h); 
	cout << char(217);
	
	SetColor(t_color);
	if(align == "center"){
		gotoXY(x + (round(w / 2) - round(content.length() / 2)), y + round(h / 2)); // center content
		cout << content << endl;
	}else if(align == "left"){
		gotoXY(x + 2, y + round(h / 2)); 
		cout << content << endl;
	}else if(align == "right"){
		gotoXY((x + w - 1) - content.length(), y + round(h / 2));
		cout << content << endl;
	}
}
void currentTarget(int x, int y, int w, int h, int b_color, int t_color, string content, string align) {
	if (h < 1 || w < 1) return;
	
	textColor(b_color);
	
	for(short yi = y+1; yi <= y + h-1; yi++){
		for(short xi = x+1; xi <= x + w - 1; xi++){
			gotoXY(xi, yi);
			cout << " ";
		}
	}
	
	SetColor(t_color);
	if(align == "center"){
		gotoXY(x + (round(w / 2) - round(content.length() / 2)), y + round(h / 2)); // center content
		cout << content << endl;
	}else if(align == "left"){
		gotoXY(x + 2, y + round(h / 2)); 
		cout << content << endl;
	}else if(align == "right"){
		gotoXY((x + w - 1) - content.length(), y + round(h / 2));
		cout << content << endl;
	}
//	textColor(0);
}

void loadingAnimation(int x, int y, string loadContent, string loadContentDone){
	int loadingBarLength = 80;
	ShowCur(0);
	SetColor(127);
	gotoXY(x + round(loadingBarLength*1.0/2) - round(loadContent.length() / 2),y);
	cout << loadContent << endl;
	
	gotoXY(x, y+2);
	for(short i = 0;i < loadingBarLength;i++){
		cout << char(177);
	}
	cout << "\r";
	gotoXY(x, y+2);
	for(short i = 0;i < loadingBarLength; i++){
		cout << char(219);
		usleep(1200);
	}
	
	gotoXY(x + round(loadingBarLength*1.0/2) - round(loadContentDone.length() / 2),y+4);
	cout << loadContentDone << endl;
	sleep(1);
}




