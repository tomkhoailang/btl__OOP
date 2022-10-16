#include"person.h"
//getter setter
Person::Person() {
}
Person::~Person() {
}
string Person::getUserName() {
	return this->username;
}
string Person::getPassWord() {
	return this->password;
}
void Person::setUserName(string username) {
	this->username = username;
}
void Person::setPassword(string password) {
	this->password = password;
}
void Person::calculation(ListGoods list) { 
	Node *a = new Node;
	int totalPrice = 0;
	vector<Goods> invoice;
	vector<int> quantity;
	vector<long> endPrice;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
	int select;
	do {
		cout<<"1. Them san pham"<<endl;
		cout<<"2. Xem hoa don"<<endl;
		cout<<"3. Chinh hoa don"<<endl;
		cout<<"4. Xuat hoa don"<<endl;
		cout<<"5. Thoat"<<endl;
		do {
			cout << "Nhap lua chon: ";
			tempCheck = validateNumber(checkNumber);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<checkNumber;
		ss>>select;				
		switch(select) {
			case 1: {
				a = list.Find_1();
				bool check = true;
				if(a != NULL) {
					for(int i = 0; i < invoice.size(); ++i){
					if(a->data.getCode() == invoice[i].getCode()){
						cout<<"San pham nay da co trong danh sach thanh toan."<<endl;
						check = false;
						break;
					}
				}
				if(check){
					if(a->data.getStatus() == "HET HAN"){
					cout<<"San pham hien tai da het han! Khong the thuc hien thanh toan."<<endl;
				}else{
					int number;
					do {
						cout<<"Nhap so luong san pham: ";
						tempCheck = validateNumber(checkNumber);
						if(tempCheck == false) {
							cout<<"Nhap sai dinh dang"<<endl;
						}
					}while(tempCheck == false);
					ss.clear();
					ss<<checkNumber;
					ss>>number;
					if(number < 1 || number > a->data.getNumber()) {
						cout<<"Them san pham that bai!"<<endl;
					}else {
						a->data.setNumber(a->data.getNumber() - number);
						invoice.push_back(a->data);
						quantity.push_back(number);
						endPrice.push_back(number * a->data.getPriceAfter());
						cout<<"San pham da duoc them vao gio hang"<<endl;
					}
				}
			}
	
				}else {
					cout<<"Vui long nhap chinh xac ma san pham!"<<endl;
				}
				break;
			}
				
			case 2:{
				if(invoice.size()==0){
					cout<<"Gio hang trong!."<<endl;
				}
				else{
					long endOfPrice = 0;
				cout <<endl<<setw(30)<<"Ten san pham"
					 <<setw(4)<<right<<"SL"
					 <<setw(9)<<right<<"Gia ban"
					 <<setw(6)<<right<<"CK"
					 <<setw(11)<<right<<"Thanh tien"<<endl;
				for(int i = 0; i < 60; ++i)
					cout<<"_";
				cout<<endl;	
				for(int i = 0; i < invoice.size(); i++) {
					cout 	<<setw(30)<<left<<invoice[i].getName()
					 		<<setw(4)<<right<<quantity[i]
							<<setw(9)<<right<<invoice[i].getPrice()
							<<setw(5)<<right<<invoice[i].getDiscount()<<"%"
							<<setw(11)<<right<<endPrice[i]<<endl;
				}
				for(int i = 0; i < 60; ++i)
					cout<<"_";
				cout<<endl;				
				for(int i = 0; i < endPrice.size(); i++) {
					endOfPrice += endPrice[i];
				}
				cout<<setw(48)<<left<<"\nTong hoa don: "<<setw(13)<<right<<endOfPrice<<endl<<endl;
				}
				
				break;
			}
			case 3:
				if(invoice.size()==0){
					cout<<"Gio hang trong!."<<endl;
				}
				else{
				int num;
				bool check = false;
				a = list.Find_1();
				for(int i = 0; i < invoice.size(); ++i){
					if(a->data.getCode() == invoice[i].getCode()){
						do {
							cout<<"So luong moi: ";
							tempCheck = validateNumber(checkNumber);
							if(tempCheck == false) {
								cout<<"Nhap sai dinh dang"<<endl;
							}
						}while(tempCheck == false);
						ss.clear();
						ss<<checkNumber;
						ss>>num;
						if(num == 0){
							a->data.setNumber(a->data.getNumber() + quantity[i]);
							quantity.erase(quantity.begin() + i);
							invoice.erase(invoice.begin() + i);
						}
						else if(a->data.getNumber() + quantity[i] - num < 0){
							cout<<"So luong can thay doi qua lon! Khong the sua"<<endl;
						}
						else{
							endPrice[i] = num * a->data.getPriceAfter();
							a->data.setNumber(a->data.getNumber() + quantity[i] - num);
							quantity[i] = num;
							cout<<"Da cap nhat hoa don."<<endl;
						}
						check = true;
						break;
					}
				}
				if(!check)
				cout<<"San pham nay hien khong co trong danh sach thanh toan."<<endl;
			}
			case 4:
				if(invoice.size()==0){
					cout<<"Gio hang trong!."<<endl;
				}
				else{
					while(invoice.size()>0)
						invoice.pop_back();
					cout<<"Da xuat hoa don!."<<endl;	
				}
				break;
			case 5:
				if(invoice.size()>0){
					int choice;
					cout<<"Hoa don chua duoc xuat. Ban co muon xuat hoa don ?"<<endl;
					cout<<"1.Co\n"<<"2.Khong"<<endl;
					do{
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
						if(choice==1){
							while(invoice.size()>0)
								invoice.pop_back();
							cout<<"Da xuat hoa don!."<<endl;
						}
						else if(choice==2){
							for(int i=0; i < invoice.size(); ++i)
								a->data.setNumber(a->data.getNumber() + quantity[i]);
						}
						else cout<<"Lua chon khong ton tai"<<endl;
					}while(choice!=1&&choice!=2);
				}	
				
		}
	}while(select != 5);
}
