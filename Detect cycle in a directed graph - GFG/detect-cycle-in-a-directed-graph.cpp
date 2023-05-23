//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> adj[], int vis[], int pathV[]){
        vis[node] = 1;
        pathV[node] = 1;
        
        // traversing the adj nodes
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathV) == true){
                    return true;
                }
            }
            // else if its visited already and pathV as well
            else if(pathV[it]){
                return true;
            }
        }
        
        pathV[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // making vis and pathV array
        int vis[V] = {0};
        int pathV[V] = {0};
        
        for(int i =0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathV) == true ){
                    return true;
                }
            }
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends