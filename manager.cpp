#include"manager.h"
void Manager::addPhone_Number(vector<string> &phone_Number){
	phone_Number.clear();
	for(Node_1* i = head_1; i != NULL; i = i->next){
		phone_Number.push_back(i->data_1.getPhoneNumber());
	}
	for(Node_2* j = head_2; j != NULL; j = j->next){
		phone_Number.push_back(j->data_2.getPhoneNumber());
	}
}
Node_1 *Manager::makeNode_1(const TempEmployee& data){
	Node_1 *newNode = new Node_1;
	newNode->data_1 = data;
	newNode->next = NULL;
	return newNode;
}

void Manager::insertLast_1(const TempEmployee& data){
	Node_1 *newNode = makeNode_1(data);
	if (isEmpty_1() == true) {
		head_1 = tail_1 = newNode;
		this->size_1++;
	}else {
		tail_1->next = newNode;
		tail_1 = newNode;
		this->size_1++;
	}
}

void Manager::insertLast_2(const Employee& data){
	Node_2 *newNode = makeNode_2(data);
	if (isEmpty_2() == true) {
		head_2 = tail_2 = newNode;
		this->size_2++;
	}else {
		tail_2->next = newNode;
		tail_2 = newNode;
		this->size_2++;
	}
}

Node_2 *Manager::makeNode_2(const Employee& data){
	Node_2 *newNode = new Node_2;
	newNode->data_2 = data;
	newNode->next = NULL;
	return newNode;
}


// class manager



Manager::Manager() {
	this->head_1 = NULL;
	this->tail_1 = NULL;
	this->size_1 = 0;
	this->head_2 = NULL;
	this->tail_2 = NULL;
	this->size_2 = 0;
}
Manager::~Manager() {
}
int Manager::getSize_1(){
	return this->size_1;
}
int Manager::getSize_2(){
	return this->size_2;
}
// nhap xuat tempemployee
bool Manager::isEmpty_1() {
	if(head_1 == NULL) {
		return true;
	}else {
		return false;
	}
}
Node_1 *Manager::makeNode_1() {
	Node_1 *temp = new Node_1();
	temp->data_1.input();
	output_title_2();
	temp->data_1.output();
	temp->next = NULL;
	return temp;
}
void Manager::insertLast_1() {
	Node_1 *temp = makeNode_1();
	if (isEmpty_1() == true) {
		head_1 = tail_1 = temp;
		this->size_1++;
	}else {
		tail_1->next = temp;
		tail_1 = temp;
		this->size_1++;
	}

}
//nhap xuat employee
bool Manager::isEmpty_2() {
	if(head_2 == NULL) {
		return true;
	}else {
		return false;
	}
}
Node_2 *Manager::makeNode_2() {
	Node_2 *temp = new Node_2();
	temp->data_2.input();
	output_title_2();
	temp->data_2.output();
	temp->next = NULL;
	return temp;
}
void Manager::insertLast_2() {
	Node_2 *temp = makeNode_2();
	if (isEmpty_2() == true) {
		head_2 = tail_2 = temp;
		this->size_2++;
	}else {
		tail_2->next = temp;
		tail_2 = temp;
		this->size_2++;
	}

}
void Manager::output_2() {
	if(head_2==NULL){
		
	}
	else{
		for(Node_2 *i = head_2; i != NULL; i = i->next) {
			i->data_2.output();
	}
	}
	
}

void Manager::output_User() {
	if(head_2==NULL){
		
	}
	else{
		for(Node_2 *i = head_2; i != NULL; i = i->next) {
			i->data_2.outputUser();
	}
	}
	
}

void Manager::output_1() {
	if(head_1==NULL){
		
	}
	else{
		for(Node_1 *i = head_1; i != NULL; i = i->next) {
			i->data_1.output();
	}
}
	}
//chuc nang manager 

