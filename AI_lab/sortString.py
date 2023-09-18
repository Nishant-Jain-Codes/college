def sortString(givenStr):
    givenStr = givenStr.split(" ")
    givenStr.sort()
    givenStr = ' '.join(givenStr)
    givenStr = givenStr[1:]
    return givenStr

givenStr = input("enter string \n")
print(f"string after sorting\n{sortString(givenStr)}")
