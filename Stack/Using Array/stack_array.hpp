#ifndef _STACK_ARRAY_HPP
#define _STACK_ARRAY_HPP

#include <iostream>
#include <cstdio>
#include <climits>
#include <cstdlib>

template<typename T>
class stack_array{
private:
    T ar[10000];
    int cur;
public:
    stack_array();
    int size();
    bool empty();
    void push(T elem);
    T top();
    void pop();
};

template<typename T>
stack_array<T>:: stack_array(){
    cur = -1;
}

template<typename T>
int stack_array<T>:: size(){
    return cur + 1;
}

template<typename T>
bool stack_array<T>:: empty(){
    return (cur == -1);
}

template<typename T>
void stack_array<T>:: push(T elem){
    if(cur + 1 >= 10000){
        std:: cerr<< "Program terminated:: *this stack required too much memory."<< std:: endl;
        exit(0);
    }
    
    ar[ ++cur ] = elem;
}

template<typename T>
T stack_array<T>:: top(){
    try{
        if(cur >= 0)
            return ar[cur];
        else{
            throw 0;
        }
    }
    catch(int &ex){
        std::cerr<< "Program terminated:: *this stack is currently empty."<< std:: endl;
        exit(0);
    }
}

template<typename T>
void stack_array<T>:: pop(){
    try{
        if(cur >= 0)
            cur--;
        else{
            throw 0;
        }
    }
    catch(int &ex){
        std::cerr<< "Program terminated:: *this stack is currently empty."<< std:: endl;
        exit(0);
    }
}

#endif