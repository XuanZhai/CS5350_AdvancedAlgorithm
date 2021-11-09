//
// Created by Xuan Zhai on 2021/11/9.
//

#include "SLVO.h"

using namespace std;

SLVO::SLVO(){
    DegreeTracker = nullptr;
    maxdegree = 0;
    itemsonTracker = 0;
}


SLVO::SLVO(const SLVO& newalgo){
    AdjMap = newalgo.AdjMap;
    ColorOrder = newalgo.ColorOrder;
    DegreeTracker = new DLList[newalgo.maxdegree];
    for(int i = 0; i < maxdegree; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    maxdegree = newalgo.maxdegree;
}


SLVO& SLVO::operator=(const SLVO& newalgo){
    AdjMap = newalgo.AdjMap;
    ColorOrder = newalgo.ColorOrder;
    delete[] DegreeTracker;
    DegreeTracker = new DLList[newalgo.maxdegree];
    for(int i = 0; i < maxdegree; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    maxdegree = newalgo.maxdegree;
}


SLVO::~SLVO(){
    delete[] DegreeTracker;
}


// Time Complexity Theta(2V+E)
void SLVO::ReadFile(const std::string& filename) {
    ifstream inputfile(filename);                       // Open a file
    if(!inputfile){
        cout << "Error in loading file" << endl;
        exit(1);
    }

    int nvertices = 0;
    inputfile >> nvertices;                 // Read the number of vertices
    maxdegree = nvertices-1;                    // maxdegree is the maximum number degree a vertex can have
    DegreeTracker = new DLList[maxdegree];     // Create an array for tracking the degree

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
        newNode.name = std::to_string(i);       // Add a degree to the dictionary
        std::pair<std::string,AdjNode> newPair (newNode.name,newNode);
        AdjMap.insert(newPair);
    }
    indexdict[1][nvertices-1] = -1;       // # We don't know the number of degree for the last vertex, so set to -1

    //for(int i =0 ;i < nvertices; i++){
    //    cout << "start: " <<indexdict[0][i] << " number of degree: " << indexdict[1][i] << endl;
   // }

    int destv = 0;
    for (int i = 0; i < nvertices-1; i++){          // For each vertex except the last one
        for(int j = 0; j < indexdict[1][i]; j++){       // If it has an edge
            inputfile >> destv;                     // Add that edge.
            AddEdge(i,destv);
           // cout << "Add: "<< i << " and " << destv << endl;
        }
    }

    while (inputfile >> destv){                 // Add all the edges for the last vertex
        AddEdge(nvertices-1,destv);
        //cout << "Add: "<< nvertices-1 << " and " << destv << endl;
    }


    std::unordered_map<std::string, AdjNode>::iterator it = AdjMap.begin();
    while(it != AdjMap.end())      // Loop through each item in the dictionary
    {
        DLLNode* newnode = new DLLNode(it->first);      // Create a node for it

        it->second.nodeonlist = newnode;            // make adjNode's pointer points to it
        DegreeTracker[it->second.degree].PushBackP(newnode);        // Add that node to the tracker.
        itemsonTracker++;
        it++;
    }

}


// Time Complexity Theta(1)
void SLVO::AddEdge(const int& source,const int& destination){
    string src = std::to_string(source);
    string dest = std::to_string(destination);
    if (AdjMap.find(src) == AdjMap.end()){
        cout << "Key not found" << endl;
        exit(1);
    }
    AdjMap.at(src).children.PushBack(dest);         // Present
    AdjMap.at(src).currentdegree++;
    AdjMap.at(src).degree++;
}