<<<<<<< HEAD
#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>
#include<vector>
#include"myDrawLib.h"
#include<conio.h>
#include<cmath>
#include<fstream>
#include<vector>
#include <sstream>
#define _WIN32_WINNT  0x0500
using namespace std;
vector<string> id_List;

#define DEFAULT_TEXT_COLOR 91
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
// ngay thang nam
typedef struct Date {
//	private:
		int dd;
		int mm;
		int yyyy;
//	public:
		Date();
		Date(int dd, int mm, int yyyy);
		void setDate(const Date &a);
		~Date();
		void setDay(int dd);
		int getDay();
		void setMonth(int mm);
		int getMonth();
		void setYear(int yyyy);
		int getYear();
		bool checkDate();
		void inputDate();
		void outputDate();
		bool checkExpiryDate();
		friend class Goods;
} Date;
//Lop hang hoa
class Goods {
	private:
		string name;		//ten hang hoa
		string code;		//ma hang hoa
		string category;	//danh muc
		string status;		//tinh trang
		float discount;		//chiet khau
		float price;		//gia goc
		float priceAfter;	//gia sau khi tru chiet khau
		int number;			//so luong
		Date date;			//ngay san xuat
		int valid;			//han su dung
		Date expiryDate;	//ngay het han
		
	public:
		//friend classes and functions
		friend class ListGoods;
		//Constructor
		Goods();
		Goods(string name, string code, int number, Date date, int valid, string status);
		//getter and setter
		string getName();
		void setName(string name);
		string getCategory();
		void setCategory(string category);
		string getCode();
		void setCode(string code);
		float getDiscount();
		void setDiscount(float discount);
		float getPrice();
		void setPrice(float price);
		float getPriceAfter();
		void setPriceAfter(float priceAfter);
		int getNumber();
		void setNumber(int number);
		int getvalid();
		void setvalid(int valid);
		string getStatus();
		void setStatus();
		void setStatusWithData(string status);
		Date getDate();
		void setDate(Date _data);
		Date getExpiryDate();
		void setExpiryDate(Date _data);
		//phuong thuc
		Date updateExpiryDate();
		void input();
		void output(int series);
		friend void outputTitle();
		friend string upperCase(string a);
		friend void changeString(char a[], string b);
		~Goods();
		int Replace(vector<string> &id_List);
};
//Node hang hoa
class Node {
	public:
	Goods data;
	Node *next;
	//Node();
};
// Danh sach hang hoa
class ListGoods {
	private: 
		int size;
		Node *head;
		Node *tail;
	public:
		ListGoods();
		int getSize();
		Node *makeNode();
		Node *makeNode(Goods data);
		bool isEmpty();
		void output();
		void outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign);
		void insertLast();
		void insertLast(Goods data);
		bool checkCode(string code);
		~ListGoods();
		void Find_2();
		Node* Find_1();
		friend void writeDataToFile(ListGoods list);
		friend void readDataFromFile(ListGoods &list);
		void Change(vector<string> id_List);
};

//class menu
class Menu{
	private:
		int x, y;
		string title;
		vector<string> menuContent;
		int numberOfMenuItem;
		int padding;
		int targetLength;
	public:
		Menu(int x, int y, vector<string> _menuContent, string title);
		~Menu(){};
		void printMenu(const string& title, const string& textAlign, int padding);
		void setPadding(int padding);
		void setTargetLength(int length);
		int GetItemAmount();
		void clearMenuScreen();
		void start(ListGoods list);
};

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
	menu.start(list);
	_getch();
	return 0;
}
bool validateNumber(string &toCheck) {
	bool correct = false;
	fflush(stdin);
	getline(cin, toCheck);
	for (int i = 0; i<toCheck.length(); i++) {
		if ((toCheck[i] >= 65 && toCheck[i] <= 90) || (toCheck[i] >= 97 && toCheck[i] <= 122) || toCheck[i] == 32 ) {
			return false;
		}else if (toCheck[i] >=48 && toCheck[i]<= 57) {
			correct = true;
		}else {
			return false;
		}
	}
	return correct;
}
bool validateString(string toCheck) {

	bool correct = false;
		
	for (int i = 0; i<toCheck.length(); i++) {
		
		if ((toCheck[i] >= 65 && toCheck[i] <= 90) || (toCheck[i] >= 97 && toCheck[i] <= 122) || toCheck[i] == 32 || toCheck[i] >=48 && toCheck[i]<= 57) {
		    correct = true;
		}
		else {
		    return false;
		}
	}
	return correct;
}

int ListGoods::getSize(){
	return size;
}

void ListGoods::outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign) {
	if(columns == 0 || rows == 0 || w == 0) return;
	int xStep = x;
	int _x = x;
	int _y = y;
	SetScreenBufferSize(500, 500);
	SetWindowSize(300, 300);
	vector<string> title{"ID", "Name", "Category", "Amount", "Price", "Discount", "Total", "NSX", "HSD", "Status"};
	vector<Goods> content;

	for(Node *i = this->head;i != NULL; i=i->next){
		content.push_back(i->data);
	}// copy the linked list into vector list
	
	for(short k = 0; k < title.size(); k++){
		drawBox(_x + (k*w), y, w, 2, titleColor, 11, title[k] ,"center");
		if(k > 0){
			SetColor(titleColor);
			gotoXY(x + (w * k), y + 2);
			cout << char(193);
			gotoXY(x + (w * k), y);
			cout << char(194);
		}
	}
	_y+=3;
	
	for(short i = 0; i < rows; i++){
			drawBox(xStep, _y, w, 2, color, 250, content[i].code, contentAlign);
			xStep+=w;	
			drawBox(xStep, _y, w, 2, color, 250, content[i].name, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].category, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)content[i].number), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)content[i].price) + " vnd", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)round(content[i].discount)) + " %", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)round(content[i].priceAfter)) + " vnd", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].date.getDay()) + "/" + to_string(content[i].date.getMonth()) + "/" + to_string(content[i].date.getYear()), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].expiryDate.getDay()) + "/" + to_string(content[i].expiryDate.getMonth()) + "/" + to_string(content[i].expiryDate.getYear()), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].status, contentAlign);
		for(short j = 0; j < title.size(); j++){
			if(i >= 1){
				SetColor(color);
				gotoXY(x, _y);
				cout << char(195);
				gotoXY(_x, _y);
				cout << char(197);
				gotoXY(x + w * (title.size()), _y);
				cout << char(180);
				if(j >= 1){
					gotoXY(_x,(y + 3) + 2 * rows);
					cout << char(193);
				}
			}else if(i < 1 && j >= 1){
				SetColor(color);
				gotoXY(_x, y + 3);
				cout << char(194);
			}
			_x+=w;
		}	
		_y+=2;
		_x = x;
		xStep = x;
	}
	gotoXY(0, (y+3) + 2 * rows + 2);
	SetColor(DEFAULT_TEXT_COLOR);
	ShowCur(0);
}

