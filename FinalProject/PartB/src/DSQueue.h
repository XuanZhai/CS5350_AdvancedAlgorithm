//
// Created by Xuan Zhai on 2021/11/19.
//

#ifndef SRC_DSQUEUE_H
#define SRC_DSQUEUE_H
#include "DLList.h"


class DSQueue {
    private:
        DLList linkedlist;
    public:
        void Pushback(const int&);
        void PopFront();
        int Peek();
        bool isEmpty();
};


#endif //SRC_DSQUEUE_H
