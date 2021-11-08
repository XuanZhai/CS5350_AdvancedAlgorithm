from os import close
import random
import time



Nvertices = 0
Nedge = 0
Gtype = ""
Dtype = ""


# Reference: https://www.pythonpool.com/adjacency-list-python/
adj_list = {}


def ClearList():                        # Delete an adj list
    adj_list.clear()


def InitList(v):
    for i in range(v):
        temp = []
        adj_list[i] = temp


def add_edge(node1, node2, weight):       
    adj_list[node1].append([node2,weight])
    adj_list[node2].append([node1,weight])


def CompleteGraph(v):
    InitList()
    for i in range(v):
        for j in range(i,v):
            if(i != j):
                add_edge(i,j,1)


def CycleGraph(v):
    InitList(v)
    for i in range(v-1):
        add_edge(i,i+1,1)
    add_edge(v-1,0,1)


def RandomGraphS(v,e):
    if e < 0 or e > v*(v-1)/2:
        print("Invalid number of edges")
        return
    
    InitList(v)
    totalpossibility = int((1+ (v-1)+(v-2)) * ((v-1)+(v-2)) /2)  # Find the total number of choice

    vertexpair = {}
    for i in range(v):
        for j in range(i,v):
            if(i != j):
                if i+j in vertexpair.keys():
                    vertexpair[i+j].append([i,j])
                else:
                    vertexpair[i+j] = []
                    vertexpair[i+j].append([i,j])
    
    numofedge = 0

    while numofedge != e:
        newindex = random.randint(1,totalpossibility)
        loc = 0
        while newindex > 0:
            if loc in vertexpair and len(vertexpair[loc]) != 0:
                newindex = newindex - (2*(v-1)-loc)
            loc += 1
        loc -= 1
        cindex = random.randint(0,len(vertexpair[loc])-1)
        add_edge(vertexpair[loc][cindex][0],vertexpair[loc][cindex][1],1)

        temp = vertexpair[loc][cindex]
        vertexpair[loc][cindex] = vertexpair[loc][len(vertexpair[loc])-1]
        vertexpair[loc][len(vertexpair[loc])-1] = temp
        vertexpair[loc].pop()          
        if len(vertexpair[loc]) == 0:
            totalpossibility -= (2*(v-1)-loc)
        numofedge += 1


def RandomGraphG(v,e):
    if e < 0 or e > v*(v-1)/2:
        print("Invalid number of edges")
        return
    
    InitList(v)
    totalpossibility = (1+(v-2))*(v-2) + (v-1)
   
    vertexpair = {}
    for i in range(v):
        for j in range(i,v):
            if(i != j):
                if i+j in vertexpair.keys():
                    vertexpair[i+j].append([i,j])
                else:
                    vertexpair[i+j] = []
                    vertexpair[i+j].append([i,j])
    
    numofedge = 0

    while numofedge != e:
        newindex = random.randint(1,totalpossibility)
        loc = 0
        while newindex > 0:
            if loc in vertexpair and len(vertexpair[loc]) != 0:
                if loc < v:
                    newindex = newindex - (loc)
                else:
                    newindex = newindex - ((v-1)*2-loc)
            loc += 1
        loc -= 1
        cindex = random.randint(0,len(vertexpair[loc])-1)
        add_edge(vertexpair[loc][cindex][0],vertexpair[loc][cindex][1],1)

        temp = vertexpair[loc][cindex]
        vertexpair[loc][cindex] = vertexpair[loc][len(vertexpair[loc])-1]
        vertexpair[loc][len(vertexpair[loc])-1] = temp
        vertexpair[loc].pop()          
        if len(vertexpair[loc]) == 0:
            if loc < v:
                totalpossibility -= (loc)
            else:
                totalpossibility -= ((v-1)*2-loc)
        numofedge += 1


def RandomGraph(v,e):
    if e < 0 or e > v*(v-1)/2:
        print("Invalid number of edges")
        return

    InitList(v)
    pairlist = []
    numofedge = 0
    for i in range(v):
        for j in range(i,v):
            if(i != j):
                pairlist.append([i,j])          # Add all possible edges to a list

    while numofedge != e:
        newindex = random.randint(0,len(pairlist)-1)        # Randomly choose one edge from the list
        add_edge(pairlist[newindex][0],pairlist[newindex][1],1)     # Add that to a graph

        temp = pairlist[newindex]
        pairlist[newindex] = pairlist[len(pairlist)-1]
        pairlist[len(pairlist)-1] = temp

        pairlist.pop()                      # Mark that visited edge
        numofedge = numofedge + 1


def ProcessInput():
    if Gtype == "Complete":
        CompleteGraph(Nvertices)
    elif Gtype == "CYCLE":
        CycleGraph(Nvertices)
    elif Gtype == "RANDOM":
        if Dtype == "UNIFORM":
            RandomGraph(Nvertices,Nedge)
        elif Dtype == "SKEWED":
            RandomGraphS(Nvertices,Nedge)
        elif Dtype == "GAUSSIAN":
            RandomGraphG(Nvertices,Nedge)
        else:
            print("Invalid Gtype")    
    else:
        print("Invalid Gtype")


def LoadInput():
    InputList = []
    with open("inputA.txt",'r') as f:   
        InputList = f.read().splitlines() 

    global Nvertices,Nedge,Gtype,Dtype

    Nvertices = int(InputList[0])
    Nedge = int(InputList[1])
    Gtype = InputList[2]
    if Gtype == "RANDOM":
        Dtype = InputList[3]
    f.close()


def PrintOutput(isToaFile, filename):              # isToaFile = 0 means print to the prompt, =1 means print to a file.
    if isToaFile:
        file = open(filename,"w")
        file.write(str(len(adj_list)) + "\n")
    else:
        print(str(len(adj_list)))

    initialindex = 1 + len(adj_list)
    for i in adj_list:
        if isToaFile:
            file.write(str(initialindex) + "\n")
        else:
            print(str(initialindex))
        initialindex = initialindex + len(adj_list[i])
     
    for i in adj_list:
        for j in adj_list[i]:
            if isToaFile:
                file.write(str(j[0]) + "\n")
            else:
                print(str(j[0]))

    if isToaFile:
        file.close()

LoadInput()
ProcessInput()
PrintOutput(True,"output.txt")