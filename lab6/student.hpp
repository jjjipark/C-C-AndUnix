#ifndef __STUDENT_CPP
#define __STUDENT_CPP

#include <string>

class Student{
	Student();

	Student(string first, string last, int age);
		~Employee();					
	public:

	bool setFirstName(string first);
	bool setLastName(string last);
	bool setAge(int age);
	
	string getFirstName();
	string getLatName();
	int getAge();

	private:

	string firstname;
	string lastname;
	int age;

}:

#endif

