//
// Created by Xuan Zhai on 2021/11/8.
//

#include "DLLNode.h"


DLLNode::DLLNode(){
    prev = nullptr;
    next = nullptr;
}

DLLNode::DLLNode(const std::string& newData){
    data = newData;
    prev = nullptr;
    next = nullptr;
}
