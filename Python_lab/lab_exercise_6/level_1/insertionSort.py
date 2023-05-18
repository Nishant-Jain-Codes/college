def insertionSort(arr):
    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1
        while j>=0 and key<arr[j]:
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = key
arr = [int(x) for x in input("Enter the array: ").split()]
insertionSort(arr)
print(f"sorted array is {arr}")


# ouput
# Enter the array: 2 1 5 3 -1 39 219
# sorted array is [-1, 1, 2, 3, 5, 39, 219]