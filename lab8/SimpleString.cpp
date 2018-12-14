#include "SimpleString.hpp"

// Include any other header files as necessary


// Define and implement the SimpleString class methods in this file…

// The 2 constructors are defined for you:

SimpleString::SimpleString() {
    this->input = "Default value";
}

SimpleString::SimpleString(std::string s) {
    this->input = s;
}

// TODO: Define the getter/setter and operator overloading methods…



//void SimpleString::getString(){
//	return s;
//}

//void SimpleString::setString(std::string s){
//	input = s;
//}

SimpleString& SimpleString::operator=(const SimpleString &s){
	input = s.input;
	return *this;
}

SimpleString SimpleString::operator+(const SimpleString &s){
	input.append(s.input);
	return *this;
}

SimpleString& SimpleString::operator++(){
	this->input.push_back(this->input);
	return *this;
}

SimpleString& SimpleString::operator--(){
	this -> input.pop_back(this->input);
	return *this;
}







