#include <bits/stdc++.h>
using namespace std;
void print_array(int arr[], int n){
    for(int i =0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap_adj_ele(int arr[], int n){
    for(int i =0; i<n; i+=2){
        if(i+1 < n){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }

    swap_adj_ele(arr,n);
    print_array(arr,n);


}