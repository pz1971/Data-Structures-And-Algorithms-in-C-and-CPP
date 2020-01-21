#include <iostream>
#include <iomanip>
#include <string>
#include "trie.hpp"
using   namespace  std ;

int main(){

	trie T ;
	T.insert("xyz") ;
	T.insert("abcd") ;
	T.insert("abc") ;
	T.insert("bc") ;
	T.print() ;

	cout << T.prefixCount("abc") << endl ;
	cout << T.prefixCount("ab") << endl ;

	cout << T.suffixCount("abc") << endl ;
	cout << T.suffixCount("ab") << endl ;

	cout << boolalpha << T.search("pqr") << endl ; 
	cout << T.search("abc") << endl ;
	
	T.remove("abc") ;
	cout <<	T.search("abc") << endl ;

	cout << T.size() << endl ;
	T.clear() ;
	cout << T.empty() << endl ;

	return 0;
}