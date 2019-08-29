#include <iostream>
#include <iomanip>
#include "linked_list.hpp"

using namespace std;

int main(){

	linked_list<int> myList;

	cout<< boolalpha << myList.empty() << endl ; // true ;

	myList.insert_front(5) ;
	myList.insert_front(7) ;
	myList.insert_front(3) ;

	cout<< boolalpha << myList.empty() << endl ; // false ;
	
	myList.insert_back(0) ;
	myList.insert_back(8) ;
	myList.insert_back(4) ;

	myList.print_list();	// 3 7 5 0 8 4

	cout<< myList.size()<< endl;	// 6

	cout<< myList.front()<< endl;	// 3
	cout<< myList.back()<< endl;	// 4

	myList.insert_at(3, 11) ;
	myList.print_list() ;

	myList.erase_front() ;
	cout<< myList.front() << endl;	// 7
	myList.erase_back() ;
	cout<< myList.back() << endl;	// 8
	myList.erase_at(2) ;
	myList.print_list() ;	// 7 5 0 8

	cout<< myList.size() << endl ; // 4
	cout<< myList.at(2) << endl;	// 0
	cout<< myList[1] << endl; 	// 5
	
	myList.clear();
	cout<< myList.empty() << endl ; // true 

	myList.insert_at(0, 1000) ;
	cout<< myList.front() << endl;	// 1000 ;

	exit(0) ;
	return 0;
}
