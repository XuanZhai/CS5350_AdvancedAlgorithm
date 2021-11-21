#include <iostream>
#include "SLVO.h"
#include "URO.h"
#include "BFSO.h"
#include "DFSO.h"
#include "SOLVO.h"
#include "LOLVO.h"
#include "AlgoInterface.h"


int main() {

    AlgoInterface* Algos[6];
    Algos[0] = new SLVO;
    Algos[1] = new URO;
    Algos[2] = new SOLVO;
    Algos[3] = new LOLVO;
    Algos[4] = new BFSO;
    Algos[5] = new DFSO;

    for(auto& Algo:Algos){
        Algo->ReadFile("Complete.txt");
        Algo->Coloring(true);
    }
//    newLOLVO.ReadFile("graph.txt");
//    newLOLVO.Coloring(true);


    for(auto & Algo : Algos){
        delete Algo;
    }

    return 0;
}
