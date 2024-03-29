//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// mk the class disjointset
class DisjointSet {
	vector<int> rank, parent, size;
public:
	// mk the parameterised constructor to put in the data
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	// mk the functions
	int findUpar(int node) {
		if (node == parent[node])
			return node;
		return parent[node] = findUpar(parent[node]);
	}

	void unionbyRank(int u, int v) {
		// finding the ultimate parent of both u and v
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);
		if (ulp_u == ulp_v) return;
		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_v] < rank[ulp_u]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			// if both the ranks are equal
			// then add either one
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}

	void unionbySize(int u, int v) {
		// finding the ultimate parent of both u and v
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);
		if (ulp_u == ulp_v) return;

		if (size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else if (size[ulp_v] < size[ulp_u]) {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		else {
			// if both the sizes are same
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // by kruskals algo using disjoint set 
        // mk the adj list
        vector<pair<int, pair<int,int>>> edges;
        for(int i =0; i<V; i++){
            for(auto it : adj[i]){
                int wt= it[1];
                int adjnode = it[0];
                int node = i;
                edges.push_back({wt,{node, adjnode}});
            }
        }
        DisjointSet ds(V);
        
        sort(edges.begin(), edges.end());
        int mstwt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                mstwt += wt;
                ds.unionbySize(u,v);
                
            }
            
        }
        return mstwt;
        
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