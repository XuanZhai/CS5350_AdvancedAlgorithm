//
// Created by Xuan Zhai on 2021/11/20.
//

#include "LOLVO.h"

using namespace std;

LOLVO::LOLVO(){
    AdjMap = nullptr;
    DegreeTracker = nullptr;
    nvertices = 0;
    nColorUsed = 1;
}


LOLVO::LOLVO(const LOLVO& newalgo){
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }


    DegreeTracker = new DLList[newalgo.nvertices];
    for(int i = 0; i < nvertices-1; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    nvertices = newalgo.nvertices;
    nColorUsed = newalgo.nColorUsed;
    filename = newalgo.filename;
}


LOLVO& LOLVO::operator=(const LOLVO& newalgo){
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    delete[] DegreeTracker;
    DegreeTracker = new DLList[newalgo.nvertices];
    for(int i = 0; i < nvertices-1; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    nvertices = newalgo.nvertices;
    nColorUsed = newalgo.nColorUsed;
    filename = newalgo.filename;
    return *this;
}


LOLVO::~LOLVO(){
    delete[] DegreeTracker;
}


// Time Complexity Theta(V+E)
void LOLVO::ReadFile(const std::string& newfilename) {
    filename = newfilename;
    ifstream inputfile(filename);                       // Open a file
    if(!inputfile){
        cout << "Error in loading file" << endl;
        exit(1);
    }

    inputfile >> nvertices;                 // Read the number of vertices
    DegreeTracker = new DLList[nvertices];     // Create an array for tracking the degree
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
        DegreeTracker[AdjMap[i].degree].PushBackP(newnode);        // Add that node to the tracker.
    }

    delete[] indexdict[0];          // Delete the start index for each node
    delete[] indexdict[1];          // Delete the number of degree for each vertex
}


void LOLVO::Coloring(const bool& isPrint){      // Same algorithm as what in SOLVO, only loop through the table
    int totaloriginaldegree = 0;
    int stacksize = 0;                  // It's the number of colored vertices
    int trackerlevel =0;                // It's the level in the degree table
    ofstream outputfile;
    if(isPrint){
        outputfile.open("out_"+filename);
    }

    while (stacksize != nvertices){         // Loop through each node on the degree table
        if(DegreeTracker[trackerlevel].isEmpty()){
            trackerlevel++;                 // If at that level there's no vertex, go to the next level
        }
        else{
            DLLNode* temp = DegreeTracker[trackerlevel].GetHead();      // Loop through that level
            while (temp != nullptr){
                int selected = temp->data;                      // Get a vertex
                int newcolor = ColoraVertex(selected);          // Find a color for it
                AdjMap[selected].color = newcolor;
                if(isPrint) {
                    totaloriginaldegree += AdjMap[selected].degree;
                    cout << "Coloring: " << selected << ". The color is " << newcolor << "; Original Degree is: " << AdjMap[selected].degree << "." << endl;
                    outputfile << temp << ", " << newcolor << endl;
                }
                stacksize++;
                temp = temp->next;
            }
            trackerlevel++;
        }
    }
    if(isPrint) {
        outputfile.close();
        cout << "\n=====================================" << endl;
        cout << "Total number of colors used: " << nColorUsed + 1 << endl;
        cout << "The average Original degree: " << totaloriginaldegree / stacksize << endl;
        cout << "=====================================" << endl;
    }
}