Employee Manager::getEmployeeByUserName(string username){
	for(Node_2* i = this->head_2;i!=NULL;i=i->next){
		if(i->data_2.getUserName() == username){
			return i->data_2;
		}
	}
}
void readManagerDataFromFile(Manager &list){
	string name, gender, phoneNumber, username, password;
	string ename, egender, ephoneNumber;
	int age;
	float wage;
	Date birthDay;
	Date workStart;
	Date ebirthDay;
	Date eworkStart;
//	ifstream tempEmployeeIn();
	ifstream employeeIn(EMPLOYEE_INFO_FILE_PATH);
	if(!employeeIn.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeIn.close();
	}
	Employee temp;
	while(employeeIn >> wage){
		employeeIn >> username;
		user_Name.push_back(username);
		employeeIn >> password;
		employeeIn.ignore();
		getline(employeeIn, name);
		employeeIn >> birthDay.dd;
		employeeIn >> birthDay.mm;
		employeeIn >> birthDay.yyyy;
		employeeIn >> workStart.dd;
		employeeIn >> workStart.mm;
		employeeIn >> workStart.yyyy;
		employeeIn >> phoneNumber;
		phone_Number.push_back(phoneNumber);
		employeeIn.ignore();
		employeeIn >> gender;
		temp.setName(name);
		temp.setBirth(birthDay);
		temp.setStartWork(workStart);
		temp.setPhoneNumber(phoneNumber);
		temp.setWage(wage);
		temp.setPassword(password);
		temp.setUserName(username);
		temp.setGender(gender);
		temp.setAge();
		temp.setMonth();
		
		list.insertLast_2(temp);
	}
	employeeIn.close();
		
	ifstream tempEmplyoyeeIn(TEMP_EMPLOYEE_INFO_FILE_PATH);
	if(!tempEmplyoyeeIn.is_open()){
		cout << "File khong ton tai!" << endl;
		tempEmplyoyeeIn.close();
	}
	TempEmployee eTemp;
	while(tempEmplyoyeeIn >> ebirthDay.dd){
		tempEmplyoyeeIn >> ebirthDay.mm;
		tempEmplyoyeeIn >> ebirthDay.yyyy;
		tempEmplyoyeeIn >> eworkStart.dd;
		tempEmplyoyeeIn >> eworkStart.mm;
		tempEmplyoyeeIn >> eworkStart.yyyy;
		tempEmplyoyeeIn.ignore();
		getline(tempEmplyoyeeIn, ename);
		tempEmplyoyeeIn >> egender;
		tempEmplyoyeeIn.ignore();
		tempEmplyoyeeIn >> ephoneNumber;
		phone_Number.push_back(ephoneNumber);
		
		eTemp.setBirth(ebirthDay);
		eTemp.setStartWork(eworkStart);
		eTemp.setName(ename);
		eTemp.setGender(egender);
		eTemp.setPhoneNumber(ephoneNumber);
		eTemp.setMonth();
		eTemp.setAge();
		list.insertLast_1(eTemp);
	}
	
	tempEmplyoyeeIn.close();
}

void writeManagerDataToFile(Manager list){
	ofstream employeeOut(EMPLOYEE_INFO_FILE_PATH);
	if(!employeeOut.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeOut.close();
	}
	
	for(Node_2 *i = list.head_2; i!=NULL; i=i->next){
		employeeOut << i->data_2.getWage() << endl;
		employeeOut << i->data_2.getUserName() << endl;
		employeeOut << i->data_2.getPassWord() << endl;
		employeeOut << i->data_2.getName() << endl;
		employeeOut << i->data_2.getBirth().dd << endl;
		employeeOut << i->data_2.getBirth().mm << endl;
		employeeOut << i->data_2.getBirth().yyyy << endl;
		employeeOut << i->data_2.getStartWork().dd << endl;
		employeeOut << i->data_2.getStartWork().mm << endl;
		employeeOut << i->data_2.getStartWork().yyyy << endl;
		employeeOut << i->data_2.getPhoneNumber() << endl;
		employeeOut << i->data_2.getGender() << endl;
	}
	employeeOut.close();
	
	ofstream employeeAccountsOut(EMPLOYEE_ACCOUNTS_FILE_PATH);
	if(!employeeAccountsOut.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeAccountsOut.close();
	}
	
	for(Node_2 *i = list.head_2; i!=NULL; i=i->next){
		employeeAccountsOut << i->data_2.getUserName() << endl;
		employeeAccountsOut << i->data_2.getPassWord() << endl;
	}
	
	employeeAccountsOut.close();
	
	ofstream tempEmployeeOut(TEMP_EMPLOYEE_INFO_FILE_PATH);
	if(!tempEmployeeOut.is_open()){
		cout << "File khong ton tai!" << endl;
		tempEmployeeOut.close();
	}
	
	for(Node_1 *i = list.head_1; i!=NULL; i=i->next){
		tempEmployeeOut << i->data_1.getBirth().dd << endl;
		tempEmployeeOut << i->data_1.getBirth().mm << endl;
		tempEmployeeOut << i->data_1.getBirth().yyyy << endl;
		tempEmployeeOut << i->data_1.getStartWork().dd << endl;
		tempEmployeeOut << i->data_1.getStartWork().mm << endl;
		tempEmployeeOut << i->data_1.getStartWork().yyyy << endl;
		tempEmployeeOut << i->data_1.getName() << endl; 
		tempEmployeeOut << i->data_1.getGender() << endl; 
		tempEmployeeOut << i->data_1.getPhoneNumber() << endl; 
	}
	
	tempEmployeeOut.close();
}

