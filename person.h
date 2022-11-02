#include<string>
#include"listgoods.h"
extern std::vector<ListGoods> pastInvoice;
using namespace std;
class Person {
	protected:
		string username;
		string password;
	public:
		Person();
		~Person();
		string getUserName();
		string getPassWord();
		void setUserName(string username);
		void setPassword(string password);
		void calculation(ListGoods list);
};
