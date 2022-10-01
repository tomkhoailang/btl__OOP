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
