from dataclasses import dataclass


@dataclass
class proc:
    pro_no: int
    burst: int

def setzero(num):
    rows, cols = (num, 10)
    arr = [[0 for i in range(cols)] for j in range(rows)]
    for i in range(1, num):
        arr[i][0]=i
    return arr

def getdata(no):
    num = no + 1
    arr = setzero(num)
    print(arr)

def push(val):











no = 5
getdata()
