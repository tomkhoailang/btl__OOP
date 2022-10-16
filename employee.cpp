#include"employee.h"
int Employee::id = 0;
Employee::Employee(const Employee& data){
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
	this->password = data.password;
	this->username = data.username;
	this->wage = data.wage;
	this->setMonth();
}
void TempEmployee::output() {
	cout <<"|"<<			setw(15) << left << getName() 		<< "|";
	cout << 		setw(9) << left << getGender() 		<< "|";
	cout << 		setw(13) << left << getPhoneNumber() 	<< "|";
	birth.outputDate();
	cout<<"|  ";
	startWork.outputDate();
	cout<<"|";
	cout << 		setw(17) << right << getMonth() 	<< "|";
	cout << 		setw(12) << right 	<< "|";
	cout << 		setw(12) << right << salary() 	<< "|";
	cout << 		setw(12) << right << salary() 	<< "|";
	cout << 		setw(11) << right << "THU VIEC" 	<< "|" << endl;
}
//class employee
Employee::Employee() {
}
Employee::~Employee() {
}
float Employee::getWage(){
	return this->wage;
}
void Employee::setWage(){
	int _month = this->month;
	float _wage = 1;
	while(_month > 5){
		_month -=6;
		_wage +=0.1;
	}
	this->wage = _wage;
}
void Employee::setWage(float wage){
	this->wage = wage;
}
long Employee::salary() {
	return 9000000 * wage;
}
void Employee::input() {
	//chinh thanh viet lien khong cho phep cach ra
	bool check;
	do {
		
		cout<<"Nhap ten tai khoan: ";
		fflush(stdin);
		getline(cin, username);
		if(validateString(username) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
		else if(checkUser(username) == false)
			cout<<"Ten tai khoan phai tu 5 ky tu tro len va khong chua dau cach!"<<endl;
		else{
			check = true;
			for(int i = 0;i<user_Name.size();i++){
				if(strcmp(username.c_str(), user_Name[i].c_str()) == 0){
					check = false;
				}
			}
		}
		if(check == false)
			cout<<"Ten tai khoan da ton tai"<<endl;
	}while(validateString(username) == false || checkUser(username) == false || check == false);
	user_Name.push_back(username);
	// nhap binh thuong
	do {
		cout<<"Nhap mat khau: ";
		fflush(stdin);
		getline(cin, password);
		if(validateString(password) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
		else if(checkUser(password) == false)
		cout<<"Mat khau phai tu 5 ky tu tro len va khong chua dau cach!"<<endl;
	}while(validateString(password) == false || checkUser(password) == false);
	TempEmployee::input();
	setWage();
}
void Employee::output() {
	
	cout <<"|"<<			setw(15) << left << getName() 		<< "|";
	cout << 		setw(9) << left << getGender() 		<< "|";
	cout << 		setw(13) << left << getPhoneNumber() 	<< "|";
	birth.outputDate();
	cout<<"|  ";
	startWork.outputDate();
	cout<<"|";
	cout << 		setw(17) << right << getMonth() 	<< "|";
	cout << 		setw(11) << right << getWage()	<< "|";
	cout << 		setw(12) << right << "9000000" 	<< "|";
	cout << 		setw(12) << right << (int)salary() 	<< "|";
	cout << 		setw(11) << right << "CHINH THUC" 	<< "|"<<endl;
}
void Employee::outputUser() {
	cout <<"|"<<			setw(20) << left << getUserName() 		<< "|";
	cout << 		setw(20) << left << getPassWord() 		<< "|" << endl;
}

