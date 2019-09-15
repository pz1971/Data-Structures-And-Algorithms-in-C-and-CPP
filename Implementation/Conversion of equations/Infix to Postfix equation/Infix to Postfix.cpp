// algorithm:		( collected from: http://csis.pace.edu/~wolf/CS122/infix-postfix.htm )
	// 1. Print operands as they arrive.
	// 2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
	// 3. If the incoming symbol is a left parenthesis, push it on the stack.
	// 4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
	// 5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
	// 6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
	// 7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
	// 8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)


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
			while(precedence_val( ch ) <= precedence_val( charStack.top() )){
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