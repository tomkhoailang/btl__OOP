#include <iostream>
using namespace std;
class Date {
	private:
		int dd;
		int mm;
		int yyyy;
	public:
		Date();
		Date(int dd, int mm, int yyyy);
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
		friend class Goods;
};
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
	int ngaymax;
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
              ngaymax=31;
              break;
            case 2:
                if ((yyyy%4==0 && yyyy%100!=0) || (yyyy%400==0))
                    ngaymax=29;
                else 
                    ngaymax=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ngaymax=30;
                break;
        }
        if (dd<=ngaymax)
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
	cout<<"Ngay san xuat: ";
	if(dd >= 10) {
		cout<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy<<endl;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy<<endl;
		}
	} else {
		cout<<"0"<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy<<endl;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy<<endl;
		}
	}
}
class Goods {
	private:
		string name;
		string code;
		int number;
		Date date;
		int validDate;
	public:
		Goods();
		Goods(string name, string code, int number, Date date, int validDate);
		string getName();
		void setName(string name);
		string getCode();
		void setCode(string code);
		int getNumber();
		void setNumber(int number);
		int getValidDate();
		void setValidDate(int validDate);
		~Goods();
		friend class ListGoods;
		
};
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
int Goods::getValidDate() {
	return validDate;
}
void Goods::setValidDate(int validDate) {
	this->validDate = validDate;
}
Goods::Goods() {
	this->name = "";
	this->code = "";
	this->number = 0;
	this->validDate = 3;
}
Goods::Goods(string name, string code, int number, Date date, int validDate) {
	this->name = name;
	this->code = code;
	this->number = number;
	this->date = date;
	this->validDate = validDate;
}
Goods::~Goods() {
}
//Node hang hoa
struct Node {
	Goods data;
	Node *next;
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
		Node *insertFirst();
		Node *insertFirst(Goods data);
		Node *insertLast();
		Node *insertLast(Goods data);
		~ListGoods();
};
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
	string nameTemp, codeTemp;
	int numberTemp;
	cout<<"Nhap thong tin san pham"<<endl;
	cout<<"Nhap ID: ";
	fflush(stdin);
	getline(cin, codeTemp);
	temp->data.setCode(codeTemp);
	cout<<"Nhap ten: ";
	fflush(stdin);
	getline(cin, nameTemp);
	temp->data.setName(nameTemp);
	cout<<"Nhap so luong: ";
	cin>>numberTemp;
	temp->data.setNumber(numberTemp);
	temp->data.date.inputDate();
	cout<<"Nhap han su dung(tu 3 thang tro len): ";
	do {
		cin>>temp->data.validDate;
		if(temp->data.validDate < 3) {
			cout<<"Nhap sai dinh dang thang "<<endl;
		}
	}while(temp->data.validDate< 3);

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
	temp->data.setValidDate(data.getValidDate());
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
	cout<<"Thong tin san pham "<<endl;
	while(head != NULL) {
		cout<<"Ten san pham: "<<temp->data.getName()<<endl;
		cout<<"Ma ID: "<<temp->data.getCode()<<endl;
		cout<<"So luong san pham: "<<temp->data.getNumber()<<endl;
		temp->data.date.outputDate();
		cout<<"Han su dung: "<<temp->data.getValidDate()<<" thang"<<endl;
		temp = temp->next;
	}
}
//Nhap them hang vao dau danh sach
Node *ListGoods::insertFirst() {
	Node *temp = makeNode();
	if (isEmpty() == true) {
		head = tail = temp;
		size++;
	}else {
		temp->next = head;
		head = temp;
	}
}
// Nhap them hang vao dau danh sach nhung co data
Node *ListGoods::insertFirst(Goods data) {
	Node *temp = makeNode(data);
	if (isEmpty() == true) {
		head = tail = temp;
		size++;
	}else {
		temp->next = head;
		head = temp;
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