void Manager::userList() {
	if(isEmpty_2()) {
		cout<<"Danh sach dang trong "<<endl;
	}else {
		cout<<"Danh sach tai khoan dang nhap: "<<endl;
		for(Node_2 *i = head_2; i != NULL; i =i->next) {
			cout<<"Ten tai khoan: "<<i->data_2.getUserName()<<endl;
			cout<<"Mat khau: "<<i->data_2.getPassWord()<<endl;
		}
	}
}

void  Manager::FindEmployee(){
	char temp_1[100], temp_2[100];
	short dem=0;
	cout<<"Nhap ten cua nhan vien: ";
	fflush(stdin);
	gets(temp_1);
	output_title_2();
	for(Node_2* i=head_2;i!=NULL;i=i->next){
		if(strstr (strupr (strcpy(temp_2,i->data_2.getName().c_str()) ),strupr(temp_1)) ){
		    dem++;
			i->data_2.output();
	    }
	}
	string result =dem==0?"Khong co thong tin trong danh sach":"";	
	cout<<result<<endl;
}
void  Manager::FindTempEmployee(){
	char temp_1[100], temp_2[100];
	short dem =0;
	cout<<"Nhap ten cua nhan vien thu viec: ";
	fflush(stdin);
	gets(temp_1);
	output_title_2();
	for(Node_1* i=head_1;i!=NULL;i=i->next){
		if(strstr (strupr (strcpy(temp_2,i->data_1.getName().c_str())) ,strupr(temp_1)) ){
			i->data_1.output();
			dem++;
		}
	}
	string result =dem==0?"Khong co thong tin trong danh sach":"";
	cout<<result<<endl;
}