//Constructor va huy cua Date
Date::Date() {
	this->dd = 1;
	this->mm = 1;
	this->yyyy = 2001;
}
Date::Date(int dd, int mm, int yyyy) {
	this->dd = dd;
	this->mm = mm;
	this->yyyy = yyyy;
}
void Date::setDate(const Date &a){
	this->dd = a.dd;
	this->mm = a.mm;
	this->yyyy = a.yyyy;
}
Date::~Date() {
}
// Getter va setter cho Date
Date Goods::getDate(){
	return this->date;
}
void Goods::setDate(Date _data){
	this->date.setDate(_data);
}
Date Goods::getExpiryDate(){
	return this->expiryDate;
}
void Goods::setExpiryDate(Date _data){
	this->expiryDate.setDate(_data);
}

void Date::setDay(int dd) {
	this->dd = dd;
}
int Date::getDay() {
	return dd;
}
void Date::setMonth(int mm) {
	this->mm = mm;
}
int Date::getMonth() {
	return mm;
}
void Date::setYear(int yyyy) {
	this->yyyy = yyyy;
}
int Date::getYear() {
	return yyyy;
}
// Kiem tra ngay
bool Date::checkDate() {
	int maxDay;
	    if (yyyy<=0 || mm<=0 || mm> 12 || dd<=0 || dd> 31)
    {
        return false;
    }
    else
    {
        switch (mm)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((yyyy%4==0 && yyyy%100!=0) || (yyyy%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (dd<=maxDay)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// Nhap ngay
void Date::inputDate() {
	bool temp;
	bool tempCheck;
	string ddTemp,mmTemp,yyyyTemp;
	stringstream ss;
	do {
		cout<<"Nhap ngay san xuat: "<<endl;
		cout<<"Ngay ";
		do {
			tempCheck = validateNumber(ddTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<ddTemp;
		ss>>dd;
		do {
			cout<<"Thang ";
			tempCheck = validateNumber(mmTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<mmTemp;
		ss>>mm;
		cout<<"Nam ";
		do {
			tempCheck = validateNumber(yyyyTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang!"<<endl;
			}
		}while(tempCheck == false );
		ss.clear();
		ss<<yyyyTemp;
		int yyyyTemp2;
		ss>>yyyyTemp2;
		if(yyyyTemp2 > 2000) {
			yyyy = yyyyTemp2;
			temp = checkDate();
			if(temp != true) {
				cout<<"Ngay san xuat phai dung dinh dang"<<endl;
			}
			else if(checkExpiryDate()){
			cout<<"Ngay san xuat khong duoc lon hon ngay hien tai!"<<endl;
			}
		}else {
			cout<<"Nam san xuat phai lon hon 2000"<<endl;
		}
	}while(yyyy <= 2000 ||  temp == false || checkExpiryDate());
}
//Xuat ngay
void Date::outputDate() {
	bool temp = checkDate();
	if(temp == false || yyyy <= 2000) {
		cout<<"Sai dinh dang, se thiet lap thanh ngay mac dinh!"<<endl;
		this->dd = 1;
		this->mm = 1;
		this->yyyy = 2001;
	}
	if(dd >= 10) {
		cout<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	} else {
		cout<<"0"<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	}
}
//so sanh ngay vua nhap voi ngay hien tai
bool Date::checkExpiryDate(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	if (yyyy < yearNow)
	{
		return false;
	}
	else if (yyyy == yearNow)
	{
		if (mm < monNow)
		{
			return false;
		}
		else if (mm == monNow)
		{
			if (dd < dayNow)
			{
				return false;
			}
		}
	}
	return true;
}

//getter and setter
string Goods::getName() {
	return name;
}
void Goods::setName(string name) {
	this->name = name;
}
string Goods::getCode() {
	return code;
}
void Goods::setCode(string code) {
	this->code = code;
}
int Goods::getNumber() {
	return number;
}
void Goods::setNumber(int number) {
	this->number = number;
}
string Goods::getCategory(){
	return category;
}
void Goods::setCategory(string category){
	this->category = category;
}
float Goods::getDiscount(){
	return discount;
}
void Goods::setDiscount(float discount){
	this->discount = discount;
}
float Goods::getPrice(){
	return price;
}
void Goods::setPrice(float price){
	this->price = price;
}
float Goods::getPriceAfter(){
	return priceAfter;
}
void Goods::setPriceAfter(float priceAfter){
	this->priceAfter = priceAfter;
}
int Goods::getvalid() {
	return valid;
}
void Goods::setvalid(int valid) {
	this->valid = valid;
}
string Goods::getStatus(){
	return status;
}
void Goods::setStatus(){
	if(expiryDate.checkExpiryDate()){
		this->status = "CON HAN";
	}
	else this->status = "HET HAN";
}
void Goods::setStatusWithData(string status){
	this->status = status;
}
//khoi tao
Goods::Goods() {
	this->name = "";
	this->code = "";
	this->number = 0;
	this->valid = 3;
}
Goods::Goods(string name, string code, int number, Date date, int valid, string status) {
	this->name = name;
	this->code = code;
	this->number = number;
	this->date = date;
	this->valid = valid;
	this->status = status;
}
//cap nhat ngay het han
Date Goods::updateExpiryDate(){
	Date update(date.getDay(), date.getMonth(),date.getYear());
	int copyValid = valid;
	int maxDay;
	update.setYear(update.getYear() + (copyValid / 12));
	update.setMonth(update.getMonth() + (copyValid % 12));
	while(update.checkDate() == false){
		if(update.getMonth() > 12){
		update.setYear(update.getYear() + 1);
		update.setMonth(update.getMonth()-12);
	}
	switch (update.getMonth())
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((update.getYear()%4==0 && update.getYear()%100!=0) || (update.getYear()%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (update.getDay()>maxDay)
        {
            update.setMonth(update.getMonth()  + 1);
            update.setDay(update.getDay() - maxDay);
        }
	}
	return update;
}
//in hoa chuoi
string upperCase(string a){
	for(int i=0; i<a.length(); ++i){
		if(a[i]>='a'&&a[i]<='z')
		a[i]-=32;
	}
	return a;
}
void changeString(char a[], string b){
			for(int i=0;i<b.length();++i){
				a[i] = b[i];
			}
		}
//Nhap thong tin hang hoa
void Goods::input(){
	bool tempCheck;
	string nameTemp, codeTemp, categoryTemp;
	stringstream ss;
	string priceTemp, discountTemp, numberTemp, validTemp;
	int numberTemp2,validTemp2;
	float priceTemp2, discountTemp2;
	cout<<"Nhap thong tin san pham"<<endl;
	cout<<"Nhap ID: ";
	do {
		fflush(stdin);
		getline(cin, codeTemp);
		
		if(validateString(codeTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(codeTemp) == false);
	codeTemp = upperCase(codeTemp);
	cout<<codeTemp<<endl;
	setCode(codeTemp);
	cout<<"Nhap ten: ";
	do {
		fflush(stdin);
		getline(cin, nameTemp);
		
		if(validateString(nameTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(nameTemp) == false);
	nameTemp = upperCase(nameTemp);
	setName(nameTemp);
	do {
		cout<<"Nhap danh muc: ";
		fflush(stdin);
		getline(cin, categoryTemp);
		
		if(validateString(categoryTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(categoryTemp) == false);
	categoryTemp = upperCase(categoryTemp);
	setCategory(categoryTemp);
	do {
		cout<<"Nhap so luong: ";
		tempCheck = validateNumber(numberTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<numberTemp;
	ss>>numberTemp2;
	setNumber(numberTemp2);
	do {
		cout<<"Nhap gia: ";
		tempCheck = validateNumber(priceTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<priceTemp;
	ss>>priceTemp2;
	setPrice(priceTemp2);
	
	do {
		cout<<"Nhap chiet khau: ";
		tempCheck = validateNumber(discountTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<discountTemp;
	ss>>discountTemp2;
	setDiscount(discountTemp2);
	setPriceAfter(getPrice()*(100-getDiscount())/100);
	date.inputDate();
	do {
		cout<<"Nhap han su dung(tu 1 thang tro len): ";
		tempCheck = validateNumber(validTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<validTemp;
	ss>>validTemp2;
	valid = validTemp2;
	expiryDate.setDate(updateExpiryDate());
	setStatus();
}
//xuat thong tin hang hoa
void Goods::output(int series){
	cout << "|" << 	setw(3) << left << series 		<< "|";
	cout << 		setw(4) << left << getCode() 		<< "|";
	cout <<			setw(15) << left << getName() 		<< "|";
	cout << 		setw(15) << left << getCategory() 	<< "|";
	cout << 		setw(6) << right << getNumber() 	<< "|";
	cout << 		setw(7) << right << getPrice() 		<< "|";
	cout << 		setw(8) << right << getDiscount() 	<< "|";
	cout << 		setw(7) << right << getPriceAfter() 		<< "|";
	date.outputDate();
	cout<<"|";
	expiryDate.outputDate();
	cout<<"|";
	cout << 		setw(7) << left << getStatus() 	<< "|"<<endl;;
}
void outputTitle(){
	cout << "|" << 	setw(3) << left << "STT" 		<< "|";
	cout << 		setw(4) << left << "ID" 		<< "|";
	cout <<			setw(15) << left << "Name" 		<< "|";
	cout << 		setw(15) << left << "Category" 	<< "|";
	cout << 		setw(6) << left << "Amount" 	<< "|";
	cout << 		setw(7) << left << "Price" 		<< "|";
	cout << 		setw(8) << left << "Discount" 	<< "|";
	cout << 		setw(7) << left << "Total" 		<< "|";
	cout << 		setw(10) << left << "NSX" 		<< "|";
	cout << 		setw(10) << left << "HSD" 		<< "|";
	cout << 		setw(7) << left << "Status" 	<< "|"<<endl;;
}

//ham huy
Goods::~Goods() {
}

//Constructor khoi tao gia tri 
ListGoods::ListGoods() {
	head = NULL;
	tail = NULL;
	this->size = 0;
}
//Ham huy
ListGoods::~ListGoods() {
}
//Tao ra Node moi
Node *ListGoods::makeNode() {
	Node *temp = new Node();
	temp->data.input();
	temp->next = NULL;
	return temp;
}
// Tao ra Node moi nhung co san gia tri
Node *ListGoods::makeNode(Goods data) {
	Node *temp = new Node();
	temp->data.setName(data.getName());
	temp->data.setCode(data.getCode());
	temp->data.setCategory(data.getCategory());
	temp->data.setNumber(data.getNumber());
	temp->data.setPrice(data.getPrice());
	temp->data.setDiscount(data.getDiscount());
	temp->data.setPriceAfter(data.getPriceAfter());
	Date tempDate(data.date.getDay(),data.date.getMonth(),data.date.getYear());
	temp->data.date = tempDate;
	temp->data.setvalid(data.getvalid());
	temp->data.expiryDate.setDate(data.updateExpiryDate());
	temp->data.setStatus();
	temp->next = NULL;
	return temp;
}

//Kiem tra danh sach rong
bool ListGoods::isEmpty() {
	if(head == NULL) {
		return true;
	}else {
		return false;
	}
}
//In ra danh sach hien tai
void ListGoods::output() {
	Node *temp = head;
	outputTitle();
	int series = 1;
	while(temp != NULL) {
		temp->data.output(series);
		series++;
		temp = temp->next;
	}
}
//Nhap them hang vao cuoi danh sach
void ListGoods::insertLast() {
	Node *temp = makeNode();
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//Nhap them hang vao cuoi danh sach nhung co data
void ListGoods::insertLast(Goods data) {
	Node *temp = makeNode(data);
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//kiem tra trung id
bool ListGoods::checkCode(string code){
	for(Node *i = head; i != NULL; i = i->next){
		if(i->data.getCode() == code)
		return false;
	} 
	return true;
}	
// Chuc nang tim kiem
void ListGoods::Find_2(){
	int select,dem=0;
	string selectTemp;
	char temp_1[100],temp_2[100];
	string _temp_1, _temp_2;
	stringstream ss;
	bool tempCheck;
	do{
	cout<<"Lua chon thong tin tim kiem\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Danh muc\n";
	cout<<"3.Tinh trang\n";
	cout<<"0.Thoat\n";
		do {
			cout<<"Nhap lua chon: ";
			tempCheck = validateNumber(selectTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<selectTemp;
		ss>>select;
		switch(select){
		case 0: {
			break;
		}
		case 1:
			{
				do {
					cout<<"Nhap ten: ";
					fflush(stdin);
					getline(cin,_temp_1);
					changeString(temp_1,upperCase(_temp_1));
					if(validateString(temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp_1) == false);
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){	
                    if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				}
				break;
			}       
		case 2:
				{
				do {
					cout<<"Nhap danh muc: ";
					fflush(stdin);
					getline(cin,_temp_1);
					changeString(temp_1,upperCase(_temp_1));
					if(validateString(temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp_1) == false);
				
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){
				    if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				    }
				break;
				}
		case 3:
					{
						cout<<"Nhap tinh trang: ";
				        fflush(stdin);
				        getline(cin,_temp_1);
					changeString(temp_1,upperCase(_temp_1));
				        outputTitle();
				        for(Node* i=head;i!=NULL;i=i->next){
				            if( strstr( strupr(strcpy(temp_2, i->data.status.c_str())),strupr(temp_1) ) ){
				                dem++;
				                i->data.output(dem);
				            }
				    }
				    break;
					}
		default: 
			cout<<"Lua chon khong ton tai!"<<endl;
			
	}
}while(select!=0);
	
}
//Chuc nang sua
Node* ListGoods:: Find_1(){
	Node* p=new Node;
	char temp_1[100],temp_2[100];
	string _temp_1;
	int dem_1 =0,dem_2=0;
    do {
		cout<<"Nhap ma san pham: ";
		fflush(stdin);
		getline(cin,_temp_1);
		changeString(temp_1,upperCase(_temp_1));
		if(validateString(temp_1) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(temp_1) == false);
		for(Node* i=head;i!=NULL;i=i->next){
			dem_1++;
			if( strstr( strupr(strcpy(temp_2, i->data.code.c_str())),strupr(temp_1) ) ){
			dem_2++;
			outputTitle();
			i->data.output(dem_1);
			return i;
					}	
				}
				    if(dem_2==0)
				        cout<<"Ma san pham khong co trong danh sach\n";
				    return p;
			}
void ListGoods:: Change(vector<string> id_List){
	int option,check,dem_1=0,dem_2=0;
	string checkNumber;
	stringstream ss;
	do{
	cout<<"\n\nVui long chon phuong thuc ma ban muon thay doi\n";
	cout<<"1.Sua lai thong tin san pham\n";
	cout<<"2.Xoa san pham\n";
	cout<<"0.Thoat\n";
	do{
		bool tempCheck;
		do {
			cout<<"Vui long nhap lua chon: ";
			tempCheck = validateNumber(checkNumber);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<checkNumber;
		ss>>option;
		if(option<0||option>2)
		    cout<<"Nhap lai!\n";
	}while(option<0||option>2);
	switch(option){
		case 0:
			break;
		case 1:
			{
        for(Node* i=head;i!=NULL;i=i->next){
        	dem_2++;
        	if(i==Find_1()){
        		check=i->data.Replace(id_List);
        		dem_1++;
        		if(check==1){
        		cout<<"Ket qua sau khi sua la:\n";
        		outputTitle();
        		i->data.output(dem_2);
        		break;
        	}
        	else	
				break;
			}
		}
		if(dem_1==0)
		    cout<<"Khong tim thay du lieu tu thong tin ma ban nhap vao\n";
		break;
	}
    case 2: {
		for(Node* i=head;i!=NULL;i=i->next){
			dem_2++;
			if(i=Find_1()){
				cout<<"Chon 1 de tiep tuc\n";
				cout<<"Chon 0 de thoat\n";
				do{
					bool tempCheck;
					do {
						cout<<"Vui long nhap lua chon:";
						tempCheck = validateNumber(checkNumber);
						if(tempCheck == false) {
							cout<<"Nhap sai dinh dang"<<endl;
						}
					}while(tempCheck == false);
					ss.clear();
					ss<<checkNumber;
					ss>>check;
					
				}while(check<0||check>1);
				if(check==0)
				    break;
				else{
				if(i=head){
	        	head=head->next;
	        	delete i;
	        	dem_1++;
            	}
            	else if(i=tail){
	        	Node* q=head;
		        while(q->next->next!=NULL){
			        q=q->next;
		        }
	        	tail=q;
		        q->next=NULL;
		        delete i;
		        dem_1++;
             	}
	            else{ 
//	            	for(Node* p=head;p->next==i;p=p->next){
//	            	    p->next=p->next->next;
//						dem_1++;	
//					}
                    Node* p=head;
                    while(p->next==i){
                    	p->next=p->next->next;
                    	delete i;
                    	dem_1++;
					}	
	            }	
		        cout<<"Danh sach sau khi xoa la:\n";
		     	output ();
        	    
		if(dem_1==0)
		    cout<<"Phan tu can xoa khong co trong danh sach\n";
		break;
	        }   
		    }
	    }
	    break;
   	}
	default:
		cout<<"Lua chon khong ton tai!"<<endl;  
   }
}while(option!=0);
}
int Goods::Replace(vector<string> &id_List){
	int option;
	cout<<"\nVui long lua chon phan thong tin can sua\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Ma san pham\n";
	cout<<"3.Danh muc \n";
	cout<<"4.Gia chiet khau\n";
	cout<<"5.Gia goc \n";
	cout<<"6.So luong san pham\n";
	cout<<"7.Ngay san xuat \n";
	cout<<"8.Han su dung \n";
	cout<<"0.Thoat\n";
	string checkOption;
	stringstream ss;
	bool tempCheck;
	do {
		cout<<"Vui long nhap lua chon: ";
		tempCheck = validateNumber(checkOption);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<checkOption;
	ss>>option;
		switch(option){
			case 0:
				return 0;
			case 1:
				{
				string temp;
				do {
					cout<<"Ten moi:";
					fflush(stdin);
					getline(cin, temp);
					temp = upperCase(temp);
					if(validateString(temp) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp) == false);
				name=temp;
				return 1;
			}
			case 2:
				{
				int dem;
				string temp;
				do{
				dem=0;
					do {
						cout<<"Ma moi:";
						fflush(stdin);
						getline(cin, temp);
						temp = upperCase(temp);
						if(validateString(temp) == false) {
							cout<<"Vui long nhap dung dinh dang!"<<endl;
						}
					}while(validateString(temp) == false);
				int n=temp.size();
				char temp_1[n+1];
				strcpy(temp_1,temp.c_str());
				for(int i=0;i<id_List.size();i++){
					if(strcmp(temp_1,id_List[i].c_str())==0){
					    cout<<"Nhap lai:\n";
						dem++;	
					}
				}
			}while(dem!=0);
//			     Sua lai gia tri cua vector
			    for(int j=0;j<id_List.size();j++){
			    	if(strcmp(code.c_str(),id_List[j].c_str())==0)
                        dem=j;      
				}
				id_List.erase(id_List.begin()+dem);
				id_List.push_back(temp);
				code=temp;
				return 1;
			}
			case 3:
				{
				string temp;
				do {
					cout<<"Danh muc moi: ";
					fflush(stdin);
					getline(cin, temp);
					temp = upperCase(temp);
					if(validateString(temp) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp) == false);
				category=temp;
				return 1;
			}
			case 4:
				{
				float num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Chiet khau moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				discount=num;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 5:
				{
				float num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Gia goc moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				price=num;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 6:
				{
				int num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"So luong san pham moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				number=num;
				return 1;
			}
			case 7:
				{
				Date temp;
				cout<<"Vui long nhap lai ngay san xuat:"<<endl;
				temp.inputDate();
				date=temp;
				expiryDate.setDate(updateExpiryDate());
				return 1;
			}
			case 8:
				{
				int num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Han su dung moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				valid=num;
				expiryDate.setDate(updateExpiryDate());
				return 1;
			}
			default: 
				cout<<"Lua chon khong ton tai";
				return 0;
		}
}

//Read and Write data to file
// Write and read file
void readDataFromFile(ListGoods &list){
	ifstream inputFile(FILE_PATH);
	string code, name, category, status;
	float discount, price, priceAfter;
	int number, valid;
	Date date, expiryDate;
	Goods temp;
		
	if(!inputFile.is_open()){
		cerr << "Khong the mo File - '" << FILE_PATH << "'" << endl;
		cout << "Nhan phim bat ki de tiep tuc" << endl;
		_getch();
		goto endPoint;
	}

	while(inputFile >> code){
		temp.setCode(code);
		inputFile.ignore();
		getline(inputFile, name);
		temp.setName(name);	
		getline(inputFile, category);
		temp.setCategory(category);		
		inputFile.ignore();
		getline(inputFile, status);
		temp.setStatusWithData(status);	
		inputFile >> discount;
		temp.setDiscount(discount);	
		inputFile >> price;
		temp.setPrice(price);	
		inputFile >> priceAfter;
		temp.setPriceAfter(priceAfter);		
		inputFile >> number;
		temp.setNumber(number);		
		inputFile >> valid;
		temp.setvalid(valid);		
		inputFile >> date.dd;
		inputFile >> date.mm;
		inputFile >> date.yyyy;
		temp.setDate(date);		
		inputFile >> expiryDate.dd;
		inputFile >> expiryDate.mm;
		inputFile >> expiryDate.yyyy;
		temp.setExpiryDate(expiryDate);
				
		list.insertLast(temp);
	}
	loadingAnimation(68, 2, "Dang doc file...", "Doc file thanh cong!!");
	endPoint:
	inputFile.close();
	system("cls");
}

void writeDataToFile(ListGoods list){
	ofstream outputFile(FILE_PATH);
		
	if(!outputFile.is_open()){
		cerr << "Khong the mo file- '" << FILE_PATH << "'" << endl;
		cout << "Nhan phim bat ki de tiep tuc" << endl;
		_getch();
		goto endPoint;
	}
		
	for(Node *i = list.head; i != NULL;i=i->next){
		outputFile << i->data.getCode() << "\n";
		outputFile << i->data.getName() << "\n";
		outputFile << i->data.getCategory() << "\n";
		outputFile << i->data.getStatus() << "\n";
		outputFile << i->data.getDiscount() << "\n";
		outputFile << i->data.getPrice() << "\n";
		outputFile << i->data.getPriceAfter() << "\n";
		outputFile << i->data.getNumber() << "\n";
		outputFile << i->data.getvalid() << "\n";		
		outputFile << i->data.getDate().getDay()<< "\n";
		outputFile << i->data.getDate().getMonth()<< "\n";
		outputFile << i->data.getDate().getYear()<< "\n";		
		outputFile << i->data.getExpiryDate().getDay()<< "\n";
		outputFile << i->data.getExpiryDate().getMonth()<< "\n";
		outputFile << i->data.getExpiryDate().getYear()<< "\n";
	}
	
	endPoint:
	outputFile.close();
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
=======
#include<iostream>
#include<ctime>
#include<iomanip>
#include<stdio.h> 
#include<string>
#include<vector>
#include"myDrawLib.h"
#include<conio.h>
#include<cmath>
#include<fstream>

using namespace std;

#define DEFAULT_TEXT_COLOR 91
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
// ngay thang nam
class Date {
	private:
		int dd;
		int mm;
		int yyyy;
	public:
		Date();
		Date(int dd, int mm, int yyyy);
		void setDate(const Date &a);
		~Date();
		void setDay(int dd);
		int getDay();
		void setMonth(int mm);
		int getMonth();
		void setYear(int yyyy);
		int getYear();
		bool checkDate();
		void inputDate();
		void outputDate();
		bool checkExpiryDate();
		friend class Goods;
};
//Lop hang hoa
class Goods {
	private:
		string name;		//ten hang hoa
		string code;		//ma hang hoa
		string category;	//danh muc
		string status;		//tinh trang
		float discount;		//chiet khau
		float price;		//gia goc
		float priceAfter;	//gia sau khi tru chiet khau
		int number;			//so luong
		Date date;			//ngay san xuat
		int valid;			//han su dung
		Date expiryDate;	//ngay het han
		
	public:
		//friend classes and functions
		friend class ListGoods;
		//Constructor
		Goods();
		Goods(string name, string code, int number, Date date, int valid, string status);
		//getter and setter
		string getName();
		void setName(string name);
		string getCategory();
		void setCategory(string category);
		string getCode();
		void setCode(string code);
		float getDiscount();
		void setDiscount(float discount);
		float getPrice();
		void setPrice(float price);
		float getPriceAfter();
		void setPriceAfter(float priceAfter);
		int getNumber();
		void setNumber(int number);
		int getvalid();
		void setvalid(int valid);
		string getStatus();
		void setStatus();
		//phuong thuc
		Date updateExpiryDate();
		void input();
		void output(int series);
		friend void outputTitle();
		~Goods();
		int Replace();
};
//Node hang hoa
class Node {
	public:
	Goods data;
	Node *next;
	//Node();
};
// Danh sach hang hoa
class ListGoods {
	private: 
		int size;
		Node *head;
		Node *tail;
	public:
		ListGoods();
		int getSize();
		Node *makeNode();
		Node *makeNode(Goods data);
		bool isEmpty();
		void output();
		void outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign);
		void insertLast();
		void insertLast(Goods data);
		bool checkCode(string code);
		~ListGoods();
		void Find_2();
		Node* Find_1();
		void Change();
};

//class menu
class Menu{
	private:
		int x, y;
		string title;
		vector<string> menuContent;
		int numberOfMenuItem;
		int padding;
		int targetLength;
	public:
		Menu(int x, int y, vector<string> _menuContent, string title);
		~Menu(){};
		void printMenu(const string& title, const string& textAlign, int padding);
		void setPadding(int padding);
		void setTargetLength(int length);
		int GetItemAmount();
		void clearMenuScreen();
		void start(ListGoods list);
};

int main() {
	ListGoods list;
	int soluong;
	SetScreenBufferSize(500, 500);
	SetWindowSize(300, 300);
	vector<string> menuContent{
							   "Nhap hang hoa",
							   "Xuat hang hoa",
							   "Tim kiem",
							   "Cap nhat hang hoa",
							   "Cap nhat hang hoa",
							   "Xuat thong tin vao file",
							   "Thoat"};
							   
	Menu menu(40, 2, menuContent, "QUAN LY CUA HANG");

	menu.start(list);
	_getch();
	return 0;
}

int ListGoods::getSize(){
	return size;
}

void ListGoods::outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign) {
	if(columns == 0 || rows == 0 || w == 0) return;
	int xStep = x;
	int _x = x;
	int _y = y;
	vector<string> title{"STT", "Name", "Category", "Amount", "Price", "Discount", "Total", "NSX", "HSD", "Status"};
	vector<Goods> content;

	for(Node *i = this->head;i != NULL; i=i->next){
		content.push_back(i->data);
	}// copy the linked list into vector list
	
	for(short k = 0; k < title.size(); k++){
		drawBox(_x + (k*w), y, w, 2, titleColor, 11, title[k] ,"center");
		if(k > 0){
			SetColor(titleColor);
			gotoXY(x + (w * k), y + 2);
			cout << char(193);
			gotoXY(x + (w * k), y);
			cout << char(194);
		}
	}
	_y+=3;
	
	for(short i = 0; i < rows; i++){
			drawBox(xStep, _y, w, 2, color, 250, to_string(i+1), contentAlign);
			xStep+=w;	
			drawBox(xStep, _y, w, 2, color, 250, content[i].name, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].category, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].number), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].price), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(round(content[i].discount)), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(round(content[i].priceAfter)), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].date.getDay()) + "/" + to_string(content[i].date.getMonth()) + "/" + to_string(content[i].date.getYear()), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].valid), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].status, contentAlign);
		for(short j = 0; j < title.size(); j++){
			if(i >= 1){
				SetColor(color);
				gotoXY(x, _y);
				cout << char(195);
				gotoXY(_x, _y);
				cout << char(197);
				gotoXY(x + w * (title.size()), _y);
				cout << char(180);
				if(j >= 1){
					gotoXY(_x,(y + 3) + 2 * rows);
					cout << char(193);
				}
			}else if(i < 1 && j >= 1){
				SetColor(color);
				gotoXY(_x, y + 3);
				cout << char(194);
			}
			_x+=w;
		}
				
		_y+=2;
		_x = x;
		xStep = x;
	}
	gotoXY(0, (y+3) + 2 * rows + 2);
	SetColor(DEFAULT_TEXT_COLOR);
	ShowCur(0);
}

//Constructor va huy cua Date
Date::Date() {
	this->dd = 1;
	this->mm = 1;
	this->yyyy = 2001;
}
Date::Date(int dd, int mm, int yyyy) {
	this->dd = dd;
	this->mm = mm;
	this->yyyy = yyyy;
}
void Date::setDate(const Date &a){
	this->dd = a.dd;
	this->mm = a.mm;
	this->yyyy = a.yyyy;
}
Date::~Date() {
}
// Getter va setter cho Date
void Date::setDay(int dd) {
	this->dd = dd;
}
int Date::getDay() {
	return dd;
}
void Date::setMonth(int mm) {
	this->mm = mm;
}
int Date::getMonth() {
	return mm;
}
void Date::setYear(int yyyy) {
	this->yyyy = yyyy;
}
int Date::getYear() {
	return yyyy;
}
// Kiem tra ngay
bool Date::checkDate() {
	int maxDay;
	    if (yyyy<=0 || mm<=0 || mm> 12 || dd<=0 || dd> 31)
    {
        return false;
    }
    else
    {
        switch (mm)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((yyyy%4==0 && yyyy%100!=0) || (yyyy%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (dd<=maxDay)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// Nhap ngay
void Date::inputDate() {
	bool temp;
	do {
		cout<<"Nhap ngay san xuat: "<<endl;
		cout<<"Ngay ";
		cin>>dd;
		cout<<"Thang ";
		cin>>mm;
		cout<<"Nam ";
		cin>>yyyy;
		temp = checkDate();
		if(temp == true) {
			if(yyyy <= 2000) {
				cout<<"Ngay san xuat phai dung dinh dang va lon hon 2000!"<<endl;
			}
		}else {
			cout<<"Ngay san xuat phai dung dinh dang va lon hon 2000!"<<endl;
		}
	}while(yyyy <= 2000 ||  temp == false);
}
//Xuat ngay
void Date::outputDate() {
	bool temp = checkDate();
	if(temp == false || yyyy <= 2000) {
		cout<<"Sai dinh dang, se thiet lap thanh ngay mac dinh!"<<endl;
		this->dd = 1;
		this->mm = 1;
		this->yyyy = 2001;
	}
	if(dd >= 10) {
		cout<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	} else {
		cout<<"0"<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	}
}
//so sanh ngay vua nhap voi ngay hien tai
bool Date::checkExpiryDate(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	if (yyyy < yearNow)
	{
		return false;
	}
	else if (yyyy == yearNow)
	{
		if (mm < monNow)
		{
			return false;
		}
		else if (mm == monNow)
		{
			if (dd < dayNow)
			{
				return false;
			}
		}
	}
	return true;
}

//getter and setter
string Goods::getName() {
	return name;
}
void Goods::setName(string name) {
	this->name = name;
}
string Goods::getCode() {
	return code;
}
void Goods::setCode(string code) {
	this->code = code;
}
int Goods::getNumber() {
	return number;
}
void Goods::setNumber(int number) {
	this->number = number;
}
string Goods::getCategory(){
	return category;
}
void Goods::setCategory(string category){
	this->category = category;
}
float Goods::getDiscount(){
	return discount;
}
void Goods::setDiscount(float discount){
	this->discount = discount;
}
float Goods::getPrice(){
	return price;
}
void Goods::setPrice(float price){
	this->price = price;
}
float Goods::getPriceAfter(){
	return priceAfter;
}
void Goods::setPriceAfter(float priceAfter){
	this->priceAfter = priceAfter;
}
int Goods::getvalid() {
	return valid;
}
void Goods::setvalid(int valid) {
	this->valid = valid;
}
string Goods::getStatus(){
	return status;
}
void Goods::setStatus(){
	if(expiryDate.checkExpiryDate()){
		this->status = "Con han";
	}
	else this->status = "Het han";
}
//khoi tao
Goods::Goods() {
	this->name = "";
	this->code = "";
	this->number = 0;
	this->valid = 3;
}
Goods::Goods(string name, string code, int number, Date date, int valid, string status) {
	this->name = name;
	this->code = code;
	this->number = number;
	this->date = date;
	this->valid = valid;
	this->status = status;
}
//cap nhat ngay het han
Date Goods::updateExpiryDate(){
	Date update(date.getDay(), date.getMonth(),date.getYear());
	int copyValid = valid;
	int maxDay;
	update.setYear(update.getYear() + (copyValid / 12));
	update.setMonth(update.getMonth() + (copyValid % 12));
	while(update.checkDate() == false){
		if(update.getMonth() > 12){
		update.setYear(update.getYear() + 1);
		update.setMonth(update.getMonth()-12);
	}
	switch (update.getMonth())
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((update.getYear()%4==0 && update.getYear()%100!=0) || (update.getYear()%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (update.getDay()>maxDay)
        {
            update.setMonth(update.getMonth()  + 1);
            update.setDay(update.getDay() - maxDay);
        }
	}
	return update;
}
//Nhap thong tin hang hoa
void Goods::input(){
	string nameTemp, codeTemp, categoryTemp;
	int numberTemp;
	float priceTemp, discountTemp;
	cout<<"Nhap thong tin san pham"<<endl;
	cout<<"Nhap ID: ";
	fflush(stdin);
	getline(cin, codeTemp);
	setCode(codeTemp);
	cout<<"Nhap ten: ";
	fflush(stdin);
	getline(cin, nameTemp);
	setName(nameTemp);
	cout<<"Nhap danh muc: ";
	fflush(stdin);
	getline(cin, categoryTemp);
	setCategory(categoryTemp);
	cout<<"Nhap so luong: ";
	cin>>numberTemp;
	setNumber(numberTemp);
	cout<<"Nhap gia thanh: ";
	cin>>priceTemp;
	setPrice(priceTemp);
	cout<<"Nhap chiet khau: ";
	cin>>discountTemp;
	setDiscount(discountTemp);
	setPriceAfter(getPrice()*(100-getDiscount())/100);
	date.inputDate();
	cout<<"Nhap han su dung(tu 1 thang tro len): ";
	do {
		cin>>valid;
		if(valid < 1) {
			cout<<"Nhap sai dinh dang thang "<<endl;
		}
	}while(valid< 1);
	expiryDate.setDate(updateExpiryDate());
	setStatus();
}
//xuat thong tin hang hoa
void Goods::output(int series){
	cout << "|" << 	setw(3) << left << series 		<< "|";
	cout << 		setw(4) << left << getCode() 		<< "|";
	cout <<			setw(15) << left << getName() 		<< "|";
	cout << 		setw(15) << left << getCategory() 	<< "|";
	cout << 		setw(6) << right << getNumber() 	<< "|";
	cout << 		setw(7) << right << getPrice() 		<< "|";
	cout << 		setw(8) << right << getDiscount() 	<< "|";
	cout << 		setw(7) << right << getPriceAfter() 		<< "|";
	date.outputDate();
	cout<<"|";
	expiryDate.outputDate();
	cout<<"|";
	cout << 		setw(7) << left << getStatus() 	<< "|"<<endl;;
}
void outputTitle(){
	cout << "|" << 	setw(3) << left << "STT" 		<< "|";
	cout << 		setw(4) << left << "ID" 		<< "|";
	cout <<			setw(15) << left << "Name" 		<< "|";
	cout << 		setw(15) << left << "Category" 	<< "|";
	cout << 		setw(6) << left << "Amount" 	<< "|";
	cout << 		setw(7) << left << "Price" 		<< "|";
	cout << 		setw(8) << left << "Discount" 	<< "|";
	cout << 		setw(7) << left << "Total" 		<< "|";
	cout << 		setw(10) << left << "NSX" 		<< "|";
	cout << 		setw(10) << left << "HSD" 		<< "|";
	cout << 		setw(7) << left << "Status" 	<< "|"<<endl;;
}

//ham huy
Goods::~Goods() {
}

//Constructor khoi tao gia tri 
ListGoods::ListGoods() {
	head = NULL;
	tail = NULL;
	this->size = 0;
}
//Ham huy
ListGoods::~ListGoods() {
}
//Tao ra Node moi
Node *ListGoods::makeNode() {
	Node *temp = new Node();
	temp->data.input();
	temp->next = NULL;
	return temp;
}
// Tao ra Node moi nhung co san gia tri
Node *ListGoods::makeNode(Goods data) {
	Node *temp = new Node();
	temp->data.setName(data.getName());
	temp->data.setCode(data.getCode());
	temp->data.setCategory(data.getCategory());
	temp->data.setNumber(data.getNumber());
	temp->data.setPrice(data.getPrice());
	temp->data.setDiscount(data.getDiscount());
	temp->data.setPriceAfter(data.getPriceAfter());
	Date tempDate(data.date.getDay(),data.date.getMonth(),data.date.getYear());
	temp->data.date = tempDate;
	temp->data.setvalid(data.getvalid());
	temp->data.expiryDate.setDate(data.updateExpiryDate());
	temp->data.setStatus();
	temp->next = NULL;
	return temp;
}

//Kiem tra danh sach rong
bool ListGoods::isEmpty() {
	if(head == NULL) {
		return true;
	}else {
		return false;
	}
}
//In ra danh sach hien tai
void ListGoods::output() {
	Node *temp = head;
	outputTitle();
	int series = 1;
	while(temp != NULL) {
		temp->data.output(series);
		series++;
		temp = temp->next;
	}
}
//Nhap them hang vao cuoi danh sach
void ListGoods::insertLast() {
	Node *temp = makeNode();
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//Nhap them hang vao cuoi danh sach nhung co data
void ListGoods::insertLast(Goods data) {
	Node *temp = makeNode(data);
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//kiem tra trung id
bool ListGoods::checkCode(string code){
	for(Node *i = head; i != NULL; i = i->next){
		if(i->data.getCode() == code)
		return false;
	}
	return true;
}
// Chuc nang tim kiem
void ListGoods::Find_2(){
	int select,dem=0;
	char temp_1[100],temp_2[100];
	do{
	cout<<"Lua chon thong tin tim kiem\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Danh muc\n";
	cout<<"3.Tinh trang\n";
	cout<<"0.Thoat\n";
	cout<<"Nhap lua chon:";
	cin>>select;
	switch(select){
		case 1:
			{
				cout<<"Nhap ten:";
				fflush(stdin);
				gets(temp_1);
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){	
                    if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				    }
				break;
			}       
			case 2:
				{
					cout<<"Nhap danh muc:";
				fflush(stdin);
				gets(temp_1);
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){
				    if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				    }
				break;
				}
				case 3:
					{
						cout<<"Nhap tinh trang:";
				        fflush(stdin);
				        gets(temp_1);
				        outputTitle();
				        for(Node* i=head;i!=NULL;i=i->next){
				            if( strstr( strupr(strcpy(temp_2, i->data.status.c_str())),strupr(temp_1) ) ){
				                dem++;
				                i->data.output(dem);
				            }
				    }
				    break;
					}
			
	}
}while(select!=0);
	
}
//Chuc nang sua
Node* ListGoods:: Find_1(){
	Node* p=new Node;
	char temp_1[100],temp_2[100];
	int dem_1 =0,dem_2=0;
    cout<<"Nhap ma san pham:";
    fflush(stdin);
    gets(temp_1);
		for(Node* i=head;i!=NULL;i=i->next){
			dem_1++;
			if( strstr( strupr(strcpy(temp_2, i->data.code.c_str())),strupr(temp_1) ) ){
			dem_2++;
			outputTitle();
			i->data.output(dem_1);
			return i;
					}	
				}
				    if(dem_2==0)
				        cout<<"Ma san pham khong co trong danh sach\n";
				    return p;
			}
void ListGoods:: Change(){
	int option,check,dem_1=0,dem_2=0;
	do{
	cout<<"\n\nVui long chon phuong thuc ma ban muon thay doi\n";
	cout<<"1.Sua lai thong tin san pham\n";
	cout<<"2.Xoa san pham\n";
	cout<<"0.Thoat\n";
	cout<<"Vui long nhap lua chon:";
	do{
		cin>>option;
		if(option<0||option>2)
		    cout<<"Nhap lai!\n";
	}while(option<0||option>2);
	switch(option){
		case 0:
			break;
		case 1:
			{
        for(Node* i=head;i!=NULL;i=i->next){
        	dem_2++;
        	if(i==Find_1()){
        		check=i->data.Replace();
        		dem_1++;
        		if(check==1){
        		cout<<"Ket qua sau khi sua la:\n";
        		outputTitle();
        		i->data.output(dem_2);
        		break;
        	}
        	else	break;
			}
		}
		if(dem_1==0)
		    cout<<"Khong tim thay du lieu tu thong tin ma ban nhap vao\n";
		break;
	}
    case 2: {
		for(Node* i=head;i!=NULL;i=i->next){
			dem_2++;
			if(i=Find_1()){
				cout<<"Chon 1 de tiep tuc\n";
				cout<<"Chon 0 de thoat\n";
				do{
					cout<<"Nhap lua chon:";
					cin>>check;
				}while(check<0||check>1);
				if(check==0)
				    break;
				else{
				if(i=head){
	        	head=head->next;
	        	delete i;
	        	dem_1++;
            	}
            	else if(i=tail){
	        	Node* q=head;
		        while(q->next->next!=NULL){
			        q=q->next;
		        }
	        	tail=q;
		        q->next=NULL;
		        delete i;
		        dem_1++;
             	}
	            else{ 
//	            	for(Node* p=head;p->next==i;p=p->next){
//	            	    p->next=p->next->next;
//						dem_1++;	
//					}
                    Node* p=head;
                    while(p->next==i){
                    	p->next=p->next->next;
                    	delete i;
                    	dem_1++;
					}	
	            }	
		        cout<<"Danh sach sau khi xoa la:\n";
		     	output ();
        	    
		if(dem_1==0)
		    cout<<"Phan tu can xoa khong co trong danh sach\n";
		break;
	        }   
		    }
	    }
	    break;
   }   
   }
}while(option!=0);
}
int Goods::Replace(){
	int option;
	cout<<"\nVui long lua chon phan thong tin can sua\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Ma san pham\n";
	cout<<"3.Danh muc \n";
	cout<<"4.Gia chiet khau\n";
	cout<<"5.Gia goc \n";
	cout<<"6.So luong san pham\n";
	cout<<"7.Ngay san xuat \n";
	cout<<"8.Han su dung \n";
	cout<<"0.Thoat\n";
	cout<<"Vui long nhap lua chon:";
	cin>>option;
		switch(option){
			case 0:
				return 0;
			case 1:
				{
				string temp;
				cout<<"Vui long nhap ten moi:";
				fflush(stdin);
				getline(cin,temp);
				name=temp;
				return 1;
			}
			case 2:
				{
				string temp;
				cout<<"Vui long nhap ma moi:";
				fflush(stdin);
				getline(cin,temp);
				code=temp;
				return 1;
			}
			case 3:
				{
				string temp;
				cout<<"Vui long nhap danh muc moi\n";
				fflush(stdin);
				getline(cin,temp);
				category=temp;
				return 1;
			}
			case 4:
				{
				float temp;
				cout<<"Vui long nhap lai gia chiet khau\n";
				cin>>temp;
				discount=temp;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 5:
				{
				float temp;
				cout<<"Vui long nhap lai gia goc\n";
				cin>>temp;
				price=temp;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 6:
				{
				int temp;
				cout<<"Vui long nhap lai so luong san pham\n";
				cin>>temp;
				number=temp;
				return 1;
			}
			case 7:
				{
				Date temp;
				cout<<"Vui long nhap lai ngay san xuat\n";
				temp.inputDate();
				date=temp;
				expiryDate.setDate(updateExpiryDate());
				return 1;
			}
			case 8:
				{
				int temp;
				cout<<"Nhap lai han su dung\n";
				cin>>temp;
				valid=temp;
				expiryDate.setDate(updateExpiryDate());
				return 1;
			}
			default: return 0;
		}
}

//
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
				124, 
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
							cout<<"Nhap so luong mat hang: ";
							cin>>soLuong;
							if(soLuong <= 0) {
								cout<<"Nhap sai so luong. Vui long nhap lai!"<<endl;
							}
							}while(soLuong <= 0);
							for(int i = 0; i<soLuong; i++) {
								Goods a;
								do{
									a.input();
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
							list.outputAsTable(0, pointerY, 20, 10, list.getSize(), 196, 1, "center");
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
							cout << "Chuc nang 5" << endl;
						}
						this->clearMenuScreen();
						goto startPoint;
					case 5:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							cout << "Chuac nang 6" << endl;
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 6:
						cout << "Ban da chon thoat chuong tring!!" << endl;
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

>>>>>>> 78f2d6c4ad695e9890476153688c74a61e15563e
