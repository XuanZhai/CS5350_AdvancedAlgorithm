//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_ADJNODE_H
#define SRC_ADJNODE_H
#include <iostream>
#include "DLList.h"


class AdjNode {
    private:

    public:
        int data;
        int degree;
        int color;
        int currentdegree;
        int degreewhendelete;
        bool isdeleted;

        DLLNode* nodeonlist;
        DLList children;

        AdjNode();

};


#endif //SRC_ADJNODE_H
