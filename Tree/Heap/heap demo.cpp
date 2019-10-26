#include <iostream>
#include "heap.hpp"

using namespace std ;

int main(){

	heap<int> myHeap(100) ;
	
	myHeap.insert(50) ;
	myHeap.insert(7) ;
	myHeap.insert(20) ;
	myHeap.insert(30) ;
	myHeap.insert(14) ;
	myHeap.insert(9) ;
	myHeap.insert(20) ;

	cout << boolalpha<< myHeap.empty() << endl ;
	cout << myHeap.size() << endl ;
	cout << myHeap.max_size() << endl ;

	while(!myHeap.empty()){
		cout << myHeap.top() << " " ;
		myHeap.pop() ;
	}
	cout << endl ;
	cout << endl ;

	int ar[] = {7, 6, 1, 3, 2, 5, 4} ;
	heapSort(ar, 7) ;
	for(int i = 0 ; i < 7 ; i++)
		cout << ar[i] << " " ;
	cout << endl ;

	return 0 ;
}