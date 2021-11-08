//
// Created by Xuan Zhai on 2021/11/8.
//

#ifndef SRC_DLLNODE_H
#define SRC_DLLNODE_H
#include <string>

class DLLNode {
    private:

    public:
        DLLNode* next;
        DLLNode* prev;
        std::string data;

        DLLNode();
        DLLNode(const std::string&);
};


#endif //SRC_DLLNODE_H
