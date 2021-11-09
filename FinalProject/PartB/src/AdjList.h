//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H
#include "AdjNode.h"
#include <string>

class AdjList {
private:
    AdjNode* head;
    AdjNode* tail;
    AdjNode* iter;
    int size;
public:
    AdjList();
    AdjList(const AdjList&);
    AdjList& operator=(const AdjList&);
    ~AdjList();

    void PushBack(const std::string&);
    void PopBack();
    bool isEmpty();
    void PushFront(const std::string&);
    void PopFront();

    void PrintList();

    AdjList* GetHead();
    AdjList* GetTail();
    AdjList* GetIter();
};


#endif //SRC_ADJLIST_H
