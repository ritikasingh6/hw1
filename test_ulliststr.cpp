#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr list1;

	// push back

	list1.push_back("a");
	list1.push_back("b");
	list1.push_back("c");
	list1.push_back("d");
	list1.push_back("e");

	cout << "Push back" << endl;
	cout << "Should print out 'a b c d e'" << endl;
	for (int i = 0; i < 5; i++){
		std:: cout << list1.get(i) << " ";
	}
	cout << "" << endl;

	// pop back
	list1.pop_back();
	list1.pop_back();
	cout << "Pop back" << endl;
	cout << "Should print out 'a b c' " << endl;
	for (int i = 0; i < 3; i++){
		std:: cout << list1.get(i) << " ";
	}
	cout << "" << endl;

	//push front
	list1.push_front("1");
	list1.push_front("2");
	cout << "Push front" << endl;
	cout << "Should print out '2 1 a b c' " << endl;
	for (int i = 0; i < 5; i++){
		std:: cout << list1.get(i) << " ";
	}
	cout << "" << endl;

	// pop front
	list1.pop_front();
	list1.pop_front();
	cout << "Pop front" << endl;
	cout << "Should print out 'a b c' " << endl;
	for (int i = 0; i < 3; i++){
		std:: cout << list1.get(i) << " ";
	}
	cout << "" << endl;




	
}
