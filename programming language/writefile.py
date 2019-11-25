file = open("phone.txt",mode='a+')
while 1:
    name = input()
    if name == "exit" or name == "bye":
        break
    phone = input()
    file.write("%s:%s\n" % (name,phone))

file.close()
