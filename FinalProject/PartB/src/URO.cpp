//
// Created by Xuan Zhai on 2021/11/13.
//

#include "URO.h"

using namespace std;


URO::URO(){
    AdjMap = nullptr;
    nvertices = 0;
}


URO::URO(const URO& newalgo){
    nvertices = newalgo.nvertices;
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    ColorOrder = newalgo.ColorOrder;
}


URO::~URO(){
    delete[] AdjMap;
}


URO& URO::operator=(const URO& newalgo){
    AdjMap = new AdjNode[nvertices];
    nvertices = newalgo.nvertices;
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    ColorOrder = newalgo.ColorOrder;
    return *this;
}



// Time Complexity Theta(2V+E)
void URO::ReadFile(const std::string& filename) {
    ifstream inputfile(filename);                       // Open a file
    if(!inputfile){
        cout << "Error in loading file" << endl;
        exit(1);
    }

    inputfile >> nvertices;                 // Read the number of vertices

    AdjMap = new AdjNode[nvertices];        // Create a dictionary of adjacent nodes

    int* indexdict[2];

    indexdict[0] = new int[nvertices];          // The start index for each node
    indexdict[1] = new int[nvertices];          // The number of degree for each vertex


    for(int i = 0; i < nvertices; i++){
        int currentn = 0;
        inputfile >> currentn;                  // Read a pointer from input file

        indexdict[0][i] = currentn;
        if(i != 0){
            indexdict[1][i-1] = (currentn - indexdict[0][i-1]);     // Find the number of degree for each vertex
        }
        AdjNode newNode;
        newNode.data = i;       // Add a degree to the dictionary
        AdjMap[i] = newNode;
    }
    indexdict[1][nvertices-1] = -1;       // # We don't know the number of degree for the last vertex, so set to -1

    int destv = 0;
    for (int i = 0; i < nvertices-1; i++){          // For each vertex except the last one
        for(int j = 0; j < indexdict[1][i]; j++){       // If it has an edge
            inputfile >> destv;                     // Add that edge.
            AddEdge(i,destv);
        }
    }

    while (inputfile >> destv){                 // Add all the edges for the last vertex
        AddEdge(nvertices-1,destv);
    }

    for(int i = 0; i < nvertices; i++){
        DLLNode* newnode = new DLLNode(i);      // Create a node for it
        AdjMap[i].nodeonlist = newnode;         // make adjNode's pointer points to it
    }

    delete[] indexdict[0];          // Delete the start index for each node
    delete[] indexdict[1];          // Delete the number of degree for each vertex
}


// Time Complexity Theta(1)
void URO::AddEdge(const int& src,const int& dest){
    AdjMap[src].children.PushBack(dest);         // Present
    AdjMap[src].currentdegree++;
    AdjMap[src].degree++;
}


void URO::Coloring(){
    int noncolored = nvertices;
    srand( (unsigned)time(NULL) );
    while (noncolored != 0){
        int chosenindex = rand()%noncolored;

    }
}