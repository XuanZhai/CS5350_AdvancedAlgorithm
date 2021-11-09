//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_DLLIST_H
#define SRC_DLLIST_H
#include "DLLNode.h"
#include <iostream>

class DLList {
    private:
        DLLNode* head;
        DLLNode* tail;
        DLLNode* iter;
        int size;
    public:
        DLList();
        DLList(const DLList&);
        DLList& operator=(const DLList&);
        ~DLList();

        void PushBack(const std::string&);
        void PushBackP(DLLNode*);
        void PopBack();
        bool isEmpty();
        void PushFront(const std::string&);
        void PushFrontP(DLLNode*);
        void PopFront();

        void PrintList();

        DLLNode* GetHead();
        DLLNode* GetTail();
        DLLNode* GetIter();
};


#endif //SRC_DLLIST_H
