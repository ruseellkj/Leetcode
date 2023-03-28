// find the index of first 1 in an infinite sorted array of 0's and 1's
#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int low, int high, int x){
    int mid;
    int res = -1;
    while(low<=high){
        mid = low + (high-low)/2;
        if(x == arr[mid]){
            res = mid;
            high = mid - 1;
        }
        else if(x > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
        return res;

    }
    return -1;

}
int findone(int arr[], int x){
    int low = 0;
    int high = 1;
    while(x > arr[high]){
        low= high;
        high = high * 2;
    }
    return binarysearch(arr,low,high,x);
}