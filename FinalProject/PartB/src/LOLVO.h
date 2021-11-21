//
// Created by Xuan Zhai on 2021/11/20.
//

#ifndef SRC_LOLVO_H
#define SRC_LOLVO_H
#include "AlgoInterface.h"

class LOLVO : public AlgoInterface {
private:
    DLList* DegreeTracker;
public:
    LOLVO();
    LOLVO(const LOLVO&);
    LOLVO& operator=(const LOLVO&);
    void ReadFile(const std::string&) override;
    void Coloring(const bool&) override;
    ~LOLVO();
};


#endif //SRC_LOLVO_H
