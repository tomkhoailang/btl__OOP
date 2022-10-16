#include"temp_employee.h"
extern vector<string> user_Name;
#pragma once
	//clas employee
class Employee: public Person, public TempEmployee {
	private:
		static int id;
		float wage;
	public:
		Employee();
		~Employee();
		Employee(const Employee& data);
		float getWage();
		void setWage();
		void setWage(float wage);
		void input();
		void output();
		void outputUser();
		long salary();
		friend class Manager;
};
	


