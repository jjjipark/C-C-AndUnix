#include <string>
#include "student.hpp"


Student::Student(){
	cout << "Student object default constructor" << endl;
}


Student::Student(string first, string last, int age){

	setFirstName(first);
	setLastName(last);
	setAge(age);

	cout << "Student object constructor:" << endl;
}

Student::~Student(){
	

	count << "Student oabject destructor: " << endl;
}


bool Student::setFirstName(string first){
}

bool Student::setLastName(string last){
}

bool Student::setAge(int age){
	if (age >0) {
		return true;
	}
	return false;
}

string Student::getFirstName(string first){

	return firstname;
}
string Student::getLastName(string last){
	return lastname;
}

string Student::getAge(int age){
	return age;
}

Student::print(){

	cout << firstname << lastname << age;
}



