//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_DLLIST_H
#define SRC_DLLIST_H
#include "DLLNode.h"
#include <iostream>

class DLList {
    private:
        int size;
    public:
        DLLNode* head;
        DLLNode* tail;
        DLLNode* iter;
        DLList();
        DLList(const DLList&);
        DLList& operator=(const DLList&);
        ~DLList();

        void PushBack(const int&);
        void PushBackP(DLLNode*);
        void PopBack();
        bool isEmpty();
        void PushFront(const int&);
        void PushFrontP(DLLNode*);
        void PopFront();
        void PrintList();

        DLLNode* GetHead();
        DLLNode* GetTail();
        DLLNode* GetIter();
        int GetSize();
        void DecreSize();
        void DeleteNode(DLLNode*&);
};


#endif //SRC_DLLIST_H
