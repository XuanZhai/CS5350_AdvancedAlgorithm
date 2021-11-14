//
// Created by Xuan Zhai on 2021/11/8.
//

#include "DLLNode.h"


DLLNode::DLLNode(){
    prev = nullptr;
    next = nullptr;
}

DLLNode::DLLNode(const int& newData){
    data = newData;
    prev = nullptr;
    next = nullptr;
}


void DLLNode::SelfDelete(){
    if(prev != nullptr && next != nullptr) {
        prev->next = next;
        next->prev = prev;
    }
    else if(next != nullptr){
        next->prev = nullptr;
    }
    else if(prev != nullptr){
        prev->next = nullptr;
    }
    prev = nullptr;
    next = nullptr;
}