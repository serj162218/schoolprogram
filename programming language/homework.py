import os
arr = input("Enter n: ")
odd = 0
even = 0
for x in range(len(arr)):
    try:
        if(x%2==0): #count start with 1, different with programming-language
            odd += int(arr[x])
        else:
            even += int(arr[x])
    except:
        print("Error! n must be NUMBER")
        os.system("pause")
        exit()
print("Result is {0}".format(abs(odd-even)))
os.system("pause")
