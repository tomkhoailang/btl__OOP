#include"listgoods.h"
//class menu
class Menu{
	private:
		int x, y;
		string title;
		vector<string> menuContent;
		int numberOfMenuItem;
		int padding;
		int targetLength;
	public:
		Menu(int x, int y, vector<string> _menuContent, string title);
		~Menu(){};
		void printMenu(const string& title, const string& textAlign, int padding);
		void setPadding(int padding);
		void setTargetLength(int length);
		int GetItemAmount();
		void clearMenuScreen();
		void start(ListGoods list);
};

