#include"menu.h"
//menu
Menu::Menu(int x, int y, string title){
	this->x = x;
	this->y = y;
	this->title = title;
}

Menu::~Menu(){
}

LoginMenu::LoginMenu(int x, int y, string title): Menu(x, y, title){
	this->role = "employee";
}

LoginMenu::~LoginMenu(){
}

string LoginMenu::getRole(){
	return this->role;
}

void LoginMenu::setRole(string role){
	this->role = role;
}

string LoginMenu::getUsername(){
	return this->username;
}

void LoginMenu::printLoginMenu() {
	short xPos = this->Menu::x;
	short yPos = this->Menu::y;
	string title = this->Menu::title;
	
	drawBox(xPos, yPos, 34, 2, 9, 15, title, "center");
	drawBox(xPos, yPos + 3, 34, 9, 260, 15, "", "left");
}

bool LoginMenu::startLoginMenu(){
	short xPos = this->Menu::x;
	short yPos = this->Menu::y;
	string enteredUsername, enteredPassword;
	string Mpassword, Musername, Epassword, Eusername;
	short labelCol = 190;
	short textCol = 15;
	bool isCorrect = false;
	bool isManager = false;
	
	do{
		this->printLoginMenu();

		gotoXY(xPos+2, yPos+ 4);
		SetColor(labelCol);
		cout << "Nhap ten dang nhap:";
		SetColor(260);
		cout << "-------------" << endl;
		gotoXY(xPos+1, yPos+ 6);
		cout << "---------------------------------" << endl;
		
		gotoXY(xPos+2, yPos+ 8);
		SetColor(labelCol);
		fflush(stdin);
		cout << "Nhap mat khau:";
		SetColor(260);
		cout << "------------------" << endl;
		gotoXY(xPos+1, yPos+ 10);
		cout << "---------------------------------" << endl;
		
		gotoXY(xPos+2, yPos+ 5);
		SetColor(textCol);
		fflush(stdin);
		getline(cin, enteredUsername);
		checkUser(enteredUsername);
		
		gotoXY(xPos+2, yPos+ 9);
		SetColor(textCol);
		char ch;
		ch = _getch();
		while((ch >= 65 && ch <= 90) || (ch>= 97 && ch <= 122) || ch == 32 || ch >=48 && ch<= 57|| ch>=33 && ch<=47 || ch == '\b') {
			if(ch == '\b' ) {
				if(enteredPassword.length() > 0) {
					enteredPassword.pop_back();
					cout<<"\b \b";
				}   
				ch = _getch();
			}else {
				enteredPassword.push_back(ch);
				cout<<'*';
				ch = _getch();
			}
		
		}
		
		ifstream accInput(MANAGER_FILE_PATH);
		while(accInput >> Musername){
			accInput.ignore();
			accInput >> Mpassword;
			if(enteredUsername.compare(Musername) == 0 && enteredPassword.compare(Mpassword) == 0){
				isCorrect = true;
				gotoXY(xPos - 4, yPos+ 13);
				SetColor(290);
				cout << "Dang nhap thanh cong voi tu cach la manager!!" << endl;
				this->role = "manager";
				sleepFunc(1);
				accInput.close();
				break;
			}
		}
		user_Name.push_back(Musername);
		
		ifstream emAccInput(EMPLOYEE_ACCOUNTS_FILE_PATH);
		while(emAccInput >> Eusername){
			emAccInput.ignore();
			emAccInput >> Epassword;
			
			if(enteredUsername.compare(Eusername) == 0 && enteredPassword.compare(Epassword) == 0){
				isCorrect = true;
				gotoXY(xPos - 4, yPos+ 13);
				SetColor(290);
				cout << "Dang nhap thanh cong voi tu cach la nhan vien!!" << endl;
				this->role = "employee";
				this->username = Eusername;
				sleepFunc(1);
				emAccInput.close();
				break;
			}
		}
		
		if(!isCorrect){
			gotoXY(xPos - 8, yPos+ 13);
			SetColor(260);
			enteredPassword = "";
			cout << "Sai ten dang nhap hoac mat khau!! (Nhan Enter de tiep tuc)" << endl;
			_getch();
			accInput.close();
			emAccInput.close();
			system("cls");
		}
	}while(!isCorrect);
	
	ShowCur(0);
	return isCorrect;
}

