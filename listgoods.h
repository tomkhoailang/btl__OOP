#pragma once
#include"date_goods.h"
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
#define FILE_PATH_2 "D://fileTest//Invoice.txt"
#define FILE_PATH_3 "D://fileTest//past.txt"
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
		void setSize(int size);
		Node *getHead();
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
		Node* Find_3(string code);
		friend void writeDataToFile(ListGoods list);
		friend void writeInvoiceToFile(ListGoods list);
		friend void writeInvoiceToFile_2(ListGoods list);
		friend void writePastToFile(vector<ListGoods> pastInvoice);
		friend void writePastToFile_2(vector<ListGoods> pastInvoice);
		friend void readPastFromFile(vector<ListGoods> &pastInvoice);
		friend void readDataFromFile(ListGoods &list);
		friend void readInvoiceFromFile(ListGoods &list);
		void Change(vector<string> id_List);
		void addCode(vector<string> &id_List);
		void insertionSort(); // Ham sap xep chen
		void sortedInsert(Node *node); // Ham bo tro cho viec sap xep chen
};

