//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void toposort(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        
        // traversing the neighbors of node
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                toposort(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges)
    {
    // Make the graph
        vector<pair<int,int>> adj[N];
        for(int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }

        // Step 1: Topological Sort

        // Make the vis array
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i = 0; i < N; i++)
        {
            if(!vis[i]){
                toposort(i, adj, vis, st);
            }
        }

        // Step 2: The dist array
        // Make the dist array
        vector<int> dist(N, INT_MAX);
        // As 0 is the src
        dist[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            // Update the distances
            if(dist[node] != INT_MAX){
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    // Relaxation function
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for(auto &d : dist){
            if(d == INT_MAX){
                d = -1;
            }
        }
        return dist;
    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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