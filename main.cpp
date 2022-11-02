#include<string>
#include<vector>
#include"menu.h"
#include<conio.h>
#include<cmath>

int main() {
	ListGoods list;
	Manager managerList;
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);  // mo man hinh console dang fullscreen
	LoginMenu loginMenu(90, 2, "DANG NHAP");
	  	
	if(loginMenu.startLoginMenu()){
		system("cls");
		readDataFromFile(list);
		readManagerDataFromFile(managerList);
		list.addCode(id_List);
		
		if(loginMenu.getRole() == "manager"){
			vector<string> menuContent{
								"Nhap hang hoa",   
								"Xuat hang hoa",
								"Tim kiem",
								"Cap nhat hang hoa",
								"Xuat thong tin vao file",  
								"Quan ly",
								"Thoat"
								};
			ListMenu ListMenu(90, 2, menuContent, "MENU QUAN LY");
			ListMenu.start(list, loginMenu.getRole(), managerList, loginMenu.getUsername());
		}else if(loginMenu.getRole() == "employee"){
			
			vector<string> menuContent{
							"Nhap hang hoa",
							"Xuat hang hoa",
							"Tim kiem",
							"Cap nhat hang hoa",
							"Xuat thong tin vao file",
							"Thong tin nhan vien",
							"Thoat"
							};
							
			ListMenu ListMenu(90, 2, menuContent, "MENU NHAN VIEN");
			ListMenu.start(list, loginMenu.getRole(), managerList, loginMenu.getUsername());
		}
	}

	return 0;
}



