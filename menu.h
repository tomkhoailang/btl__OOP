#include"manager.h"
//class menu
class Menu {
	protected:
		int x, y;
		string title;
	public:
		Menu(int x, int y, string title);
		~Menu();
};

class ListMenu: public Menu{
	private:
		vector<string> menuContent;
		int numberOfMenuItem;
		int padding;
		int targetLength;
	public:
		ListMenu(int x, int y, vector<string> _menuContent, string title);
		~ListMenu(){};
		void printMenu(const string& title, const string& textAlign, int padding);
		void setPadding(int padding);
		void setTargetLength(int length);
		int GetItemAmount();
		void clearMenuScreen();
		void start(ListGoods &list, string role, Manager &managerList, string info);
};

class LoginMenu: public Menu{
	private:
		string username;
		string role;
	public:
		LoginMenu(int x, int y, string title);
		~LoginMenu();
		string getRole();
		void setRole(string role);
		string getUsername();
		void printLoginMenu();
		bool startLoginMenu();
};

