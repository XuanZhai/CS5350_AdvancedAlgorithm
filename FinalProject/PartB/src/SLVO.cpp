//
// Created by Xuan Zhai on 2021/11/9.
//

#include "SLVO.h"

using namespace std;

SLVO::SLVO(){
    AdjMap = nullptr;
    DegreeTracker = nullptr;
    nvertices = 0;
    itemsonTracker = 0;
    terminalclique = 0;
    nColorUsed = 1;
}


SLVO::SLVO(const SLVO& newalgo){
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }


    ColorOrder = newalgo.ColorOrder;
    DegreeTracker = new DLList[newalgo.nvertices];
    for(int i = 0; i < nvertices-1; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    nvertices = newalgo.nvertices;
    terminalclique = newalgo.terminalclique;
    nColorUsed = newalgo.nColorUsed;
    itemsonTracker = newalgo.itemsonTracker;
    filename = newalgo.filename;
}


SLVO& SLVO::operator=(const SLVO& newalgo){
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    ColorOrder = newalgo.ColorOrder;
    delete[] DegreeTracker;
    DegreeTracker = new DLList[newalgo.nvertices];
    for(int i = 0; i < nvertices-1; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    nvertices = newalgo.nvertices;
    terminalclique = newalgo.terminalclique;
    nColorUsed = newalgo.nColorUsed;
    itemsonTracker = newalgo.itemsonTracker;
    filename = newalgo.filename;
    return *this;
}


SLVO::~SLVO(){
    delete[] DegreeTracker;
}


// Time Complexity Theta(V+E)
void SLVO::ReadFile(const std::string& newfilename) {
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
        itemsonTracker++;
    }

    delete[] indexdict[0];          // Delete the start index for each node
    delete[] indexdict[1];          // Delete the number of degree for each vertex
}


// Time complexity Theta(V+E)
void SLVO::FindOrder() {

    int currindex = 0;

    while (itemsonTracker != 0){
        if(!DegreeTracker[currindex].isEmpty()){                    // Check if the current level is empty
            if(itemsonTracker == currindex +1 && itemsonTracker > terminalclique){
                terminalclique = itemsonTracker;                    // We got the terminal clique
            }

            int itempicked = DegreeTracker[currindex].GetHead()->data;      // Get the first number

            DegreeTracker[currindex].PopFront();                    // Remove the first number
            itemsonTracker--;
            AdjMap[itempicked].isdeleted = true;                    // Mark deleted
            AdjMap[itempicked].degreewhendelete = AdjMap[itempicked].currentdegree; // Get the degreewhendeleted

            AdjMap[itempicked].nodeonlist = nullptr;                // The node is no longer on the list

            AdjMap[itempicked].children.iter = AdjMap[itempicked].children.head;    // For each of his children
            ColorOrder.Pushback(itempicked);

            while (AdjMap[itempicked].children.iter != nullptr){
                int child = AdjMap[itempicked].children.iter->data;
                if(!AdjMap[child].isdeleted) {                          // Delete that child in the current level
                    DegreeTracker[AdjMap[child].currentdegree].DeleteNode(AdjMap[child].nodeonlist);
                    AdjMap[child].currentdegree--;      // Move to next level
                    DegreeTracker[AdjMap[child].currentdegree].PushBackP(AdjMap[child].nodeonlist);
                }
                AdjMap[itempicked].children.iter = AdjMap[itempicked].children.iter->next;
            }
            if(currindex != 0) {
                currindex--;            // Next time starts with the upper level.
            }
        }
        else{
            currindex++;            // If empty, go to the next level.
        }
    }
}


// Time complexity Theta(V+E)
void SLVO::Coloring(const bool& isPrint){
    FindOrder();
    int totaloriginaldegree = 0;
    int stacksize = 0;
    int maximumdegree_deleted = -1;
    ofstream outputfile;
    if(isPrint){
        outputfile.open("out_"+filename);
    }

    while (!ColorOrder.isEmpty()){          // Pop the ordering list
        int temp = ColorOrder.Peek();
        int newcolor = ColoraVertex(temp);      // For each popped vertex, make a color for them.
        AdjMap[temp].color = newcolor;

        totaloriginaldegree += AdjMap[temp].degree;
        stacksize++;
        if(AdjMap[temp].degreewhendelete > maximumdegree_deleted){
            maximumdegree_deleted = AdjMap[temp].degreewhendelete;
        }
        if(isPrint) {
            cout << "Coloring: " << temp << ". The color is " << newcolor << "; Original Degree is: " << AdjMap[temp].degree << "; Degree when deleted is: " << AdjMap[temp].degreewhendelete << endl;
            outputfile << temp << ", " << newcolor << endl;
        }
        ColorOrder.Popback();
    }

    outputfile.close();
    if(isPrint) {
        cout << "\n=====================================" << endl;
        cout << "Total number of colors used: " << nColorUsed + 1 << endl;
        cout << "The average Original degree: " << totaloriginaldegree / stacksize << endl;
        cout << "The Maximum degree when deleted: " << maximumdegree_deleted << endl;
        cout << "The size of terminal clique: " << terminalclique << endl;
        cout << "=====================================" << endl;
    }
}