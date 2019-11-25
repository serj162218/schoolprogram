import os
name = input("Enter name: ")
age = int(input("Enter age: "))
salary = int(input("Enter Salary: "))
if ((18<=age<=26 and salary >= 10000) or (age > 85 and salary > 1000000)):
    print("Welcome {0}!".format(name))
else:
    print("Sorry {0}!".format(name))
os.system("pause")
