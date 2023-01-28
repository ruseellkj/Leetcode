#include <bits/stdc++.h>
using namespace std;

// 10 1 7 4 8 2 11
// round 1 :
// 1 10 7 4 8 2 11

// dont do swapping , instead do shifting
// void insertion_sort(int arr[], int n){
//     for(int i=1; i<n; i++){
//         int current = arr[i];
//         for(int j = i-1; j>=0; j--){
//             if(arr[j]>current){
//                 // shifting left
//                 arr[j+1] = arr[j];
//             }
//             else{
//                 break;
//             }
//         }
//         arr[j+1] = current
//     }
// }

 void insertionSort(int arr[], int n){
        for(int i =1; i<n; i++){
            int current = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>current){
                // shifting
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1]= current;
        }
    }