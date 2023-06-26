//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	   // base case
	   int a = first_occurence(arr,n,x);
	   int b = last_occurence(arr,n,x);
	   //calculating the count/occurence of the number
	   int c = (b-a)+1;
	   
	   if (a == -1 || b == -1)
	        return 0;
	   //return c;
	   // if (first_occurence(arr,n,x) == -1 || last_occurence(arr,n,x) == -1)
		  //  return 0;
	   // return last_occurence(arr,n,x) - first_occurence(arr,n,x) + 1;
	}
	
	int first_occurence(int arr[], int n, int x)
	{
	    int start =0;
	    int end = n-1;
	    int res = -1;
	    while(start<=end){
	        int mid = (start+end)/2;
	        if(x == arr[mid]){
	            
	           // finding the first occurence
	           res = mid;
	           end = mid -1;
	        }
	        else if( x > arr[mid]){
	            start = mid +1;
	        }
	        else{
	            end = mid -1;
	        }
	    }
	    return res;
	    
	}
	
	int last_occurence(int arr[], int n, int x)
	{
	    int start =0;
	    int end = n-1;
	    int res = -1;
	    while(start<=end){
	        int mid = (start+end)/2;
	        if(x == arr[mid]){
	            
	           // finding the last occurence
	           res = mid;
	           start = mid +1;
	        }
	        else if( x > arr[mid]){
	            start = mid +1;
	        }
	        else{
	            end = mid -1;
	        }
	    }
	    return res;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends