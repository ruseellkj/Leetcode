//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // using the set data structure
        // mk a set 
        set<pair<int,int>> st;
        // mk the dist arr
        vector<int> dist(V,1e9);
        dist[S]=0;
        st.insert({0,S});
        
        while(!st.empty()){
            // this gives the value of the top/begin of the set
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            // remove/erase
            st.erase(it);
            
            // traverse/iterate through the nieghbors
            for(auto it : adj[node]){
                int adjnode = it[0];
                int edgeweight = it[1];
                
                if(dis + edgeweight < dist[adjnode]){
                    // erase if it already exist
                    if(dist[adjnode] != 1e9){
                        // this means there was someone who updated
                        // the dist from 1e9 to <1e9
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode] = dis + edgeweight;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends