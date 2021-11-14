//
// Created by Xuan Zhai on 2021/11/9.
//

#ifndef SRC_SLVO_H
#define SRC_SLVO_H

#include <fstream>
#include "DSStack.h"
#include "AdjNode.h"

class SLVO {
    private:
        AdjNode* AdjMap;
        DSStack ColorOrder;
        DLList* DegreeTracker;
        int maxdegree;
        int maxdeletedegree;
        int cumOriginalDegree;
        int nColorUsed;
        int itemsonTracker;
    public:
        SLVO();
        SLVO(const SLVO&);
        SLVO& operator=(const SLVO&);
        void AddEdge(const int&,const int&);
        void ReadFile(const std::string&);
        void Coloring();
        void PrintResult();
        ~SLVO();
};


#endif //SRC_SLVO_H
