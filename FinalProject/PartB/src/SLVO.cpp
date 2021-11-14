//
// Created by Xuan Zhai on 2021/11/9.
//

#include "SLVO.h"

using namespace std;

SLVO::SLVO(){
    AdjMap = nullptr;
    DegreeTracker = nullptr;
    maxdegree = 0;
    itemsonTracker = 0;
    maxdeletedegree = 0;
    cumOriginalDegree = 0;
    nColorUsed = 0;
}


SLVO::SLVO(const SLVO& newalgo){
    AdjMap = new AdjNode[maxdegree+1];
    for(int i = 0; i < maxdegree+1; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }


    ColorOrder = newalgo.ColorOrder;
    DegreeTracker = new DLList[newalgo.maxdegree+1];
    for(int i = 0; i < maxdegree; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    maxdegree = newalgo.maxdegree;
}


SLVO& SLVO::operator=(const SLVO& newalgo){
    AdjMap = new AdjNode[maxdegree+1];
    for(int i = 0; i < maxdegree+1; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    ColorOrder = newalgo.ColorOrder;
    delete[] DegreeTracker;
    DegreeTracker = new DLList[newalgo.maxdegree+1];
    for(int i = 0; i < maxdegree; i++){
        DegreeTracker[i] = newalgo.DegreeTracker[i];
    }
    maxdegree = newalgo.maxdegree;
    return *this;
}


SLVO::~SLVO(){
    delete[] AdjMap;
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
    DegreeTracker = new DLList[maxdegree+1];     // Create an array for tracking the degree
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
        cumOriginalDegree += AdjMap[i].degree;
    }

    delete[] indexdict[0];          // Delete the start index for each node
    delete[] indexdict[1];          // Delete the number of degree for each vertex
}


// Time Complexity Theta(1)
void SLVO::AddEdge(const int& src,const int& dest){
    AdjMap[src].children.PushBack(dest);         // Present
    AdjMap[src].currentdegree++;
    AdjMap[src].degree++;
}


void SLVO::Coloring() {

    int currindex = 0;
    while (itemsonTracker != 0){
        if(!DegreeTracker[currindex].isEmpty()){                    // Check if the current level is empty
            int itempicked = DegreeTracker[currindex].GetHead()->data;      // Get the first number

//            cout << "============================" << endl;
//            for(int j = 0; j < 20; j++){
//                cout << j << " is: " << DegreeTracker[j].GetSize() << endl;
//                if(!DegreeTracker[j].isEmpty()){
//                    DegreeTracker[j].PrintList();
//                }
//            }
//            cout << "---------------------------\n" << endl;

            DegreeTracker[currindex].PopFront();                    // Remove the first number
            itemsonTracker--;
            AdjMap[itempicked].isdeleted = true;                    // Mark deleted
            AdjMap[itempicked].degreewhendelete = AdjMap[itempicked].currentdegree; // Get the degreewhendeleted

            if(AdjMap[itempicked].degreewhendelete > maxdeletedegree){
                maxdeletedegree = AdjMap[itempicked].degreewhendelete;
            }

            AdjMap[itempicked].nodeonlist = nullptr;                // The node is no longer on the list

            AdjMap[itempicked].children.iter = AdjMap[itempicked].children.head;    // For each of his children
            ColorOrder.Pushback(itempicked);

            while (AdjMap[itempicked].children.iter != nullptr){
                int child = AdjMap[itempicked].children.iter->data;
                if(!AdjMap[child].isdeleted) {
                    DegreeTracker[AdjMap[child].currentdegree].DeleteNode(AdjMap[child].nodeonlist);
                    AdjMap[child].currentdegree--;
                    DegreeTracker[AdjMap[child].currentdegree].PushBackP(AdjMap[child].nodeonlist);

                }
                AdjMap[itempicked].children.iter = AdjMap[itempicked].children.iter->next;
            }
            if(currindex != 0) {
                currindex--;
            }
        }
        else{
            currindex++;
        }
    }
}


void SLVO::PrintResult() {
    cout << "Result is: ";
    while (!ColorOrder.isEmpty()){
        int temp = ColorOrder.Peek();
        cout << temp << " ";
        ColorOrder.Popback();
    }
    cout << " " << endl;
}