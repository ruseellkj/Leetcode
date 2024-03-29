//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int node, vector<int> adj[],vector<int>& vis, vector<int>& dist){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it])
                dist[it] = dist[node]+1;
            if(!vis[it]){
                dfs(it,adj,vis,dist);
            }
        }
        vis[node] = 0;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // mk the graph
        vector<int>adj[N];
        for(int i =0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(N,0);
        vector<int>dist(N,1e9);
        dist[src] = 0;
        
        dfs(src,adj,vis,dist);
        
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends