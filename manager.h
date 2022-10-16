#include"employee.h"
#define EMPLOYEE_ACCOUNTS_FILE_PATH "D://fileTest//EmployeeAcounts.txt"
#define EMPLOYEE_INFO_FILE_PATH "D://fileTest//EmployeeInfo.txt"
#define TEMP_EMPLOYEE_INFO_FILE_PATH "D://fileTest//TempEmployeeInfo.txt"
#define MANAGER_FILE_PATH "D://fileTest//Manager.txt"
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
		Manager();
		~Manager();
		int getSize_1();
		int getSize_2();
		Node_1 *makeNode_1();
		Node_2 *makeNode_2();
		bool isEmpty_1();
		bool isEmpty_2();
		void insertLast_1();
		void insertLast_2();
		void output_1();
		void output_2();
		void output_User();
		void userList();
		Node_1 *makeNode_1(const TempEmployee& data);
		Node_2 *makeNode_2(const Employee& data);
		void insertLast_1(const TempEmployee& data);
		void insertLast_2(const Employee& data);
		Employee getEmployeeByUserName(string username);
		friend void writeManagerDataToFile(Manager list);
		friend void readManagerDataFromFile(Manager &list);
		void FindEmployee();
		void FindTempEmployee();
		Node_1* FindTelephone_1();
		Node_2* FindTelephone_2();
		void ChangeTempEmployee();
		void ChangeEmployee();
		void ReplaceTempEmployee();
		void ReplaceEmployee();
		void RemoveTempEmployee();
		void RemoveEmployee();
		void addPhone_Number(vector<string> &phone_Number);
};
