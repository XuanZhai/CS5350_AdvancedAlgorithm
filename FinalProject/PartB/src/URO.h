//
// Created by Xuan Zhai on 2021/11/13.
//

#ifndef SRC_URO_H
#define SRC_URO_H
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "DSStack.h"
#include "AdjNode.h"

class URO {
    private:
        AdjNode* AdjMap;
        DSStack ColorOrder;
        int nvertices;
    public:
        URO();
        URO(const URO&);
        ~URO();
        URO& operator=(const URO&);
        void ReadFile(const std::string&);
        void AddEdge(const int&,const int&);
        void Coloring();
};


#endif //SRC_URO_H