ListMenu::ListMenu(int x, int y, vector<string> _menuContent, string title): Menu(x, y, title){
	this->menuContent = _menuContent;
	this->numberOfMenuItem = _menuContent.size();
}

int ListMenu::GetItemAmount(){
	return this->numberOfMenuItem;
}

void ListMenu::setPadding(int padding) {
	this->padding = padding;
}

void ListMenu::setTargetLength(int length) {
	this->targetLength = length;
}

void ListMenu::printMenu(const string& title, const string& textAlign, int padding) {
	int yPos = this->y;
	int xPos = this->x;
	vector<string> _menuContent = this->menuContent;
	this->setPadding(padding);
	int size = this->GetItemAmount();
	short titleLength = title.length() + 10;
	short contentMaxLength;
	
	//find the longest ListMenu content string
	contentMaxLength = _menuContent[0].length();
	
	for(short i = 0; i < size; i++){
		if(_menuContent[i].length() > contentMaxLength){
			contentMaxLength = _menuContent[i].length();
		}
	}
	short contentXPos = (xPos + round(titleLength / 2)) - round(contentMaxLength / 2) - (padding * 1.0 / 2);
	this->setTargetLength(contentMaxLength);
	//draw the title of ListMenu
	drawBox(xPos, yPos, titleLength, 2, 9, 15, title, "center");
	
	//draw the ListMenu item
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

void ListMenu::clearMenuScreen() {
		cout << "\n\nNhan phim bat ki de tiep tuc..." << endl;
		_getch();
		system("cls");
		ShowCur(0);
}

void ListMenu::start(ListGoods &list, string role, Manager &managerList, string info) {
	ShowCur(0);
	int soLuong;
	string title = this->title;
	int contentYPos = this->y + 3;
	int lastPosY = this->y + 3;
	int currentIndex = 0;
	bool isUp = false;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
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
							if(soLuong < 0) {
								cout<<"Nhap sai so luong. Vui long nhap lai!"<<endl;
							}else if(soLuong == 0) {
								cout<<"Da thoat khoi chuc nang!"<<endl;
							}
							}while(soLuong < 0);
							for(int i = 0; i<soLuong; i++) {
								Goods a;
								//Xoa bo check id trung khi nhap de tranh viec them vao bi bao loi
//								do{
									a.input();
									//Them ham chinh sua so luong de cap nhat lai so luong moi them
									list.Add();
//									id_List.push_back(a.getCode());
//									if(!list.checkCode(a.getCode()))
//									cout<<"\nMA ID "<<a.getCode()<<" DA TON TAI! VUI LONG NHAP LAI."<<endl;
//								}while(!list.checkCode(a.getCode()));
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
                        	list.Change();
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
						if(role.compare("manager") == 0){
							short choice;
							cout << "1. Them nhan vien" << endl;
							cout << "2. Xuat nhan vien" << endl;
							cout << "3. Cap nhat thong tin nhan vien" << endl;
							cout << "4. Tim kiem" << endl;
							cout << "5. Xu ly hoa don" << endl;
							cout << "0. Thoat" << endl;
						
							do {
								cout << "Nhap lua chon: ";
								tempCheck = validateNumber(checkNumber);
								if(tempCheck == false) {
									cout<<"Nhap sai dinh dang"<<endl;
								}
							}while(tempCheck == false);
							ss.clear();
							ss<<checkNumber;
							ss>>choice;
							
							switch(choice){
								case 1:
									short amount, type;
									startChossing: ;
									cout << "Chon loai nhan vien: " << endl;
									cout << "1. Nhan vien chinh thuc" << endl;
									cout << "2. Thu viec" << endl;
									cout << "0. Thoat "<<endl;
									do {
										cout << "Nhap lua chon: ";
										tempCheck = validateNumber(checkNumber);
										if(tempCheck == false) {
											cout<<"Nhap sai dinh dang"<<endl;
										}
									}while(tempCheck == false);
									ss.clear();
									ss<<checkNumber;
									ss>>type;
									if(type == 0) {
										cout<<"Da thoat khoi chuc nang"<<endl;
										break;
									}else if(type < 1 || type > 2) {
										cout<<"Lua chon khong ton tai!"<<endl;
										break;
									}else {
										do {
											cout << "\nNhap so luong nhan vien muon them: ";
											tempCheck = validateNumber(checkNumber);
											if(tempCheck == false) {
												cout<<"Nhap sai dinh dang"<<endl;
											}
										}while(tempCheck == false);
										ss.clear();
										ss<<checkNumber;
										ss>>amount;
										if(amount == 0){
											cout<<"Loi chuc nang"<<endl;
											break;
										}
										if(type == 1){
											for(short i = 0;i < amount;i++){
												managerList.insertLast_2();
											}
										}
										else if(type == 2){	
											for(short i = 0;i < amount;i++){
												managerList.insertLast_1();
											}
										}else{
											cout << "Khong co lua chon nay!" << endl;
											goto startChossing;
										}
										writeManagerDataToFile(managerList);
										cout << "Da them thanh cong" << endl;
										break;
									}
								case 2:
									short outType;
									startOutChossing: ;
									cout << "1. Xuat danh sach nhan vien" << endl;
									cout << "2. Xuat danh sach tai khoan" << endl;
									do {
										cout << "Nhap lua chon: ";
										tempCheck = validateNumber(checkNumber);
										if(tempCheck == false) {
											cout<<"Nhap sai dinh dang"<<endl;
										}
									}while(tempCheck == false);
									ss.clear();
									ss<<checkNumber;
									ss>>outType;
									if(outType == 1){
										if(managerList.isEmpty_1() && managerList.isEmpty_2()){
											cout<<"Danh sach trong!"<<endl;
										}
										else{
											output_title_2();
											managerList.output_2();
											managerList.output_1();
										}
									}else if(outType == 2){
										if(managerList.isEmpty_2()){
											cout<<"Danh sach trong!"<<endl;
										}
										else{
											output_title_3();
											managerList.output_User();
										}
									}else{
										cout << "Khong co lua chon nay!" << endl;
										goto startOutChossing;
									}
									break;
								case 3:
									short n;
									do{
										cout<<"1. Nhan vien thu viec\n";
										cout<<"2. Nhan vien chinh thuc\n";
										cout<<"0. Thoat\n";
										do {
											cout << "Nhap lua chon: ";
											tempCheck = validateNumber(checkNumber);
											if(tempCheck == false) {
												cout<<"Nhap sai dinh dang"<<endl;
											}
										}while(tempCheck == false);
										ss.clear();
										ss<<checkNumber;
										ss>>n;
										if(n<0||n>2)
											cout<<"Khong co lua chon nay\n";
									}while(n<0||n>2);
									switch(n){
										case 0:
											break;
										case 1:
											managerList.ChangeTempEmployee();
											break;
										case 2:
											managerList.ChangeEmployee();
											break;
									}
									writeManagerDataToFile(managerList);
									break;
								case 4:
									short x;
									do{
										cout<<"1. Nhan vien thu viec\n";
										cout<<"2. Nhan vien chinh thuc\n";
										cout<<"0. Thoat\n";
										do {
											cout << "Nhap lua chon: ";
											tempCheck = validateNumber(checkNumber);
											if(tempCheck == false) {
												cout<<"Nhap sai dinh dang"<<endl;
											}
										}while(tempCheck == false);
										ss.clear();
										ss<<checkNumber;
										ss>>x;
										if(x<0||x>2)
											cout<<"Khong co lua chon nay\n";
									}while(x<0||x>2);
									switch(x){
										case 0:
											break;
										case 1:
											managerList.FindTempEmployee();
											break;
										case 2:
											managerList.FindEmployee();
											break;
									}
									break;
								case 5:
									managerList.calculation(list);
									break;	
								case 0:
									break;
								default:
									cout << "Lua chon khong hop le" << endl;
							}
						}else{
							Employee a = managerList.getEmployeeByUserName(info);
							short choice;
							cout << "1. Thong tin nhan vien" << endl;
							cout << "2. Xu ly hoa don" << endl;
							cout << "0. Thoat" << endl;
							do {
								cout << "Nhap lua chon: ";
								tempCheck = validateNumber(checkNumber);
								if(tempCheck == false) {
									cout<<"Nhap sai dinh dang"<<endl;
								}
							}while(tempCheck == false);
							ss.clear();
							ss<<checkNumber;
							ss>>choice;
							switch(choice){
								case 1:
									output_title_2();
									a.output();
									break;
								case 2:
									a.calculation(list);
									break;
								case 0:
									break;
								default:
									cout << "Lua chon khong hop le!" << endl;
							}
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