Node_1* Manager::FindTelephone_1(){
	string temp;
	short dem=0;
	do {
		cout<<"Nhap so dien thoai: ";
		fflush(stdin);
		getline(cin, temp);
		if(validateString(temp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(temp) == false);
	
	
	for(Node_1* i=head_1;i!=NULL;i=i->next){
		if(strcmp(i->data_1.getPhoneNumber().c_str(),temp.c_str())==0){
			dem++;
			return i;
		}
	}
	if(dem==0){
		return NULL;
	}	
}
Node_2* Manager::FindTelephone_2(){
	string temp;
	short dem=0;
	do {
		cout<<"Nhap so dien thoai: ";
		fflush(stdin);
		getline(cin, temp);
		if(validateString(temp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(temp) == false);
	for(Node_2* i=head_2;i!=NULL;i=i->next){
		if(strcmp(i->data_2.getPhoneNumber().c_str(),temp.c_str())==0){
			dem++;
			return i;
		}
	}
	if(dem==0){
		return NULL;
	}
}

void Manager::ChangeTempEmployee(){
	short choice;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
	do{
		cout<<"1. Sua thong tin\n";
		cout<<"2. Xoa thong tin\n";
		cout<<"0. Thoat\n";
		do {
			cout<<"Nhap lua chon: ";
			tempCheck = validateNumber(checkNumber);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<checkNumber;
		ss>>choice;
		switch(choice){
			case 0:
				break;
			case 1:
			{
				ReplaceTempEmployee();
				choice = 0;
				break;		
			}
			case 2:
			{
				RemoveTempEmployee();
				choice = 0;
				break;
			}
			default: {
				cout<<"Lua chon khong ton tai!"<<endl;
				break;
			}
				
		}
	}while(choice != 0);
	
}
void Manager::ChangeEmployee(){
	short choice;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
	do{
		cout<<"1. Sua thong tin\n";
		cout<<"2. Xoa thong tin\n";
		cout<<"0. Thoat\n";
		do {
			cout<<"Nhap lua chon: ";
			tempCheck = validateNumber(checkNumber);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<checkNumber;
		ss>>choice;
		switch(choice){
			case 0:
				choice = 0;
				break;
			case 1:
			{
				ReplaceEmployee();
				choice = 0;
				break;		
			}
			case 2:
			{
				RemoveEmployee();
				choice = 0;
				break;
			}
			default: {
				cout<<"Lua chon khong ton tai!"<<endl;
				break;
			}
		}
	}while(choice != 0);
	
}

void Manager::ReplaceTempEmployee(){
	short choice;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
	Node_1* i=FindTelephone_1();
	if(i==NULL){
		cout<<"Khong tim thay trong danh sach\n";
	}
	else{
		output_title_2();
		i->data_1.output();
		do{
			do{
				cout<<"1. Sua thong tin\n";
				cout<<"0. Thoat\n";
				do {
		 			cout<<"Nhap lua chon: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>choice;
			}while(choice<0&&choice>1);
			switch(choice){
				case 0:
					cout<<"Thoat khoi chuc nang!"<<endl;
					break;
				case 1:
				{
					short option;
					do{
						cout<<"1. Ten\n";
						cout<<"2. Ngay sinh\n";
						cout<<"3. So dien thoai\n";
						cout<<"0. Thoat"<<endl;
						do {
					 		cout<<"Nhap lua chon: ";
							tempCheck = validateNumber(checkNumber);
							if(tempCheck == false) {
								cout<<"Nhap sai dinh dang"<<endl;
							}
						}while(tempCheck == false);
						ss.clear();
						ss<<checkNumber;
						ss>>option;
						switch(option){
							case 0:
								cout<<"Thoat khoi chuc nang!"<<endl;
								choice = 0;
								break;
							case 1:
							{
								string temp;
								char temp_1;
								do {
									cout<<"Nhap ten: ";
									fflush(stdin);
									getline(cin, temp);
									
									if(validateString(temp) == false) {
										cout<<"Vui long nhap dung dinh dang!"<<endl;
									}
								}while(validateString(temp) == false);
								i->data_1.name = upperCase(temp);
								break;
							}
							case 2:
							{
								Date temp;
						    	cout<<"Nhap lai ngay sinh\n";
						    	temp.inputPerson();
						    	i->data_1.setBirth(temp);
						    	i->data_1.setAge();
								break;
							}
							case 3:
							{
						    	string temp;
						    	bool isDuplicated;
						    	do{
						    		isDuplicated = false;
						    		do {
						    			cout<<"Nhap so dien thoai: ";
										fflush(stdin);
										getline(cin, temp);
										if(validateString(temp) == false) {
											cout<<"Vui long nhap dung dinh dang!"<<endl;
										}
									}while(validateString(temp) == false);
										if(temp.length()!=10){
											cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
											isDuplicated = true;
										}else if(temp[0] != '0'){
										cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
										isDuplicated = true;
										}else{
										for(Node_1* i=head_1;i!=NULL;i=i->next){
						    				if(i->data_1.getPhoneNumber().compare(temp)==0){
						    					isDuplicated=true;
						    					cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
						    					break;
											}		
										}
										for(Node_2* i=head_2;i!=NULL;i=i->next){
						    				if(i->data_2.getPhoneNumber().compare(temp)==0){
						    					isDuplicated=true;
						    					cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
						    					break;
											}		
										}
									}
						    
								}while(isDuplicated);
						    	i->data_1.phoneNumber=temp;
						    	addPhone_Number(phone_Number);
								break;
							}
							
							default:
								cout<<"Lua chon khong ton tai!"<<endl;
								break;
						}
					}while(option != 0);
					break;
				}
				default:
					cout<<"Lua chon khong ton tai!"<<endl;
					break;
			}
		}while(choice !=0);
	}
}
void Manager::RemoveTempEmployee(){
	short dem=0;
	Node_1* i=FindTelephone_1();
	if(i==NULL){
		cout<<"Khong tim thay trong danh sach\n";
	}
	else{
		if(i==head_1){
	        head_1=head_1->next;
	        delete i;
	        dem++;
	        this->size_1--;
        }
        else if(i==tail_1){
	        Node_1* q=head_1;
		    while(q->next->next!=NULL){
			    q=q->next;
		    }
	        tail_1=q;
		    q->next=NULL;
		    delete i;
		    dem++;
		    this->size_1--;
        }
	    else{ 
            Node_1* p=head_1;
            while(p->next==i){
            	p->next=p->next->next;
                i->next=NULL;
                delete i;
                dem++;
                this->size_1--;
			}	
	    }

	}
	string temp = dem!=0?"Da sua thanh cong\n":"";
	cout<<temp<<endl;
	addPhone_Number(phone_Number);
	
}
void Manager::ReplaceEmployee(){
	short choice;
	string checkNumber;
	stringstream ss;
	bool tempCheck;
	Node_2* i=FindTelephone_2();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		output_title_2();
		i->data_2.output();
		do{
			cout<<"1. Sua thong tin ca nhan \n";
			cout<<"2. Sua tai khoan\n";
			cout<<"0. Thoat\n";

			do {
				cout<<"Nhap lua chon: ";
				tempCheck = validateNumber(checkNumber);
				if(tempCheck == false) {
					cout<<"Nhap sai dinh dang"<<endl;
				}
			}while(tempCheck == false);
			ss.clear();
			ss<<checkNumber;
			ss>>choice;
			switch(choice){
				case 0:
					choice = 0;
					break;
				case 1:
				{
						short option;
						do{
							cout<<"1. Ten\n";
							cout<<"2. Ngay sinh\n";
							cout<<"3. So dien thoai\n";
							cout<<"4. Luong\n";
							cout<<"0. Thoat"<<endl;
							do {
								cout<<"Nhap lua chon: ";
								tempCheck = validateNumber(checkNumber);
								if(tempCheck == false) {
									cout<<"Nhap sai dinh dang"<<endl;
								}
							}while(tempCheck == false);
							ss.clear();
							ss<<checkNumber;
							ss>>option;
							switch(option){
								case 0:
									cout<<"Thoat khoi chuc nang!"<<endl;
									break;
								case 1:
								{
									string temp;
									char temp_1;
									do {
										cout<<"Nhap ten: ";
										fflush(stdin);
										getline(cin, temp);
										if(validateString(temp) == false) {
											cout<<"Vui long nhap dung dinh dang!"<<endl;
										}
									}while(validateString(temp) == false);
									i->data_2.name = upperCase(temp);
									break;
								}
								case 2:
								{
							    	Date temp;
							    	cout<<"Nhap lai ngay sinh\n";
							    	temp.inputPerson();
							    	i->data_2.setBirth(temp);
							    	i->data_2.setAge();
									break;
								}
								case 3:
								{
							    	string temp;
							    	bool isDuplicated;
							    	do{
							    		isDuplicated = false;
							    		do {
											cout<<"Nhap so dien thoai: ";
											fflush(stdin);
											getline(cin, temp);
											if(validateString(temp) == false) {
												cout<<"Vui long nhap dung dinh dang!"<<endl;
											}
										}while(validateString(temp) == false);
										if(temp.length()!=10){
											cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
											isDuplicated = true;
										}else if(temp[0] != '0'){
											cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
											isDuplicated = true;
										}else{
											for(Node_1* i=head_1;i!=NULL;i=i->next){
							    			if(i->data_1.getPhoneNumber().compare(temp)==0){
							    				isDuplicated=true;
							    				cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
							    				break;
											}		
										}
										for(Node_2* i=head_2;i!=NULL;i=i->next){
							    			if(i->data_2.getPhoneNumber().compare(temp)==0){
							    				isDuplicated=true;
							    				cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
							    				break;
											}		
										}
									}
							    
									}while(isDuplicated);	
							    	i->data_2.phoneNumber=temp;
							    	addPhone_Number(phone_Number);
									break;
								}
								case 4:
								{
									float temp;
									cout<<"Nhap he so luong: ";
									cin>>temp;
									i->data_2.setWage(temp);
									break;
								}
								default: {
									cout<<"Lua chon khong ton tai!"<<endl;
									break;
								}
							}
						}while(option != 0);
						choice = 0;
						break;
				}
				case 2: {
					string temp;
					short check;
					do {
						do{
							do{
								cout<<"Nhap mat khau: ";
								fflush(stdin);
								getline(cin, temp);
								if(validateString(temp) == false) {
									cout<<"Vui long nhap dung dinh dang!"<<endl;
								}
								if(temp.size()<5)
									cout<<"Nhap lai:\n";
								check = 0;
								for(int i = 0;i<temp.size();i++){
									if(isspace(temp[i]))
										check++;
								}
							}while(check != 0);
						}while(temp.size()<5);
					}while(validateString(temp) == false);
					i->data_2.setPassword(temp);
					choice = 0;
					break;
				}
				default:{
					cout<<"Lua chon khong ton tai!"<<endl;
					break;
				}
			}
		}while(choice != 0);
	}
}
void Manager::RemoveEmployee(){
	short dem=0;
	Node_2* i=FindTelephone_2();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		if(i==head_2){
	        head_2=head_2->next;
	        delete i;
	        dem++;
	        this->size_2--;
        }
        else if(i==tail_2){
	        Node_2* q=head_2;
		    while(q->next->next!=NULL){
			    q=q->next;
		    }
	        tail_2=q;
		    q->next=NULL;
		    delete i;
		    dem++;
		    this->size_2--;
        }
	    else{ 
            Node_2* p=head_2;
            while(p->next==i){
            	p->next=p->next->next;
                i->next=NULL;
                delete i;
                dem++;
                this->size_2--;
			}	
	    }
	}
	string temp = dem!=0?"Da sua thanh cong\n":"";
	cout<<temp<<endl;
	addPhone_Number(phone_Number);
}


