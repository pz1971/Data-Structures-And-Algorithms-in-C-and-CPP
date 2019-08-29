#include <iostream>
#include "stack_list.hpp"

using namespace std ;

int main(){

	stack_list<int> ST ;
	
	cout<< boolalpha << ST.empty()<< endl;	// true
	
	ST.push(5) ;
	ST.push(2) ;
	ST.push(4) ;
	ST.push(9) ;
	ST.push(7) ;

	cout<< ST.empty() << endl;	// false
	cout<< ST.size() << endl; 	// 5

	while(!ST.empty()){
		cout<< ST.top() << " ";
		ST.pop() ;
	}							// 7 9 4 2 5

	cout<< endl << ST.size()<< endl ; 	// 0 ;

	return 0 ;
}