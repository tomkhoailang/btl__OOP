#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

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
		friend class ListGoods;
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
		Node *makeNode();
		Node *makeNode(Goods data);
		bool isEmpty();
		void output();
		Node *insertLast();
		Node *insertLast(Goods data);
		~ListGoods();
};
int main() {
	ListGoods list;
	int soluong;
	do {
		cout<<"Nhap so luong mat hang: ";
		cin>>soluong;
		if(soluong <= 0) {
			cout<<"Nhap sai so luong. Vui long nhap lai!"<<endl;
		}
	}while(soluong <= 0);
	for(int i = 0; i<soluong; i++) {
		list.insertLast();
	}
	list.output();
	return 0;
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
		if (yyyy > yearNow)
	{
		return true;
	}
	else if (yyyy == yearNow)
	{
		if (mm > monNow)
		{
			return true;
		}
		else if (mm == monNow)
		{
			if (dd > dayNow)
			{
				return true;
			}
		}
	}
	return false;
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
	if(expiryDate.checkExpiryDate())
	this->status = "Con han";
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
	temp->data.setNumber(data.getNumber());
	Date tempDate(data.date.getDay(),data.date.getMonth(),data.date.getYear());
	temp->data.date = tempDate;
	temp->data.setvalid(data.getvalid());
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
Node *ListGoods::insertLast() {
	Node *temp = makeNode();
	if (isEmpty() == true) {
		head = tail = temp;
		size++;
	}else {
		tail->next = temp;
		tail = temp;
	}
}
//Nhap them hang vao cuoi danh sach nhung co data
Node *ListGoods::insertLast(Goods data) {
	Node *temp = makeNode(data);
	if (isEmpty() == true) {
		head = tail = temp;
		size++;
	}else {
		tail->next = temp;
		tail = temp;
	}
}


