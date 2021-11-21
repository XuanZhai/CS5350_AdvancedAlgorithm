//
// Created by Xuan Zhai on 2021/11/20.
//

#ifndef SRC_ALGOINTERFACE_H
#define SRC_ALGOINTERFACE_H
#include <fstream>
#include "AdjNode.h"

class AlgoInterface {               // Super class
private:

public:
    AdjNode* AdjMap;
    int nvertices;
    int nColorUsed;
    std::string filename;
    virtual void ReadFile(const std::string&) = 0;
    void AddEdge(const int&,const int&);
    int ColoraVertex(const int&);
    virtual void Coloring(const bool&) = 0;
    virtual ~AlgoInterface();
};


#endif //SRC_ALGOINTERFACE_H
