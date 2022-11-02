#include"listgoods.h"

vector<string> id_List;
int ListGoods::getSize(){
	return size;
}
void ListGoods::setSize(int size) {
	this->size = size;
}

void ListGoods::outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign) {
	if(columns == 0 || rows == 0 || w == 0) return;
	this->insertionSort();
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
Node *ListGoods::getHead() {
	return this->head;
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
	int select,dem,check;
	string selectTemp;
	char temp_1[100],temp_2[100];
	string _temp_1, _temp_2;
	stringstream ss;
	string checkNumber;
	bool tempCheck;
	do{
	cout<<"Lua chon thong tin tim kiem\n";
	cout<<"1. Ten san pham\n";
	cout<<"2. Danh muc\n";
	cout<<"3. Tinh trang\n";
	cout<<"0. Thoat\n";
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
					if(validateString(_temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(_temp_1) == false);
				changeString(temp_1,upperCase(_temp_1));
				check=0;
				dem=0;
				for(Node* i=head;i!=NULL;i=i->next){
					if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
						check++;
					}
				}
				if(check!=0){
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){	
                    if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				}
			    }
			    else{
			    	cout<<"Phan tu can tim ko co trong danh sach\n";
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
					if(validateString(_temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(_temp_1) == false);
				check=0;
				dem=0;
				for(Node* i=head;i!=NULL;i=i->next){
					if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
						check++;
					}
				}
				if(check!=0){
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){
				    if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				    }
				}
				else{
			    	cout<<"Phan tu can tim ko co trong danh sach\n";
				}
				break;
				}
		case 3:
					{
                    int choice,dem_1=0;
                    char temp_1[100]="CON HAN";
                    char temp_2[100]="HET HAN";
                    do{
                    cout<<"1. Con han su dung\n";
                    cout<<"2. Het han su dung\n";
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
						if(choice<1||choice>2)
							cout<<"Vui long chon lai!"<<endl;
                    }while(choice<1||choice>2);
                    switch(choice){
                    	case 1:
                    		check=0;
                    		dem=0;
                    		for(Node* i=head;i!=NULL;i=i->next){
                    			if(strcmp(temp_1,i->data.status.c_str())==0){
                    				check++;
                    			}
							}
							if(check!=0){
                    		outputTitle();
                    		for(Node* i=head;i!=NULL;i=i->next){
                    			dem++;
                    			if(strcmp(temp_1,i->data.status.c_str())==0){
                    				dem_1++;
                    				i->data.output(dem);
								}
						    }
							}
							else{
							cout<<"Phan tu can tim khong co trong danh sach\n";
						}
							break;
						case 2:
							check=0;
							dem=0;
							for(Node* i=head;i!=NULL;i=i->next){
								if(strcmp(temp_2,i->data.status.c_str())==0){
									check++;
								}
							}
							if(check!=0){
							outputTitle();
							for(Node* i=head;i!=NULL;i=i->next){
                    			dem++;
                    			if(strcmp(temp_2,i->data.status.c_str())==0){
                    				dem_1++;
                    				i->data.output(dem);
								}
							}
						}
						else{
							cout<<"Phan tu can tim khong co trong danh sach\n";
						}
							break;
				default:
					cout<<"Khong co lua chon nay\n";
					break;
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
	string temp_1;
	int dem_1 =0,dem_2=0;
    do {
		cout<<"Nhap ma san pham: ";
		fflush(stdin);
		getline(cin,temp_1);
		temp_1 = upperCase(temp_1);
//		changeString(temp_1,upperCase(temp_1));
		if(validateString(temp_1) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(temp_1) == false);
		for(Node* i=head;i!=NULL;i=i->next){
			dem_1++;
            if(strcmp(temp_1.c_str(),i->data.code.c_str())==0){
			    dem_2++;
			    outputTitle();
			    i->data.output(dem_1);
			    return i;
			}	
		}
	if(dem_2==0){
		cout<<"Ma san pham khong co trong danh sach\n";
	    return NULL;
	}
}
Node* ListGoods:: Find_3(string code){
	code = upperCase(code);
	int dem_1 =0,dem_2=0;
	for(Node* i=head;i!=NULL;i=i->next){
			dem_1++;
            if(strcmp(code.c_str(),i->data.code.c_str())==0){
			    dem_2++;
//			    outputTitle();
//			    i->data.output(dem_1);
			    return i;
			}	
		}
	if(dem_2==0){
		cout<<"Ma san pham khong co trong danh sach\n";
	    return NULL;
	}
}
void ListGoods::addCode(vector<string> &id_List){
	for(Node* i=head;i!=NULL;i=i->next){
		id_List.push_back(i->data.getCode());
	}
}
void ListGoods:: Change(vector<string> id_List){
	int option,check,dem;
	Node* i=new Node;
	string checkNumber;
	stringstream ss;
//	do{
	cout<<"\n\nVui long chon phuong thuc ma ban muon thay doi\n";
	cout<<"1. Sua thong tin san pham\n";
	cout<<"2. Xoa san pham\n";
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
				dem=0;
				id_List.clear();
        		i=Find_1();
        		if(i!=NULL){
        		addCode(id_List);
        		check=i->data.Replace(id_List);
        		dem++;
        		if(check==1){
        		    cout<<"Da sua thanh cong\n";
        		break;
        	    }
        	}
		else{
			cout<<"Khong tim thay trong danh sach\n";
			break;
		}
	}
    case 2: {
    	dem=0;
		i=Find_1();
		if(i!=NULL){
		cout<<"Chon 1 de tiep tuc\n";
		cout<<"Chon 0 de thoat\n";
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
			ss>>check;
					
		}while(check<0||check>1);
		if(check==0)
			break;
		else{
		    if(i==head){
	        	head=head->next;
	        	delete i;
	        	dem++;
	        	this->size--;
            	}
            else if(i==tail){
	        	Node* q=head;
		        while(q->next->next!=NULL){
			        q=q->next;
		        }
	        	tail=q;
		        q->next=NULL;
		        delete i;
		        dem++;
		        this->size--;
             	}
	            else{ 
                    Node* p=head;
                    while(p->next==i){
                    	p->next=p->next->next;
                    	i->next=NULL;
                    	delete i;
                    	dem++;
                    	this->size--;
					}	
	            }	
		        cout<<"Danh sach sau khi xoa la:\n";
		     	output ();
		    }
		    break;
	    }  
		else{
		    cout<<"Phan tu can xoa khong co trong danh sach\n";
		    break;
		} 
	    break;
   	}
	default:
		cout<<"Lua chon khong ton tai!"<<endl;  
   }
//}while(option!=0);
}
//Read and Write data to file
// Write and read file
void readDataFromFile(ListGoods &list){
	ifstream inputFile(FILE_PATH);
	string code, name, category, status;
	float discount;
	long price, priceAfter;
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
//	loadingAnimation(68, 2, "Dang doc file...", "Doc file thanh cong!!");
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
void readInvoiceFromFile(ListGoods &list){
	ifstream inputFile(FILE_PATH_2);
	string code, name, category, status, customer_name;
	float discount;
	long price, priceAfter;
	int number, valid;
	Date date, expiryDate;
	Goods temp;
		
	if(!inputFile.is_open()){
		cerr << "Khong the mo File - '" << FILE_PATH_2 << "'" << endl;
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
	endPoint:
	inputFile.close();
	system("cls");
}

void writeInvoiceToFile(ListGoods list) {
	ofstream outputFile(FILE_PATH_2);
	
	int quantity = 0;
	if(!outputFile.is_open()){
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
		quantity++;
	}
	endPoint:
	outputFile.close();	
}
void writeInvoiceToFile_2(ListGoods list) {
	ofstream outputFile(FILE_PATH_2, ios::app);
	
	if(!outputFile.is_open()){
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
void writePastToFile(vector<ListGoods> pastInvoice) {
	ofstream outputFile(FILE_PATH_3, ios::app);
	if(!outputFile.is_open()){
		_getch();
		goto endPoint;
	}
	for(int i = 0; i<pastInvoice.size(); i++) {
		for(Node *j = pastInvoice[i].getHead(); j!= NULL; j=j->next) {
			if(j == pastInvoice[i].getHead()) {
				outputFile << pastInvoice[i].getSize() << "\n";
			}
			outputFile << j->data.getCode() << "\n";
			outputFile << j->data.getName() << "\n";
			outputFile << j->data.getCategory() << "\n";
			outputFile << j->data.getStatus() << "\n";
			outputFile << j->data.getDiscount() << "\n";
			outputFile << j->data.getPrice() << "\n";
			outputFile << j->data.getPriceAfter() << "\n";
			outputFile << j->data.getNumber() << "\n";
			outputFile << j->data.getvalid() << "\n";		
			outputFile << j->data.getDate().getDay()<< "\n";
			outputFile << j->data.getDate().getMonth()<< "\n";
			outputFile << j->data.getDate().getYear()<< "\n";		
			outputFile << j->data.getExpiryDate().getDay()<< "\n";
			outputFile << j->data.getExpiryDate().getMonth()<< "\n";
			outputFile << j->data.getExpiryDate().getYear()<< "\n";
		}
	}
	endPoint:
	outputFile.close();	
}
void writePastToFile_2(vector<ListGoods> pastInvoice) {
	ofstream outputFile(FILE_PATH_3);
	if(!outputFile.is_open()){
		_getch();
		goto endPoint;
	}
	for(int i = 0; i<pastInvoice.size(); i++) {
		outputFile << pastInvoice[i].getSize() << "\n";
		for(Node *j = pastInvoice[i].getHead(); j!= NULL; j=j->next) {
			outputFile << j->data.getCode() << "\n";
			outputFile << j->data.getName() << "\n";
			outputFile << j->data.getCategory() << "\n";
			outputFile << j->data.getStatus() << "\n";
			outputFile << j->data.getDiscount() << "\n";
			outputFile << j->data.getPrice() << "\n";
			outputFile << j->data.getPriceAfter() << "\n";
			outputFile << j->data.getNumber() << "\n";
			outputFile << j->data.getvalid() << "\n";		
			outputFile << j->data.getDate().getDay()<< "\n";
			outputFile << j->data.getDate().getMonth()<< "\n";
			outputFile << j->data.getDate().getYear()<< "\n";		
			outputFile << j->data.getExpiryDate().getDay()<< "\n";
			outputFile << j->data.getExpiryDate().getMonth()<< "\n";
			outputFile << j->data.getExpiryDate().getYear()<< "\n";
		}
	}
	endPoint:
	outputFile.close();	
}
void readPastFromFile(vector<ListGoods> &pastInvoice) {
	ifstream inputFile(FILE_PATH_3);
	ListGoods invoice_list;
	ListGoods toDelete;
	string code, name, category, status, customer_name;
	float discount;
	long price, priceAfter;
	int number, valid,  numberPast;
	Date date, expiryDate;
	Goods temp;
		
	if(!inputFile.is_open()){
		cerr << "Khong the mo File - '" << FILE_PATH_3 << "'" << endl;
		cout << "Nhan phim bat ki de tiep tuc" << endl;
		_getch();
		goto endPoint;
	}
	while(inputFile >> numberPast) {
		invoice_list.setSize(numberPast);
		inputFile.ignore();
		for(int i = 0; i < numberPast; i++) {
			inputFile >> code;
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
			invoice_list.insertLast(temp);
		}
		pastInvoice.push_back(invoice_list);
		invoice_list = toDelete;
	}
	endPoint:
	inputFile.close();
	system("cls");
}

//Ham insertion sort
//Y tuong la ta se tao mot list moi de luu ket qua sau khi xap xep cua list cu
//Ta se dung mot con tro sorted dong vai tro nhu la head cua list moi
void ListGoods::insertionSort() {
	this->sorted = NULL; // khoi tao sorted list ban dau la NULL (giong viec khoi tao con tro head)
	Node* current = this->head; // Tao mot con tro current de luu head hien tai
	
	//vong while se duyet qua tung phan tu ben trong linked list can xap xep
	while(current != NULL){ 
		Node *next = current->next; //tao mot node next mang gia tri cua phan tu tiep theo cua current luc chua thuc hien xap xep
		
		this->sortedInsert(current); // thuc hien xap xep trong ham sortInsert
		
		current = next; // gan lai current bang phan tu tiep theo cua no va tiep tuc chay vong while
	}
	
	this->head = this->sorted;
}

//Day la ham se thuc hien viec xap xep du lieu
void ListGoods::sortedInsert(Node *node){
	// bat truong hop ban dau khi sorted list chua co gi khi sort list = NULL 
	//hoac truong hop node moi co gia tri lon be hon hoac bang node ban dau thi se chen node moi vao dau danh sach
	if(this->sorted == NULL || sorted->data.getPrice() >= node->data.getPrice()){ 
		node->next = sorted;
		this->sorted = node;
	}else{
		// Khoi tao mot node current se mang dia chi cua sorted 
		// day la con tro tam thoi de thuc hien viec xap xep ma khong lam mat du lieu hien tai cua sorted
		Node *current = this->sorted;
		
		// Duyet tu dau den cuoi sorted list
		//Kiem tra xem gia tri cua phan tu trong sorted list co be hon node moi hay khong
		//Neu co se dich current len mot don vi cho den khi gap phan tu co gia tri cua phan tu tiep theo lon hon thi se dung lai
		//Hoac se duyet den cuoi
		//Vi tri ma current dung lai se la vi tri ma ta can chen node moi vao
		while(current->next != NULL && current->next->data.getPrice() < node->data.getPrice()){ 
			current = current->next;
		}
		
		//chen node moi vao sau current
		node->next = current->next;
		current->next = node;
	}
}
