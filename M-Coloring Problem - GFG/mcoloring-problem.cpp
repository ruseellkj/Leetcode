//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isPossible(int node, int color[], bool graph[101][101], int col, int n){
        for(int k = 0; k<n; k++){
            if(k != node && graph[k][node] == 1 && color[k] == col){
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int color[], bool graph[][101], int m, int n){
        // base case
        if(node == n){
            return true;
        }
        
        for(int col = 1; col <=m; col++){
            if(isPossible(node,color,graph,col,n)){
                color[node] = col;
                if(solve(node+1,color,graph,m,n) == true){
                    return true;
                }
                color[node] = 0; //reset the color of that node 
                
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if(solve(0,color,graph,m,n) == true) return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends