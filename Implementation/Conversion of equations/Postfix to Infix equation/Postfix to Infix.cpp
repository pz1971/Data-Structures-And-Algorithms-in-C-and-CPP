// algorithm:		collected from :	http://scanftree.com/Data_Structure/postfix-to-infix
	// 1.While there are input symbol left
	// 2.	Read the next symbol from input.
	// 3.	If the symbol is an operand 
	// 		Push it onto the stack.
	// 4.	Otherwise, 
	// 		the symbol is an operator.
	// 5.	If there are fewer than 2 values on the stack
	// 		Show Error /* input not sufficient values in the expression */
	// 6.	Else 
	// 		Pop the top 2 values from the stack.
	// 		Put the operator, with the values as arguments and form a string.
	// 		Encapsulate the resulted string with parenthesis.
	// 		Push the resulted string back to stack.
	// 7.	If there is only one value in the stack
	// 		That value in the stack is the desired infix string.
	// 8.	If there are more values in the stack
	// 		Show Error /* The user input has too many values */

#include <iostream>
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
	
	std:: string x , y ;

	for(const char ch : input){
		if(! is_operator(ch) ){			// ch is an operand
			x.clear() ;
			x.push_back(ch) ;		// converting to a string
			infixStack.push(x) ;	// pushing to the stack
		}
		else{							// ch is an operator
			if(infixStack.size() < 2){
				std:: cerr << "Error : invalid input" << std:: endl ;
				exit(0) ;
			}
			else{
				y = infixStack.top() ;
				infixStack.pop() ;

				x = infixStack.top() ;
				infixStack.pop() ;
				
				if(ch == '*' || ch == '/'){
					if(x.size() > 1)
						x = '(' + x + ')' ;
					if(y.size() > 1)
						y = '(' + y + ')' ;
				}

				infixStack.push(x + ch + y) ;
			}
		}
	}

	if(infixStack.size() > 1){
		std:: cerr << "Error : invalid input//input has too many values" << std:: endl ;
		exit(0) ;
	} 
	else{
		std:: cout << infixStack.top() << std:: endl ;
		infixStack.pop() ;
	}

	infixStack.clear() ;

	return 0 ;
}