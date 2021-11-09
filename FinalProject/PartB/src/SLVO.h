//
// Created by Xuan Zhai on 2021/11/9.
//

#ifndef SRC_SLVO_H
#define SRC_SLVO_H

#include <fstream>
#include <unordered_map>
#include "DSStack.h"
#include "AdjNode.h"

class SLVO {
    private:
        std::unordered_map<std::string, AdjNode> AdjMap;
        DSStack ColorOrder;
        DLList* DegreeTracker;
        int maxdegree;
        int itemsonTracker;
    public:
        SLVO();
        SLVO(const SLVO&);
        SLVO& operator=(const SLVO&);
        void AddEdge(const int&,const int&);
        void ReadFile(const std::string&);
        ~SLVO();
};


#endif //SRC_SLVO_H
