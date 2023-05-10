def bubbleSort(arr,si,ei):
    if(si>=ei):
        return
    for i in range(si,ei):
        if(arr[i]>arr[i+1]):
            temp = arr[i]
            arr[i]=arr[i+1]
            arr[i+1]=temp
    bubbleSort(arr,si,ei-1)
    return 

size = int(input("enter the size of array "))
arr = [int(input("Enter the element: ")) for i in range(size)]
bubbleSort(arr,0,size-1)
print(f"sorted array is {arr}")