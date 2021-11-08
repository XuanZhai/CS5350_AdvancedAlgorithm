from hashlib import new
import time
import random
import matplotlib.pyplot as plt



def Task1(size):
    start = time.time()
    for i in range(size):
        print("Hello, World")
    
    end = time.time()
    ans = (end-start) * 1000
    return ans


def Task2(size):

    newarray = []
    start = time.time()
    for i in range(size):
        temp = random.randint(1,size)
        newarray.append(temp)
        j = len(newarray)-2
        while(newarray[j] > temp and j>=0):
            temp1 = newarray[j+1]
            newarray[j+1] = newarray[j]
            newarray[j] = temp1
            j = j - 1
    end = time.time()
    ans = (end-start) * 1000
    return ans


def Task3(size):
    newarray = []
    num1,num2,num3 = 0,0,0
    start = time.time()
    for i in range(size):
        temp = random.randint(1,3)
        if(temp == 1):
            num1 = num1 + 1
        elif(temp == 2):
            num2 = num2 + 1
        else:
            num3 = num3 + 1
        newarray.append(temp)
    end = time.time()
    ans = (end-start) * 1000
    return ans


def Task3v2(size):
    newarray = []
    num1,num2,num3 = 0,0,0
    for i in range(size):
        temp = random.randint(1,3)
        if(temp == 1):
            num1 = num1 + 1
        elif(temp == 2):
            num2 = num2 + 1
        else:
            num3 = num3 + 1
        newarray.append(temp)
    return newarray



def mergeSort(arr):     # Reference: https://www.geeksforgeeks.org/merge-sort contributed by Mayank Khanna
    if len(arr) > 1:
 
         # Finding the mid of the array
        mid = len(arr)//2
        # Dividing the array elements
        L = arr[:mid]
        # into 2 halves
        R = arr[mid:]
        # Sorting the first half
        mergeSort(L)
        # Sorting the second half
        mergeSort(R)
        i = j = k = 0
        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


def Task4(newarray):
    start = time.time()
    mergeSort(newarray)
    end = time.time()
    ans = (end-start) * 1000
    return ans



# Q1table = []
# Q1Xaxis = [100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000]
# for a in range(100000, 1100000, 100000):
#     Q1table.append(Task1(a))

# plt.plot(Q1Xaxis, Q1table)
# plt.title("n numbers of Hello World and processing time")
# plt.xlabel("n")
# plt.ylabel("time(sec)")
# plt.show()
# print(Q1table)


# Q2table = []
# Q2Xaxis = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]
# for b in range(1000, 11000, 1000):
#     Q2table.append(Task2(b))
# plt.plot(Q2Xaxis, Q2table)
# plt.title("Question two: the number of value and the running time")
# plt.xlabel("n")
# plt.ylabel("time(sec)")
# plt.show()
# print(Q2table)

# temparray = []
# Q3table = []
# Q3Xaxis = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]
# for c in range(1000, 11000, 1000):
#     Q3table.append(Task3(c, temparray))

# plt.plot(Q3Xaxis, Q3table)
# plt.title("Question three: the number of value and the running time")
# plt.xlabel("n")
# plt.ylabel("time(sec)")
# plt.show()
# print(Q3table)


Q4table = []
Q4Xaxis = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]
for d in range(1000000, 11000000, 1000000):
    Q4table.append(Task4(Task3v2(d)))
plt.plot(Q4Xaxis, Q4table)
plt.title("Question four: the number of value and the running time")
plt.xlabel("n")
plt.ylabel("time(sec)")
plt.show()
print(Q4table)