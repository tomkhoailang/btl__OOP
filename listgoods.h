#pragma once
#include"date_goods.h"
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
extern std::vector<string> id_List;
// Danh sach hang hoa
class ListGoods {
	private: 
		int size;
		Node *head;
		Node *tail;
		Node *sorted; // list luu ket qua sau khi xap xep chen
	public:
		ListGoods();
		int getSize();
		Node *makeNode();
		Node *makeNode(Goods data);
		bool isEmpty();
		void output();
		void outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign);
		void insertLast();
		void insertLast(Goods data);
		bool checkCode(string code);
		~ListGoods();
		void Find_2();
		Node* Find_1();
		friend void writeDataToFile(ListGoods list);
		friend void readDataFromFile(ListGoods &list);
		void Change(vector<string> id_List);
		void addCode(vector<string> &id_List);
		void insertionSort(); // Ham sap xep chen
		void sortedInsert(Node *node); // Ham bo tro cho viec sap xep chen
};

