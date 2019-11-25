file = open("phone.txt",'r')
no = {}
for i in open("phone.txt"):
    name,phone = file.readline().split(":")
    no[name] = phone

print(no)

while True:
    searchName = input("Enter the name you want to get phoneNumber:\n")
    if searchName == "exit" or searchName == "bye":
        break
    try:
        print("%s's phone is %s" % (searchName,no[searchName]))
    except:
        print("there's no info. with this person.")

file.close()
