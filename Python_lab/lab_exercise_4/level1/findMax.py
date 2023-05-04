
# Find the maximum element in a list of numbers
def maxFinder(inList):
    max = inList[0]
    for i in inList:
        if i > max:
            max = i
    return max
noOfElements = int(input("Enter the number of elements: "))
inList = [int(input("Enter the element: ")) for i in range(noOfElements)]
print("The maximum element is: ", maxFinder(inList))