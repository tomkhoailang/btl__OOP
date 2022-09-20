//#include<windows.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include "myDrawLib.h"
//#include <conio.h>
//#include <cmath>
//using namespace std;
//
//class Menu{
//	private:
//		int x, y;
//		string title;
//		vector<string> menuContent;
//		int numberOfMenuItem;
//		int padding;
//		int targetLength;
//	public:
//		Menu(int x, int y, vector<string> menuContent, string title);
//		~Menu(){};
//		void printMenu(const string& title, const string& textAlign, int padding);
//		void setPadding(int padding);
//		void setTargetLength(int length);
//		int GetItemAmount();
//		void resetMenu();
//		void start();
//};
//
//int main(){
//	vector<string> menuContent{
//							   "Nhap hang hoa",
//							   "Xuat hang hoa",
//							   "Cap nhat hang hoa",
//							   "Tim kiem hang hoa",
//							   "Xuat thong tin vao file",
//							   "Thoat"};
//	Menu menu(40, 2, menuContent, "QUAN LY CUA HANG");
//	menu.start();
//
//return 0;
//}
//
//Menu::Menu(int x, int y, vector<string> _menuContent, string title){
//	this->x = x;
//	this->y = y;
//	this->title = title;
//	this->menuContent = _menuContent;
//	this->numberOfMenuItem = _menuContent.size();
//}
//
//int Menu::GetItemAmount(){
//	return this->numberOfMenuItem;
//}
//
//void Menu::setPadding(int padding) {
//	this->padding = padding;
//}
//
//void Menu::setTargetLength(int length) {
//	this->targetLength = length;
//}
//
//void Menu::printMenu(const string& title, const string& textAlign, int padding) {
//	int yPos = this->y;
//	int xPos = this->x;
//	vector<string> _menuContent = this->menuContent;
//	this->setPadding(padding);
//	int size = this->GetItemAmount();
//	short titleLength = title.length() + 10;
//	short contentMaxLength;
//	
//	//find the longest menu content string
//	contentMaxLength = _menuContent[0].length();
//	
//	for(short i = 0; i < size; i++){
//		if(_menuContent[i].length() > contentMaxLength){
//			contentMaxLength = _menuContent[i].length();
//		}
//	}
//	short contentXPos = (xPos + round(titleLength / 2)) - round(contentMaxLength / 2) - (padding * 1.0 / 2);
//	this->setTargetLength(contentMaxLength);
//	//draw the title of menu
//	drawBox(xPos, yPos, titleLength, 2, 9, 15, title, "center");
//	
//	//draw the menu item
//	for(short i = 0; i < size; i++){
//		drawBox(contentXPos, 
//				yPos+=3, 
//				contentMaxLength + padding,
//				2, 
//				124, 
//				15, 
//				_menuContent[i], 
//				textAlign);
//	}
//}
//
//void Menu::resetMenu() {
//		cout << "\nNhan phim bat ki de tiep tuc..." << endl;
//		_getch();
//		system("cls");
//		ShowCur(0);
//		this->start();
//}
//
//void Menu::start() {
//	ShowCur(0);
//	string title = this->title;
//	int contentYPos = this->y + 3;
//	int lastPosY = this->y + 3;
//	int currentIndex = 0;
//	bool isPressed = true;
//	bool isUp = false;
//	this->printMenu(title, "center", 5);
//	
//	while(true){
//		
//		if(isPressed){
//			if(currentIndex > 0 && !isUp){
//				// Set the target element position x
//				currentTarget((this->x + round((title.length() + 10) / 2))
//								 - round(this->targetLength / 2) 
//								 - round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
//							  lastPosY, 
//						  	  this->targetLength + this->padding, 
//						  	  2, 
//						  	  0, 
//						  	  15, 
//						  	  this->menuContent[currentIndex - 1], 
//						  	  "center");
//			}else if(isUp){
//				currentTarget((this->x + round((title.length() + 10) / 2))
//							    - round(this->targetLength / 2) 
//								- round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
//							  lastPosY, 
//						  	  this->targetLength + this->padding, 
//						  	  2, 
//						  	  0, 
//						  	  15, 
//						  	  this->menuContent[currentIndex + 1], 
//						  	  "center");
//			}
//	
//			lastPosY = contentYPos;
//			currentTarget((this->x + round((title.length() + 10) / 2))
//							 - round(this->targetLength / 2) 
//							 - round(this->padding * 1.0 / 2) // set the target X postion to fit with the content box
//							 , 
//						  contentYPos, 
//						  this->targetLength + this->padding, 
//						  2, 
//						  200, 
//						  15, 
//						  this->menuContent[currentIndex], 
//						  "center");
//			isPressed = false;
//		}
//		
//		if(_kbhit()){
//			char c = _getch();
//			
//			if(c == -32){ // check if arrow key is pressed
//				c = _getch();
//				 
//				if(c == 72){
//					if(contentYPos != this->y + 3){
//						lastPosY = contentYPos;
//						isUp = true;
//						currentIndex--;
//						contentYPos-=3;	
//					}
//					isPressed = true;
//				}else if(c == 80){
//					if(contentYPos != this->y + 3 + (3 * (this->GetItemAmount() - 1))){
//						lastPosY = contentYPos;
//						isUp = false;
//						currentIndex++;
//						contentYPos+=3;		
//					}
//					isPressed = true;
//				}
//			}
//			if(c == 13){
//				int pointerX = 0;
//				int pointerY = this->y + 3 + 3 * this->GetItemAmount() + 2;
//				gotoXY(pointerX, pointerY);
//				textColor(0);
//				SetColor(91);
//
//				switch(currentIndex){
//					case 0:
//						cout << "Chuc nang 0";
//						this->resetMenu();
//						break;
//					case 1:
//						drawTable(0, pointerY, 26, 8, 10, 196, 1, "center");
//						this->resetMenu();
//						break;
//					case 2:
//						cout << "chuc nang 2";
//						this->resetMenu();
//						break;
//					case 3:
//						cout << "Chuc nang 3";
//						
//						this->resetMenu();
//						break;
//					case 4:
//						cout << "Chuc nang 4";
//						this->resetMenu();
//					case 5:
//						cout << "Ban da chon thoat chuong tring!!" << endl;
//						exit(1);
//						break;
//					default:
//						cout << "Loi" << endl;
//						break;
//				}
//			}
//		}
//	};
//}

