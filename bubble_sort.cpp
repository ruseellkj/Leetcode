#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here  
        bool swapped = false;
        // loop from 1 to n-1 , u can also use from 0 to <n-1 in place of 1 to <n
        for(int i=1; i<n; i++){
            // for processing all elements of arr 
            for(int j =0; j<n-i; j++){
                if(arr[j]>arr[j+1]){ 
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapped = true;
                }
            }
            if(swapped == false){
                // already sorted
                break;
            }
        }
    } 
};