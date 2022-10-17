#include"date_goods.h"
using namespace std;
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
			cout<<"Ngay  san xuat khong duoc lon hon ngay hien tai!"<<endl;
			}
		}else {
			cout<<"Nam san xuat phai lon hon 2000"<<endl;
		}
	}while(yyyy <= 2000 ||  temp == false || checkExpiryDate());
}
//Nhap ngay sinh cua nhan vien
void Date::inputPerson() {
	bool temp;
	bool tempCheck;
	string ddTemp,mmTemp,yyyyTemp;
	stringstream ss;
	do {
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
			yyyy = yyyyTemp2;
			temp = checkDate();
			if(temp != true) {
				cout<<"Ngay vua nhap phai dung dinh dang"<<endl;
			}
			else if(checkExpiryDate()){
				cout<<"Ngay vua nhap khong duoc lon hon ngay hien tai!"<<endl;
			}
	}while(temp == false || checkExpiryDate());
}
//Xuat ngay
void Date::outputDate() {
	bool temp = checkDate();
	if(temp == false) {
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
//mh7
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

//Tra ve ngay hien tai
Date nowDate(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	Date now(dayNow, monNow, yearNow);
	return now;
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
long Goods::getPrice(){
	return price;
}
void Goods::setPrice(long price){
	this->price = price;
}
long Goods::getPriceAfter(){
	return priceAfter;
}
void Goods::setPriceAfter(long priceAfter){
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

//Nhap thong tin hang hoa
void Goods::input(){
	bool tempCheck;
	string nameTemp, codeTemp, categoryTemp;
	stringstream ss;
	string priceTemp, discountTemp, numberTemp, validTemp;
	int numberTemp2,validTemp2;
	long priceTemp2;
	float discountTemp2;
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
	cout << 		setw(7) << left << getStatus() 	<< "|"<<endl;
}
int Goods::Replace(vector<string> &id_List){
	int option;
	cout<<"\nVui long lua chon phan thong tin can sua\n";
	cout<<"1. Ten san pham\n";
	cout<<"2. Ma san pham\n";
	cout<<"3. Danh muc \n";
	cout<<"4. Gia chiet khau\n";
	cout<<"5. Gia goc \n";
	cout<<"6. So luong san pham\n";
	cout<<"7. Ngay san xuat \n";
	cout<<"8. Han su dung \n";
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
//			case 0:
//				return 0;
			case 1:
				{
				string temp;
				do {
					cout<<"Ten moi: ";
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
						cout<<"Ma moi: ";
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
                id_List.clear();
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
				long num;
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
				setStatus();
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
				setStatus();
				return 1;
			}
			default: 
				cout<<"Lua chon khong ton tai!";
				return 0;
		}
}

//ham huy
Goods::~Goods() {
}
