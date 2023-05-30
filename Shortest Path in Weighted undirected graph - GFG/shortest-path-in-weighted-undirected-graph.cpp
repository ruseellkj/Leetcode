//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // mk the graph
        vector<pair<int,int>> adj[n+1];
        for(int i =0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // mk the pq
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        // mk the dist arr
        vector<int> dist(n+1,1e9);
        dist[1] = 0;
        
        // mk the parent arr
        vector<int> parent(n+1);
        for(int i =0; i<n; i++){
            parent[i] = i;
        }
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // traversing the neighbors of node
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgeweight = it.second;
                
                if(dis + edgeweight < dist[adjnode]){
                    // update the dist
                    dist[adjnode] = dis + edgeweight;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
        // if some node is not reachable then 
        if(dist[n] == 1e9){
            return {-1};
        }
        vector<int> ans;
        while(parent[n] != n){
            ans.push_back(n);
            n = parent[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends