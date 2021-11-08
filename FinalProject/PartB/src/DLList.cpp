//
// Created by Xuan Zhai on 2021/11/8.
//

#include "DLList.h"

DLList::DLList(){
    head = nullptr;
    tail = nullptr;
    iter= nullptr;
    size = 0;
}

DLList::DLList(const DLList& newList){
    head = nullptr;
    tail = nullptr;
    DLLNode* temp = newList.head;
    while (temp != nullptr){
        this->PushBack(temp->data);
        temp = temp->next;
    }
    iter = head;
    size = newList.size;
}


DLList& DLList::operator=(const DLList& newList){
    head = nullptr;
    tail = nullptr;
    DLLNode* temp = newList.head;
    while (temp != nullptr){
        this->PushBack(temp->data);
        temp = temp->next;
    }
    iter = head;
    size = newList.size;
    return *this;
}


DLList::~DLList(){
    while (size != 0){
        this->PopBack();
    }
}


void DLList::PushBack(const std::string&){

}


void DLList::PopBack(){

}


DLLNode* DLList::GetHead(){

}


DLLNode* DLList::GetTail(){

}


DLLNode* DLList::GetIter(){

}