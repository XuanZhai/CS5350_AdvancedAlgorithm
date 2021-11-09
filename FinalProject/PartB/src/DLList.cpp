//
// Created by Xuan Zhai on 2021/11/8.
//

#include "DLList.h"

using namespace std;

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


void DLList::PushBack(const std::string& newstring){
    DLLNode* newnode = new DLLNode(newstring);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
        iter = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }
    size++;
}


void DLList::PushBackP(DLLNode* newnode){
    if(head == nullptr){
        head = newnode;
        tail = newnode;
        iter = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }
    size++;
}


void DLList::PopBack(){
    if(tail == nullptr)
        return;
    else if(tail == head){
        delete head;
        tail = nullptr;
        head = nullptr;
        iter = nullptr;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    size--;
}


bool DLList::isEmpty(){
    if(size == 0)
        return true;
    return false;
}


void DLList::PushFront(const std::string& newstring){
    DLLNode* newnode = new DLLNode(newstring);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
        iter = newnode;
    }
    else{
        head->prev = newnode;
        newnode = head;
    }
    size++;
}


void DLList::PushFrontP(DLLNode *newnode) {
    if(head == nullptr){
        head = newnode;
        tail = newnode;
        iter = newnode;
    }
    else{
        head->prev = newnode;
        newnode = head;
    }
    size++;
}


void DLList::PopFront(){
    if(head == nullptr){
        return;
    }
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        iter = nullptr;
    }
    else{
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    size--;
}

DLLNode* DLList::GetHead(){
    return head;
}


DLLNode* DLList::GetTail(){
    return tail;
}


DLLNode* DLList::GetIter(){
    return iter;
}


void DLList::PrintList() {
    DLLNode* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}