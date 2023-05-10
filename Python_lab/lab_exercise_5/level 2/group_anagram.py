
size = int(input("enter the size of array "))
givenList = [input("Enter the element: ") for i in range(size)]
mappedList = {i:sorted(i) for i in givenList}
solution = []
for i in range(0,len(givenList)):
    temp = []
    if givenList[i] == '':
        continue
    for j in range(i+1,len(givenList)):
        if(len(givenList[j])!=0 and mappedList[givenList[i]]==mappedList[givenList[j]] ):
            temp.append(givenList[j])
            givenList[j] = ""
    if(len(temp)>0):
        temp.append(givenList[i])
        solution.append(temp)
print(solution)