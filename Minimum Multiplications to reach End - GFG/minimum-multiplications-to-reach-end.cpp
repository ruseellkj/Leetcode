//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        
        // mk the queue
        // {steps,node}
        queue<pair<int,int>> q;
        
        // mk the dist arr
        vector<int> dist(mod,1e9);
        
        q.push({0,start});
        
        while(!q.empty()){
            auto it = q.front();
            int steps = it.first;
            int node = it.second;
            q.pop();
            
            // traversing the arr and multiplying the node with it
            for(auto it : arr){
                int num = (it*node)%mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return dist[num];
                    q.push({steps+1,num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends