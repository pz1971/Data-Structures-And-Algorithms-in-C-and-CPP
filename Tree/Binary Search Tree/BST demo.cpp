#include <iostream>
#include "bst.hpp"

using namespace std ;

int main(){

	bst<int> myBST ;
	myBST.insert(3) ;
	myBST.insert(1) ;
	myBST.insert(5) ;

	myBST.print(myBST.root) ;
	cout << endl ;
	// cout <<myBST.root->data << endl ;
	// cout << myBST.root->left->data << endl ;
	// cout << myBST.root->right->data << endl ;
	cout << myBST.size() << endl ;
	
	cout << endl  ;
	cout << endl  ;

	int ar[] = {3, 2, 1, 5, 4} ;
	bst<int> myBST2 ;
	cout << boolalpha << myBST2.empty() << endl ;
	myBST2.insert(ar, 5) ;
	myBST2.print(myBST2.root) ;
	cout << endl ;
	cout <<  myBST2.size() << endl ;
		
	cout << myBST2.search(4) << " " << myBST2.search(7) << endl ;
	
	
	myBST2.erase(3) ;
	myBST2.print(myBST2.root) ;
	cout << endl ;
	
	myBST2.clear( myBST2.find(1) ) ;
	myBST2.print(myBST2.root) ;
	cout << endl ;
	
	myBST2.clear(myBST2.root) ;
	cout  <<  myBST2.size() << endl ;

	return 0 ;
}