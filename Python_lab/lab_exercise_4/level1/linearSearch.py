def indexFinder(inList,x):
    for i in range(len(inList)):
        if inList[i] == x:
            return i
    return -1

inList = [int(input("Enter the element: ")) for i in range(int(input("Enter the number of elements: ")))]
element = int(input("Enter the element to be searched: "))
print("The element is present at index: ", indexFinder(inList, element))