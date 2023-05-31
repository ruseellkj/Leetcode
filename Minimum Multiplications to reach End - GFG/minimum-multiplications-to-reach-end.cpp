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
        // using simple bfs
        int mod = 100000;
        // mk the vis arr
        vector<int> vis(mod,0);
        vis[start] = 1;
        // mk the queue
        // {steps,node}
        queue<pair<int,int>> q;
        q.push({0,start});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second;
            
            
            if(node == end) return steps;
            // traversing the arr
            for (int i = 0; i < arr.size(); i++)
		    {
			    int x = (arr[i] * node) % mod;
			    if (vis[x])
				    continue;
			    vis[x] = 1;
			    q.push({steps + 1, x});
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