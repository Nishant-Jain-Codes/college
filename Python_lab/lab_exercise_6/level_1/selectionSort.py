def selectionSort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1,len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[i],arr[min_index] = arr[min_index],arr[i] 
arr = [int(x) for x in input("Enter the array: ").split()]
selectionSort(arr)
print(f"sorted array is {arr}")


# ouput
# Enter the array: 1 5 -1 10 200 104
# sorted array is [-1, 1, 5, 10, 104, 200]