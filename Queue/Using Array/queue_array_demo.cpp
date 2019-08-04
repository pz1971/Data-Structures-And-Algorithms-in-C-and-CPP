#include <cstdio>
#include <climits>
#include <cstdlib>
#include "queue_array.hpp"

int main(){
    
    queue_array <int> qu;
    
    if(qu.empty()){
        printf("qu is empty\n");
    }
    else{
        printf("qu is not empty\n");
    }

    qu.push(100);
    qu.push(91);

    if(qu.empty()){
        printf("qu is empty\n");
    }
    else{
        printf("qu is not empty\n");
    }

    printf("size of qu = %d\n", qu.size());

    while(!qu.empty()){
        printf("%d\n", qu.front());
        qu.pop();
    }

    printf("%d\n", qu.front());

    return 0;
}