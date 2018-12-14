#include <iostream>
#include <random>
#include <vector>


int main(){
	std::vector<int> v;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,100);

	for (int i=0; i<15; ++i) {
		int number = distribution(generator);
		v.push_back (number);

	}
	for (std::vector<int>::const_iterator it = v.begin() ; it != v.end(); ++it)
		std::cout << ' ' << *it;
	
	std::cout << '\n';
	return 0;
}
