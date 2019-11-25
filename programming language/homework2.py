import os
import math

def main():
    theRange = int(input())
    if theRange < 3 or theRange%2!=1:
        print("Range must bigger than 2 or must be odd")
        stop()
    startingPoint = int(input())
    if(startingPoint > 4 or startingPoint < 0):
        print("startingPoint must less than 5 and bigger than -1")
        stop()
    arr = [[] for i in range(theRange)]
    for x in arr:
        str = input()
        x.extend(list(str))
        if len(x) != theRange:
            print("must be {0} numbers".format(theRange))
            stop()
    record = ""
    x = len(arr)//2
    y = len(arr[x])//2
    z = 1
    record += arr[x][y]
    direction = 4 #4=>left 8=>top 6=>right 2=>down
    if startingPoint == 0:
        direction = 4
    elif startingPoint == 1:
        direction = 8
    elif startingPoint == 2:
        direction = 6
    elif startingPoint == 3:
        direction = 2

    while 1:
        for j in range(2):
            for k in range(z):
                try:
                    if direction==4:
                        y = y-1
                    elif direction==8:
                        x = x-1
                    elif direction==6:
                        y = y+1
                    elif direction==2:
                        x = x+1
                    if(x<0 or y<0):
                        raise IndexError()
                    record += arr[x][y]
                except IndexError:
                    print(record)
                    stop()
            
            if direction==4:
                direction =8
            elif direction==8:
                direction = 6
            elif direction==6:
                direction = 2
            elif direction==2:
                direction = 4
        z = z+1
    
    print(record)
    
def stop():
    os.system("pause")
    exit()
    
main()
