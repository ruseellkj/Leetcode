//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> adj[], int vis[]){
        vis[node] = 2;
        // pathV[node] = 1;
        
        // traversing the adj nodes
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis) == true){
                    return true;
                }
            }
            // else if its visited already and pathV as well
            else if(vis[it] == 2){
                return true;
            }
        }
        
        vis[node] = 1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // making vis and pathV array
        int vis[V] = {0};
        // int pathV[V] = {0};
        
        for(int i =0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis) == true ){
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