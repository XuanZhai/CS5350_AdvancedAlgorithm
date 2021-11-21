//
// Created by Xuan Zhai on 2021/11/9.
//

#ifndef SRC_SLVO_H
#define SRC_SLVO_H

#include "AlgoInterface.h"
#include "DSStack.h"

class SLVO : public AlgoInterface{
    private:
        DSStack ColorOrder;
        DLList* DegreeTracker;
        int terminalclique;
        int itemsonTracker;
    public:
        SLVO();
        SLVO(const SLVO&);
        SLVO& operator=(const SLVO&);
        void ReadFile(const std::string&) override;
        void FindOrder();
        void Coloring(const bool&) override;
        ~SLVO();
};


#endif //SRC_SLVO_H
