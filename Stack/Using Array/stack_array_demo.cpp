#include <cstdio>
#include <climits>
#include <cstdlib>
#include "stack_array.hpp"

int main(){
    
    stack_array <int> stk;
    
    if(stk.empty()){
        printf("stk is empty\n");
    }
    else{
        printf("stk is not empty\n");
    }

    stk.push(100);
    stk.push(91);

    if(stk.empty()){
        printf("stk is empty\n");
    }
    else{
        printf("stk is not empty\n");
    }

    printf("size of stk = %d\n", stk.size());

    while(!stk.empty()){
        printf("%d\n", stk.top());
        stk.pop();
    }

    printf("%d\n", stk.top());

    return 0;
}