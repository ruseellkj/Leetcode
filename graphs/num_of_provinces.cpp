// class Solution {
// public:
//     void dfs(int node,vector<int> &vis,vector<int> adjLs[]){
//         vis[node]=1;
              
//         for(auto it : adjLs[node]){
//             if(!vis[it]){
//                 // vis.push_back(it);
//                 dfs(it,vis,adjLs);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected[0].size();
//         // make your adj list
//         vector<int> adjLs[V];
//         // converting adj matrix to list
//         for(int i = 0; i<V; i++){
//             for(int j = 0; j<V; j++){
//                 if(isConnected[i][j] == 1 && i!=j){
//                     adjLs[i].push_back(j);
//                     adjLs[j].push_back(i);
//                 }
//             }
//         }

//         // making vis array or vector
//         vector<int>vis(V+1,0);
//         int cnt = 0;
//         for(int i = 0; i<V; i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(i,vis,adjLs);
//             }
//         }
//         return cnt;


//     }
// };