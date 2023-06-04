//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int m = edge.size();
        if(m<n-1) return -1;
        // mk the union/graph
        DisjointSet ds(n);
        for(int i =0; i<m; i++){
            int u = edge[i][0];
            int v = edge[i][1];
            
            // if both the nodes are in the same compo then cnt
            if(ds.findUpar(u) == ds.findUpar(v)){
                continue;
            }
            else{
                ds.unionbySize(u,v);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ds.findUpar(i) == i){
                cnt++;
            }
        }
        
        return cnt-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends