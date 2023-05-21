// class Solution {
// public:

//     void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
//         vis[row][col] = 1;

//         int n = grid.size();
//         int m = grid[0].size();

//         // now traverse the nearest neigbours in all 4 directions 
//         // and mark them if its land (1)
//         for(int delrow=-1; delrow<=1; delrow++)
//         {
            
//             int nrow=row+delrow;
//             int ncol=col;
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
//             !vis[nrow][ncol] && grid[nrow][ncol]=='1')
//             {
//                 dfs(nrow,ncol,vis,grid);
//             }
            
//         }

//         for(int delcol=-1;delcol<=1;delcol++)
//         {
//             int nrow=row;
//             int ncol=col+delcol;
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
//             !vis[nrow][ncol] && grid[nrow][ncol]=='1')
//             {
//                 dfs(nrow,ncol,vis,grid);
//             }
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         // here the nearest neighbours are in only in 4 directions not 8 directions
//         // applying bfs then dfs in next submission
//         int n = grid.size();
//         int m = grid[0].size();

//         // creating vis matrix
//         vector<vector<int>> vis(n, vector<int> (m,0));
//         int cnt = 0;
//         for(int row = 0; row<n; row++){
//             for(int col = 0; col<m; col++){
//                 if(!vis[row][col] && grid[row][col] == '1'){
//                     cnt++;
//                     dfs(row,col,vis,grid);
//                 }
//             }
//         }
//         return cnt;

//     }
// };