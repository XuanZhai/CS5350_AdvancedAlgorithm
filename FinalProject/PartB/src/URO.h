//
// Created by Xuan Zhai on 2021/11/13.
//

#ifndef SRC_URO_H
#define SRC_URO_H
#include "AlgoInterface.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>


class URO : public AlgoInterface {
    private:
        int* Verticesleft;                  // A integer array that tracking unselected vertices

    public:
        URO();
        URO(const URO&);
        ~URO();
        URO& operator=(const URO&);
        void ReadFile(const std::string&) override;
        void Coloring(const bool&) override;
};


#endif //SRC_URO_H
