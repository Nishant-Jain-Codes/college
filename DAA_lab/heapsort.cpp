//https://practice.geeksforgeeks.org/problems/heap-sort/1

//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.
//require max heap 
class Solution
{
    public:
    //Heapify function to maintain heap property.
    bool inBound(int x , int n ){
        return x>=0 && x<n;
    }
  
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    if(n<=i)
        return;
    int parent = i ;
      int left = (2*parent)+1;
      int right = (2*parent)+2;
      int newParent = parent;
      if(inBound(left,n)&& inBound(right,n)){
          if(arr[newParent]<arr[left]){
              newParent = left;
          }
          if ( arr[newParent]<arr[right]){
              newParent = right;
          }
      }
      else if(inBound(left,n)){
          if(arr[newParent]<arr[left]){
              newParent = left;
              
          }
      }
      if ( newParent == parent)
       { return;}
        else 
        {
            swap(arr[newParent],arr[parent]);
            heapify(arr,n,newParent);
        }
      
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for ( int i =(n+1)/2;i>=0;i--){
            heapify(arr,n,i);
        }
        
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i = 0;i<n;i++){
            swap(arr[0],arr[n-1-i]);
            heapify(arr,n-1-i,0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends