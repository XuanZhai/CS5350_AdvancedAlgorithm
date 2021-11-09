//
// Created by Xuan Zhai on 2021/11/8.
//

#include "DSStack.h"

void DSStack::Pushback(std::string newstring){
    linkedlist.PushBack(newstring);
}


void DSStack::Popback(){
    linkedlist.PopBack();
}


std::string DSStack::Peek(){
    return linkedlist.GetTail()->data;
}


bool DSStack::isEmpty(){
    return linkedlist.isEmpty();
}
