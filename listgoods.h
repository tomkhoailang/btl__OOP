#include"dategoods.h"
#include"myDrawLib.h"
#include<fstream>
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
class ListGoods {
	private: 
		int size;
		Node *head;
		Node *tail;
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
};
void readDataFromFile(ListGoods &list);
void writeDataToFile(ListGoods list);

