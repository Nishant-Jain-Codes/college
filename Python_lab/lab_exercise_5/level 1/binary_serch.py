def binarySearch(arr,find):
    lo = 0
    hi = len(arr)
    while(lo<=hi):
        mid = (hi+lo)>>1
        if(arr[mid]==find):
            return True
        elif(arr[mid] > find):
            hi=mid-1
        else:
            lo = mid+1
    return False

size = int(input("enter the size of array "))
arr = [int(input("Enter the element: ")) for i in range(size)]
arr.sort()
find = int(input("what number to find ? "))
print(f"location of number {find} is in the array :{binarySearch(arr,find)}")