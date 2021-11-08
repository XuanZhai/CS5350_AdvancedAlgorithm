from os import close
import random
import time


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





def PartOne(v):
    InitList()
    for i in range(v):
        for j in range(i,v):
            if(i != j):
                add_edge(i,j,1)


def PartTwo(v):
    InitList(v)
    for i in range(v-1):
        add_edge(i,i+1,1)
    add_edge(v-1,0,1)

    
def PartThree(v,e):
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
        pairlist.pop(newindex)                      # Mark that edge visited
        numofedge = numofedge + 1

    
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


def RunwithTime():
    time1 = []
    time2 = []
    time3 = []

    for i in range(100,1000,100):
        print(i)
        start = time.time()
        PartOne(i)
        end = time.time()
        duration = (end-start) * 1000
        time1.append([i,duration])
        ClearList()

        start = time.time()
        PartTwo(i)
        end = time.time()
        duration = (end-start) * 1000
        time2.append([i,duration])
        ClearList()

        start = time.time()
        PartThree(i, i*(i-1)/2)
        end = time.time()
        duration = (end-start) * 1000
        time3.append([i,duration])
        ClearList()
    
    print(time1)
    print("==========================================================")
    print(time2)
    print("==========================================================")
    print(time3)


PartThree(5,3)
PrintOutput(False,"file3.txt")
