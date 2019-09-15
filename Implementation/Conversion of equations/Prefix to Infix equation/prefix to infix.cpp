// Algorithm for Prefix to Infix:	( collected from: https://www.geeksforgeeks.org/prefix-infix-conversion/ )

//	1.	Read the Prefix expression in reverse order (from right to left)
// 	2.	If the symbol is an operand, then push it onto the Stack
// 	3.	If the symbol is an operator, then pop two operands from the Stack
// 			Create a string by concatenating the two operands and the operator between them.
// 			string = (operand1 + operator + operand2)
// 			And push the resultant string back to Stack
// 	4.	Repeat the above steps until end of Prefix expression.

#include <iostream>
#include <algorithm>
#include <string>
#include "stack_list.hpp"		// provided in "stack/Using Linked List" folder

bool is_operator(char ch){
	return ( ch == '+' ||
			 ch == '-' ||
			 ch == '*' || 
			 ch == '/' || 
			 ch == '^' ) ;
}

int main(){

	stack_list<std:: string> infixStack ;

	std:: string input ;
	getline(std::cin, input) ;
	reverse(input.begin(), input.end()) ;
	
	std:: string x , y ;

	for(const char ch : input){
		if(!is_operator(ch)){
			x.clear() ;
			x.push_back(ch) ;
			infixStack.push(x) ;
		}
		else{
			if(infixStack.size() < 2){
				std:: cerr << "Error : Invalid input" << std:: endl ;
				exit(0) ;
			}
			else{
				x = infixStack.top() ;
				infixStack.pop() ;

				y = infixStack.top() ;
				infixStack.pop() ;

				infixStack.push( "(" + x + ch + y + ")" ) ;
			}
		}
	}

	if(infixStack.size() != 1){
		std:: cerr << "Error : Invalid input" << std:: endl ;
		exit(0) ;
	}
	else{
		std:: cout << infixStack.top() << std:: endl ;
		infixStack.pop() ;
	}

	infixStack.clear() ;

	return 0 ;
}