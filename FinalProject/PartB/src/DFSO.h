//
// Created by Xuan Zhai on 2021/11/19.
//

#ifndef SRC_DFSO_H
#define SRC_DFSO_H
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "DSStack.h"
#include "AlgoInterface.h"

class DFSO : public AlgoInterface{
private:
    int* Verticesleft;                  // A list of uncolored vertices

public:
    DFSO();
    DFSO(const DFSO&);
    ~DFSO();
    DFSO& operator=(const DFSO&);
    void ReadFile(const std::string&) override;
    void Coloring(const bool&) override;
};


#endif //SRC_DFSO_H
