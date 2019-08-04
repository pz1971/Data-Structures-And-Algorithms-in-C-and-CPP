#ifndef _QUEUE_ARRAY_HPP
#define _QUEUE_ARRAY_HPP

#include <iostream>
#include <cstdio>
#include <climits>
#include <cstdlib>

template<typename T>
class queue_array{
private:
    T ar[10000];
    int _front, _back;
public:
    queue_array();
    int size();
    bool empty();
    void push(T elem);
    T front();
    void pop();
};

template<typename T>
queue_array<T>:: queue_array(){
    _front = 0;
    _back = 0;
}

template<typename T>
int queue_array<T>:: size(){
    return (_back - _front);
}

template<typename T>
bool queue_array<T>:: empty(){
    return  (_front == _back);
}

template<typename T>
void queue_array<T>:: push(T elem){
    if(_back >= 10000){
        std:: cerr<< "Program terminated:: *this queue required too much memory."<< std:: endl;
        exit(0);
    }
    
    ar[_back++] = elem;
}

template<typename T>
T queue_array<T>:: front(){
    try{
        if(_front < _back)
            return ar[_front];
        else{
            throw 0;
        }
    }
    catch(int &ex){
        std::cerr<< "Program terminated:: *this queue is currently empty."<< std:: endl;
        exit(0);
    }
}

template<typename T>
void queue_array<T>:: pop(){
    try{
        if(_front < _back)
            _front++;
        else 
            throw 0;
    }
    catch(int &ex){
        std::cerr<< "Program terminated:: *this queue is currently empty."<< std:: endl;
        exit(0);
    }
}

#endif