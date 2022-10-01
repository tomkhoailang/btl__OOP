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



//Menu methods

Menu::Menu(int x, int y, vector<string> _menuContent, string title){
	this->x = x;
	this->y = y;
	this->title = title;
	this->menuContent = _menuContent;
	this->numberOfMenuItem = _menuContent.size();
}

int Menu::GetItemAmount(){
	return this->numberOfMenuItem;
}

void Menu::setPadding(int padding) {
	this->padding = padding;
}

void Menu::setTargetLength(int length) {
	this->targetLength = length;
}

void Menu::printMenu(const string& title, const string& textAlign, int padding) {
	int yPos = this->y;
	int xPos = this->x;
	vector<string> _menuContent = this->menuContent;
	this->setPadding(padding);
	int size = this->GetItemAmount();
	short titleLength = title.length() + 10;
	short contentMaxLength;
	
	//find the longest menu content string
	contentMaxLength = _menuContent[0].length();
	
	for(short i = 0; i < size; i++){
		if(_menuContent[i].length() > contentMaxLength){
			contentMaxLength = _menuContent[i].length();
		}
	}
	short contentXPos = (xPos + round(titleLength / 2)) - round(contentMaxLength / 2) - (padding * 1.0 / 2);
	this->setTargetLength(contentMaxLength);
	//draw the title of menu
	drawBox(xPos, yPos, titleLength, 2, 9, 15, title, "center");
	
	//draw the menu item
	for(short i = 0; i < size; i++){
		drawBox(contentXPos, 
				yPos+=3, 
				contentMaxLength + padding,
				2, 
				260, 
				15, 
				_menuContent[i], 
				textAlign);
	}
}

void Menu::clearMenuScreen() {
		cout << "\n\nNhan phim bat ki de tiep tuc..." << endl;
		_getch();
		system("cls");
		ShowCur(0);
}

void Menu::start(ListGoods list) {
	ShowCur(0);
	int soLuong;
	string title = this->title;
	int contentYPos = this->y + 3;
	int lastPosY = this->y + 3;
	int currentIndex = 0;
	bool isUp = false;

	startPoint: ;
	
	this->printMenu(title, "center", 5);
	bool isPressed = true;
	while(true){
		
		if(isPressed){
			if(currentIndex > 0 && !isUp){
				// Set the target element position x
				currentTarget((this->x + round((title.length() + 10) / 2))
								 - round(this->targetLength / 2) 
								 - round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
							  lastPosY, 
						  	  this->targetLength + this->padding, 
						  	  2, 
						  	  0, 
						  	  15, 
						  	  this->menuContent[currentIndex - 1], 
						  	  "center");
			}else if(isUp){
				currentTarget((this->x + round((title.length() + 10) / 2))
							    - round(this->targetLength / 2) 
								- round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
							  lastPosY, 
						  	  this->targetLength + this->padding, 
						  	  2, 
						  	  0, 
						  	  15, 
						  	  this->menuContent[currentIndex + 1], 
						  	  "center");
			}
	
			lastPosY = contentYPos;
			currentTarget((this->x + round((title.length() + 10) / 2))
							 - round(this->targetLength / 2) 
							 - round(this->padding * 1.0 / 2) // set the target X postion to fit with the content box
							 , 
						  contentYPos, 
						  this->targetLength + this->padding, 
						  2, 
						  200, 
						  15, 
						  this->menuContent[currentIndex], 
						  "center");
			isPressed = false;
			
			textColor(0);
			ShowCur(0);
		}
		
		if(_kbhit()){
			char c = _getch();
			if(c == -32){ // check if arrow key is pressed
				c = _getch();
				 
				if(c == 72){
					if(contentYPos != this->y + 3){
						lastPosY = contentYPos;
						isUp = true;
						currentIndex--;
						contentYPos-=3;	
					}
					isPressed = true;
				}else if(c == 80){
					if(contentYPos != this->y + 3 + (3 * (this->GetItemAmount() - 1))){
						lastPosY = contentYPos;
						isUp = false;
						currentIndex++;
						contentYPos+=3;		
					}
					isPressed = true;
				}
			}
			if(c == 13){
				ShowCur(1);
				int pointerX = 0;
				int pointerY = this->y + 3 + 3 * this->GetItemAmount() + 2;
				gotoXY(pointerX, pointerY);
				textColor(0);
				SetColor(DEFAULT_TEXT_COLOR);

				switch(currentIndex){
					case 0:
						do {
							string checkNumber;
							stringstream ss;
							bool tempCheck;
							do {
								cout<<"Nhap so luong mat hang: ";
								tempCheck = validateNumber(checkNumber);
								if(tempCheck == false) {
									cout<<"Nhap sai dinh dang"<<endl;
								}
							}while(tempCheck == false);
							ss.clear();
							ss<<checkNumber;
							ss>>soLuong;
							if(soLuong <= 0) {
								cout<<"Nhap sai so luong. Vui long nhap lai!"<<endl;
							}
							}while(soLuong <= 0);
							for(int i = 0; i<soLuong; i++) {
								Goods a;
								do{
									a.input();
									id_List.push_back(a.getCode());
									if(!list.checkCode(a.getCode()))
									cout<<"\nMA ID "<<a.getCode()<<" DA TON TAI! VUI LONG NHAP LAI."<<endl;
								}while(!list.checkCode(a.getCode()));
								list.insertLast(a);
							}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 1:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							list.outputAsTable(0, pointerY, 21, 10, list.getSize(), 196, 1, "left");
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 2:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							list.Find_2();
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 3:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
                        list.Change(id_List);
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 4:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							writeDataToFile(list);
							loadingAnimation(68, pointerY+2, "Dang xuat du lieu ra file...", "->Xuat thanh cong");
						}
						this->clearMenuScreen();
						goto startPoint;
					case 5:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							cout << "Chuc nang 6" << endl;
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 6:
						cout << "Ban da chon thoat chuong trinh!!" << endl;
						exit(0);
						break;
					default:
						cout << "Khong co chuc nang nay, vui long them chuc nang vao case!!!" << endl;
						break;
				}
			}
		}
	};
}

