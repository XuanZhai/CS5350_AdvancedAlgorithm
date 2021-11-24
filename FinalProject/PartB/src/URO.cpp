//
// Created by Xuan Zhai on 2021/11/13.
//

#include "URO.h"

using namespace std;


URO::URO(){
    AdjMap = nullptr;
    nvertices = 0;
    nColorUsed = 1;
    Verticesleft = nullptr;
}


URO::URO(const URO& newalgo){
    nvertices = newalgo.nvertices;
    AdjMap = new AdjNode[nvertices];
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    nColorUsed = newalgo.nColorUsed;
    Verticesleft = newalgo.Verticesleft;
    filename = newalgo.filename;
}


URO::~URO(){
    delete[] Verticesleft;
}


URO& URO::operator=(const URO& newalgo){
    AdjMap = new AdjNode[nvertices];
    nvertices = newalgo.nvertices;
    for(int i = 0; i < nvertices; i++){
        AdjMap[i] = newalgo.AdjMap[i];
    }
    nColorUsed = newalgo.nColorUsed;
    Verticesleft = newalgo.Verticesleft;
    filename = newalgo.filename;
    return *this;
}



// Time Complexity Theta(V+E)
void URO::ReadFile(const std::string& newfilename) {
    filename = newfilename;
    ifstream inputfile(filename);                       // Open a file
    if(!inputfile){
        cout << "Error in loading file" << endl;
        exit(1);
    }

    inputfile >> nvertices;                 // Read the number of vertices

    AdjMap = new AdjNode[nvertices];        // Create a dictionary of adjacent nodes
    Verticesleft = new int[nvertices];

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
        Verticesleft[i] = i;
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
        AdjMap[i].nodeonlist = nullptr;         // make adjNode's pointer points to it
    }

    delete[] indexdict[0];          // Delete the start index for each node
    delete[] indexdict[1];          // Delete the number of degree for each vertex
}


// Time complexity O(V+E)
void URO::Coloring(const bool& isPrint){
    int nverremain = nvertices;             // How many vertices are not colored
    int totaloriginaldegree = 0;
    int selectedsize = 0;
    ofstream outputfile;
    if(isPrint){
        outputfile.open("out_"+filename);
    }

    while (nverremain != 0){                // While not all been selected
        int selindex = rand()%nverremain;       // Randomly pick one that's unselected
        int selected = Verticesleft[selindex];
        Verticesleft[selindex] = Verticesleft[nverremain-1];  // Delete it in the array
        int newcolor = ColoraVertex(selected);          // Find a color for it
        AdjMap[selected].color = newcolor;

        totaloriginaldegree += AdjMap[selected].degree;
        selectedsize++;
        if(isPrint) {
            cout << "Coloring: " << selected << ". The color is " << newcolor << "; Original Degree is: " << AdjMap[selected].degree << "." << endl;
            outputfile << selected << ", " << newcolor << endl;
        }
        nverremain--;
    }
    if(isPrint) {
        outputfile.close();
        cout << "\n=====================================" << endl;
        cout << "Total number of colors used: " << nColorUsed + 1 << endl;
        cout << "The average Original degree: " << totaloriginaldegree / selectedsize << endl;
        cout << "=====================================" << endl;
    }
}