//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_DSSTACK_H
#define SRC_DSSTACK_H
#include "DLList.h"

class DSStack {
    private:
        DLList linkedlist;
    public:
        void Pushback(const int&);
        void Popback();
        int Peek();
        bool isEmpty();
};


#endif //SRC_DSSTACK_H
