#pragma once
#include"person.h"
extern std::vector<string> phone_Number;
//class tempemployee
class TempEmployee {
	protected:
		string name;
		string gender;
		int age;
		Date birth;
		Date startWork;
		string phoneNumber;
		int month;
	public:
		TempEmployee();
		TempEmployee(const TempEmployee& data);
		~TempEmployee();
		string getName();
		string getGender();
		string getPhoneNumber();
		int getAge();
		Date getBirth();
		Date getStartWork();
		int getMonth();
		void setName(string name);
		void setGender(string gender);
		void setAge();
		void setPhoneNumber(string phoneNumber);
		void setBirth(Date birth);
		void setStartWork(Date startWork);
		void setMonth();
		long salary();
		void input();
		void output();
		friend class Manager;
};

