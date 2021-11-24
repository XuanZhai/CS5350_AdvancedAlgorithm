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
    return *this;
}


DLList::~DLList(){
    while (size != 0){
        this->PopBack();
    }
}


void DLList::PushBack(const int& newint){
    DLLNode* newnode = new DLLNode(newint);
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
        newnode->next = nullptr;
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


void DLList::PushFront(const int& newint){
    DLLNode* newnode = new DLLNode(newint);
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
    if(size == 1){
        int b =0;
    }

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
        iter = head->next;
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



int DLList::GetSize(){
    return size;
}


void DLList::DecreSize() {
    size--;
}


void DLList::DeleteNode(DLLNode*& oldnode){
    if(oldnode->prev != nullptr && oldnode->next != nullptr) {      // It means it's in the middle
        oldnode->prev->next = oldnode->next;
        oldnode->next->prev = oldnode->prev;
    }
    else if(oldnode->prev == nullptr && oldnode->next == nullptr){
        head = nullptr;
        tail = nullptr;
        iter = nullptr;
    }
    else if(oldnode->next != nullptr){              // Means it's the head
        head = oldnode->next;
        iter = oldnode->next;
        oldnode->next->prev = nullptr;
    }
    else if(oldnode->prev != nullptr){                       // Means it's the tail
        tail = oldnode->prev;
        oldnode->prev->next = nullptr;
    }
    oldnode->prev = nullptr;
    oldnode->next = nullptr;
    size--;
}