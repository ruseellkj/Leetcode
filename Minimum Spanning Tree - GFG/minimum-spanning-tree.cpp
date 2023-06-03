//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        // converting adj matrix to adj list
        vector<vector<pair<int, int>>> adjLs(V);
        for (int i = 0; i < V; i++)
        {
            for (auto edge : adj[i])
            {
                int u = edge[0];
                int wt = edge[1];
                adjLs[i].push_back({u, wt});
                adjLs[u].push_back({i, wt});
            }
        }
        // mk the pq
        // {wt,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        // mk the vis arr
        vector<int> vis(V,0);
        
        // to store the sum of the MST
        int sum = 0; 
        
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            
            // if the node is visited already
            if(vis[node] == 1) continue;
            // when we add it to the mst
            vis[node] = 1;
            sum += wt;
            
            // traversing the neighbors of that node
            
            for(auto it : adjLs[node]){
                int adjnode = it.first;
                int eW = it.second;
                
                if(!vis[adjnode]){
                    pq.push({eW,adjnode});
                }
            }
        }
        
        return sum;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends