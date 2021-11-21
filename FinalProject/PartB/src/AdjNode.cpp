//
// Created by Xuan Zhai on 2021/11/8.
//

#include "AdjNode.h"


AdjNode::AdjNode(){
    data = -1;
    degree = 0;
    currentdegree = 0;
    degreewhendelete = 0;
    color = -1;
    isdeleted = false;
    nodeonlist = nullptr;
}