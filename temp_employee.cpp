#include"temp_employee.h"

//tempemployee
TempEmployee::TempEmployee() {
}
TempEmployee::~TempEmployee() {
}

TempEmployee::TempEmployee(const TempEmployee& data){
	this->name = data.name;
	this->age = data.age;
	this->gender = data.gender;
	this->birth.dd = data.birth.dd;
	this->birth.mm = data.birth.mm;
	this->birth.yyyy = data.birth.yyyy;
	this->startWork.dd = data.startWork.dd;
	this->startWork.mm = data.startWork.mm;
	this->startWork.yyyy = data.startWork.yyyy;
	this->phoneNumber = data.phoneNumber;
	this->setMonth();
}
string TempEmployee::getName() {
	return this->name;
}
string TempEmployee::getGender() {
	return this->gender;
}
string TempEmployee::getPhoneNumber(){
	return this->phoneNumber;
}
int TempEmployee::getAge(){
	return this->age;
}
Date TempEmployee::getBirth() {
	return this->birth;
}
int TempEmployee::getMonth(){
	return this->month;
}
void TempEmployee::setName(string name) {
	this->name = name;
}
void TempEmployee::setGender(string gender) {
	this->gender = gender;
}
void TempEmployee::setBirth(Date birth) {
	this->birth = birth;
}
void TempEmployee::setAge(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int yearNow = tm.tm_year + 1900;
	this->age = yearNow - this->birth.getYear();
}
void TempEmployee::setPhoneNumber(string phoneNumber){
	this->phoneNumber = phoneNumber;
}

void TempEmployee::setMonth() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	int month = 0;
	month = (yearNow - startWork.getYear()) * 12;
	month += monNow - startWork.getMonth();
	if(dayNow < startWork.getDay())
		month -= 1;
	this->month = month;	
}
long TempEmployee::salary() {
	return 3000000;
}
void TempEmployee::input() {
	bool checkPhone;
	bool checkP;
	string choiceGender;
	do{
		cout<<"\nTen nhan vien: ";
		fflush(stdin);
		getline(cin, name);
		name = upperCase(name);
		if(!validateString(name))
			cout<<"Ten sai dinh dang! Vui long nhap lai."<<endl;
	}while(!validateString(name));
	
	cout<<"Gioi tinh: "<<endl;
	cout<<"1. Nam"<<endl<<"2. Nu"<<endl;
	
	do{
		cout<<"Chon gioi tinh: ";
		fflush(stdin);
		getline(cin, choiceGender);
		if(choiceGender=="1")
			gender = "NAM";
		else if(choiceGender=="2")
			gender = "NU";
		else cout<<"sai"<<endl;
	}while(choiceGender!="1"&&choiceGender!="2");
	do {
		cout<<"So dien thoai: ";
		checkPhone = validateNumber(phoneNumber);
		if(!checkPhone)
			cout<<"So dien thoai khong hop le! Vui long nhap lai."<<endl;
		else{
			if(phoneNumber.length()!=10){
				cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
				checkPhone = false;
			}
			else if(phoneNumber[0] != '0'){
				cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
				checkPhone = false;
			}else {
				checkP = true;
				for(int i = 0; i < phone_Number.size(); i ++) {
					if(strcmp(phoneNumber.c_str(), phone_Number[i].c_str()) == 0)
						checkP = false;
				}
				if(checkP == false)
					cout<<"So dien thoai da ton tai"<<endl;
			}
		}
	}while(!checkPhone||checkP == false);
	phone_Number.push_back(phoneNumber);
	
	do{
		cout<<"Nhap ngay sinh: "<<endl;
		birth.inputPerson();
		setAge();
		if(age<18)
			cout<<"Nhan vien chua du tuoi lam viec! Vui long nhap lai."<<endl;
	}while(age<18);
	cout<<"Ngay bat dau lam viec: "<<endl;
	cout<<"1. Ngay hien tai"<<endl<<"2. Nhap ngay lam viec"<<endl;
	do{
		cout<<"Nhap lua chon: ";
		fflush(stdin);
		getline(cin, choiceGender);
		if(choiceGender=="1")
			startWork.setDate(nowDate());
		else if(choiceGender=="2"){
			do{
				cout<<"Nhap ngay bat dau lam viec: "<<endl;
				startWork.inputPerson();
				if(startWork.getYear() - birth.getYear() < 18)
					cout<<"Nhan vien chua du tuoi lam viec! Vui long nhap lai."<<endl;
			}while(startWork.getYear() - birth.getYear() < 18);
		}
		else cout<<"sai"<<endl;
	}while(choiceGender!="1"&&choiceGender!="2");
	setMonth();
}
void TempEmployee::setStartWork(Date startWork){
	this->startWork.dd = startWork.dd;
	this->startWork.mm = startWork.mm;
	this->startWork.yyyy = startWork.yyyy;
}

Date TempEmployee::getStartWork(){
	return this->startWork;
}
