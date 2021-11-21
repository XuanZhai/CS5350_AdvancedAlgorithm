//
// Created by Xuan Zhai on 2021/11/19.
//

#ifndef SRC_BFSO_H
#define SRC_BFSO_H
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "AlgoInterface.h"
#include "DSQueue.h"

class BFSO : public AlgoInterface {
private:
    int* Verticesleft;

public:
    BFSO();
    BFSO(const BFSO&);
    ~BFSO();
    BFSO& operator=(const BFSO&);
    void ReadFile(const std::string&) override;
    void Coloring(const bool&) override;
};


#endif //SRC_BFSO_H
