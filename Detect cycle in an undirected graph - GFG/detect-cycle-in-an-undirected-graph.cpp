//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int s, vector<int> adj[], int visited[],int parent) 
     {
         visited[s]=1;
         for(auto it:adj[s])
         {
             if(!visited[it])
             {
                 if(dfs(it,adj,visited,s))
                 return true;
             }
             else if(it!=parent)
             {
                 return true;
             }
         }
         return false;
     }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        int visited[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,-1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends