#pragma once
#include<ctime>
#include<iostream>
#include"other.h"
#include"myDrawLib.h"
#include<vector>
#include<iomanip>
#include<string.h>
#include<sstream>
//extern std::vector<string> id_List;
//extern std::vector<int> amount;
//extern std::vector<string> check_id;
// ngay thang nam
typedef struct Date {
//	private:
		int dd;
		int mm;
		int yyyy;
//	public:
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
		void inputPerson();
		void outputDate();
		bool checkExpiryDate();
		friend class Goods;
} Date;
//Ham tra ve ngay hien tai
Date nowDate();
using namespace std;
//Lop hang hoa
class Goods {
	private:
		string name;		//ten hang hoa
		string code;		//ma hang hoa
		string category;	//danh muc
		string status;		//tinh trang
		float discount;		//chiet khau
		long price;		//gia goc
		long priceAfter;	//gia sau khi tru chiet khau
		int number;			//so luong
		Date date;			//ngay san xuat
		int valid;			//han su dung
		Date expiryDate;	//ngay het han
		
	public:
		//friend classes and functions
		friend class ListGoods;
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
		long getPrice();
		void setPrice(long price);
		long getPriceAfter();
		void setPriceAfter(long priceAfter);
		int getNumber();
		void setNumber(int number);
		int getvalid();
		void setvalid(int valid);
		string getStatus();
		void setStatus();
		void setStatusWithData(string status);
		Date getDate();
		void setDate(Date _data);
		Date getExpiryDate();
		void setExpiryDate(Date _data);
		//phuong thuc
		Date updateExpiryDate();
		void input();
		void output(int series);
		friend void outputTitle();
		
		friend void changeString(char a[], string b);
		~Goods();
		int Replace(vector<string> &id_List);
};
//Node hang hoa
class Node {
	public:
	Goods data;
	Node *next;
	//Node();
};
