//
// Created by Xuan Zhai on 2021/11/20.
//

#include "AlgoInterface.h"

// Time Complexity Theta(1)
void AlgoInterface::AddEdge(const int& src,const int& dest){
    AdjMap[src].children.PushBack(dest);
    AdjMap[src].currentdegree++;
    AdjMap[src].degree++;
}

// Time Complexity O(V)
int AlgoInterface::ColoraVertex(const int& index){
    bool* colormap = new bool[nvertices]{false};            // A list of color checker
    DLLNode* tempi = AdjMap[index].children.head;
    while (tempi != nullptr){
        if(AdjMap[tempi->data].color != -1){
            colormap[AdjMap[tempi->data].color] = true;     // Go through neighbours and check which colors are used.
        }
        tempi = tempi->next;
    }

    for(int i = 0; i < AdjMap[index].children.GetSize()+1; i++){
        if(!colormap[i]){                           // Starts from 0, check which color is not used.
            if(i > nColorUsed){
                nColorUsed = i;                     // Update the number of colors used if necessary
            }
            delete[] colormap;
            return i;
        }
    }
    printf("No color found");
    delete[] colormap;
    return nColorUsed;
}


AlgoInterface::~AlgoInterface(){
    delete[] AdjMap;
}