#include <iostream>
#include "queue_list.hpp"

using namespace std ;

int main(){

	queue_list<int> Q ;
	
	cout<< boolalpha << Q.empty()<< endl;	// true
	
	Q.push(5) ;
	Q.push(2) ;
	Q.push(4) ;
	Q.push(9) ;
	Q.push(7) ;

	cout<< Q.empty() << endl;	// false
	cout<< Q.size() << endl; 	// 5

	while(!Q.empty()){
		cout<< Q.front() << " ";
		Q.pop() ;
	}							// 5 2 4 9 7

	cout<< endl << Q.size()<< endl ; 	// 0 ;

	return 0 ;
}