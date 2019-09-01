#include <cstdio>
#include <cstdlib>
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

	stack_list<char> charStack ;
	charStack.push('(') ;
	char ch ;
	
	while( true ){
		ch = getchar() ;
		
		if(ch == ' ')
			continue ;				// ignoring whitespaces
		else if(ch == '\n')
			break ;					// end of output
		
		else if(ch == '('){
			charStack.push( ch ) ;
		}
		else if(ch == ')'){						// popping till opening parentheses
			while(charStack.top() != '('){
				putchar( charStack.top() ) ;
				charStack.pop() ;
			}
			charStack.pop() ;
		}

		else if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
			putchar(ch) ;		// operand
		}

		else if(precedence_val( ch ) > precedence_val( charStack.top() )){
			charStack.push( ch ) ;
		}

		else{
			while(precedence_val( ch ) < precedence_val( charStack.top() )){
				putchar( charStack.top() ) ;
				charStack.pop() ;
			}
			charStack.push( ch ) ;
		}
	}
	
	while(charStack.size() > 1) {		// emptying stack...
		putchar( charStack.top() ) ;
		charStack.pop() ;
	}
	putchar('\n') ;

	charStack.clear() ;

	return 0 ;
}