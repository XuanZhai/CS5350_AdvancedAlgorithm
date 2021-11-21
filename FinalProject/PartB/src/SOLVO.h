//
// Created by Xuan Zhai on 2021/11/19.
//

#ifndef SRC_SOLVO_H
#define SRC_SOLVO_H

#include "AlgoInterface.h"

class SOLVO : public AlgoInterface {
private:
    DLList* DegreeTracker;              // We need a Degree Tracker to find the degrees for each vertex

public:
    SOLVO();
    SOLVO(const SOLVO&);
    SOLVO& operator=(const SOLVO&);
    void ReadFile(const std::string&) override;
    void Coloring(const bool&) override;
    ~SOLVO();
};


#endif //SRC_SOLVO_H
