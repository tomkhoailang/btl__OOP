#include"other.h"

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
//in hoa chuoi
string upperCase(string a){
	for(int i=0; i<a.length(); ++i){
		if(a[i]>='a'&&a[i]<='z')
		a[i]-=32;
	}
	return a;
}
void output_title_2();
void output_title_3();
//kiem tra username
bool checkUser(string &a){
	short n = a.size();
	char x[n+1];
	strcpy(x,a.c_str());
	strlwr(x);
	for(int i = 0; i<n; i++){
		a[i] = x[i];
	}
	if(a.length() < 5)
	return false;
	for(int i = 0; i < a.length(); ++i){
		if(a[i] == ' ')
		return false;
	}
	return true;
}
void changeString(char a[], string b){
			for(int i=0;i<b.length();++i){
				a[i] = b[i];
			}
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
void output_title_2(){
	cout <<			setw(16) << left << "|Ten nhan vien" 		<< "|";
	cout << 		setw(9) << left << "Gioi tinh" 		<< "|";
	cout << 		setw(13) << left << "So dien thoai" 	<< "|";
	cout << 		setw(10) << left << "Ngay sinh" 	<< "|";
	cout << 		setw(10) << left << "Ngay vao lam" 	<< "|";
	cout << 		setw(17) << left << "So thang lam viec" 	<< "|";
	cout << 		setw(11) << left << "He so luong" 	<< "|";
	cout << 		setw(12) << left << "Luong co ban" 	<< "|";
	cout << 		setw(12) << left << "Luong thang" 	<< "|";
	cout << 		setw(11) << left << "Ghi chu" 	<< "|";
	cout<<endl;
}
void output_title_3(){
	cout <<			setw(21) << left << "|Tai khoan" 		<< "|";
	cout << 		setw(20) << left << "Mat khau" 		<< "|" << endl;
}

