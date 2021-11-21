//
// Created by Xuan Zhai on 2021/11/19.
//

#include "DSQueue.h"


void DSQueue::Pushback(const int& newstring){
    linkedlist.PushBack(newstring);
}


void DSQueue::PopFront(){
    linkedlist.PopFront();
}


int DSQueue::Peek(){
    return linkedlist.GetHead()->data;
}


bool DSQueue::isEmpty(){
    return linkedlist.isEmpty();
}