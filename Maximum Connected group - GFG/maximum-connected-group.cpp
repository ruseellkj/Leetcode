//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// mk the class disjointset
class DisjointSet {

public:
	vector<int> rank, parent, size;
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
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();

        // step 1: mk the components connected
        DisjointSet ds(n * n);
        for(int row =0; row<n; row++){
            for(int col =0; col<n; col++){
                if(grid[row][col] == 0) continue;
                int delrow[] = {-1,0,+1,0};
                int delcol[] = {0,-1,0,+1};
                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                    && grid[nrow][ncol] == 1){
                        int nodeNo = row * n + col;
                        int adjnodeNo = nrow * n + ncol;
                        ds.unionbySize(nodeNo,adjnodeNo);
                    }
                }
                
            }
        }
        int mx = 0;
        // step 2: 0->1 conversion
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;
                int delrow[] = {-1,0,+1,0};
                int delcol[] = {0,+1,0,-1};
                set<int> components;
                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                    && grid[nrow][ncol] == 1){
                        int adjnodeNo = nrow * n + ncol;
                        components.insert(ds.findUpar(adjnodeNo));
                    }
                }
                int tsize = 0;
                for(auto it : components){
                    tsize += ds.size[it];
                }
                mx = max(mx,tsize + 1);
            }
        }
        for(int cellNo=0; cellNo<n*n; cellNo++){
            mx=max(mx,ds.size[ds.findUpar(n*n-1)]);
        }
        return mx;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends