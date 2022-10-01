#include"menu.h"

// Danh sach hang hoa
int main() {
	ListGoods list;
	HWND hWnd = GetConsoleWindow();
  	ShowWindow(hWnd,SW_SHOWMAXIMIZED);  // mo man hinh console dang fullscreen
	
	vector<string> menuContent{
							   "Nhap hang hoa",
							   "Xuat hang hoa",
							   "Tim kiem",
							   "Cap nhat hang hoa",
							   "Xuat thong tin vao file",
							   "Chuc Nang Trong",
							   "Thoat"};
							   
	Menu menu(90, 2, menuContent, "QUAN LY CUA HANG");
  	
	readDataFromFile(list);
	list.addCode(id_List);
	menu.start(list);
	_getch();
	return 0;
}





