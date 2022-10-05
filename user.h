class Person {
	protected:
		string username;
		string password;
		string defaultName;
	public:
		Person();
		~Person();
		string getUserName();
		string getPassWord();
		string getDefaultName();
		void setUserName(string username);
		void setPassword(string password);
		void setDefaultName(string name);
		void calculation(ListGoods list);
		
};
//class tempemployee
class TempEmployee {
	protected:
		string name;
		string gender;
		Date date;
		int month;
	public:
		TempEmployee();
		~TempEmployee();
		string getName();
		string getGender();
		Date getDate();
		int getMonth();
		void setName(string name);
		void setGender(string gender);
		void setDate(Date date);
		void setMonth(int month);
		void salary();
		void input();
		void output();
};
//clas employee
class Employee: public Person, public TempEmployee {
	private:
		string name;
		string gender;
		Date date;
		float salary;
	public:
		Employee();
		~Employee();
		void input();
		void output();
		
};
//Node nhan vien
struct Node_1{
	TempEmployee data_1;
	Node_1 *next;
};
struct Node_2 {
	Employee data_2;
	Node_2 *next;
};
//class manager
class Manager: public Person {
	private:
		int size_1;
		int size_2;
		//TempEmployee
		Node_1 *head_1;
		Node_1 *tail_1;
		//Employee
		Node_2 *head_2;
		Node_2 *tail_2;
	public:
	
		
};
