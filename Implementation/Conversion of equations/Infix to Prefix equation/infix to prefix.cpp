// algorithm :
// 1.  get expression
// 2.  reverese the expression (including parentheses)
// 3.  run usual algorithm of infix to postfix conversion
// 4.  reverse the output expression 
// 5.  end

#include <iostream>
#include <algorithm>
#include "stack_list.hpp"		// provided in "stack/Using Linked List" folder

int precedence_val(const char ch){
	if(ch == '+' || ch == '-')
		return 1 ;
	if(ch == '*' || ch == '/' || ch == '%')
		return 2 ;
	if(ch == '^')
		return 3 ;
	return 0 ;		// for others
}

int main(){

	std:: string input, output ;
    getline(std::cin, input) ;
    
    reverse(input.begin(), input.end()) ;
	for(char &ch : input){
		if(ch == '(')
			ch = ')' ;
		else if(ch == ')')
			ch = '(' ;
	}
    
    stack_list<char> charStack ;
	charStack.push('(') ;
	
	for(const char ch : input){
		
		if(ch == ' ')
			continue ;				// ignoring whitespaces
		else if(ch == '\n')
			break ;					// end of output
		
		else if(ch == '('){
			charStack.push( ch ) ;
		}
		else if(ch == ')'){						// popping till opening parentheses
			while(charStack.top() != '('){
                output.push_back( charStack.top() ) ;
				charStack.pop() ;
			}
			charStack.pop() ;
		}

		else if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
			output.push_back(ch) ;		// operand
		}

		else if(precedence_val( ch ) > precedence_val( charStack.top() )){
			charStack.push( ch ) ;
		}

		else{
			while(precedence_val( ch ) <= precedence_val( charStack.top() )){
                output.push_back( charStack.top() ) ;
				charStack.pop() ;
			}
			charStack.push( ch ) ;
		}
	}
	
	while(charStack.size() > 1) {		// emptying stack...
		putchar( charStack.top() ) ;
		charStack.pop() ;
	}

	charStack.clear() ;

    reverse(output.begin(), output.end()) ;
    std:: cout << output << std:: endl ;

	return 0 ;
}