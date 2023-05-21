// class Solution {
// public:

//     void bfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, 
//     int iniColor, int color){

//         ans[row][col] = color;

//         int n = image.size();
//         int m = image[0].size();

//         // make queue of pairs
//         queue<pair<int,int>> q;
//         q.push({row,col});

//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             // traversing the  neighbors
//             for(int delrow=-1; delrow<=1; delrow++)
//             {
            
//                 int nrow=row+delrow;
//                 int ncol=col;
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
//                 image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
//                 {
//                     q.push({nrow,ncol});
//                     ans[nrow][ncol] = color;
//                 }
            
//             }
//             for(int delcol=-1;delcol<=1;delcol++)
//             {
//                 int nrow=row;
//                 int ncol=col+delcol;
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
//                 image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
//                 {
//                     q.push({nrow,ncol});
//                     ans[nrow][ncol] = color;
//                 }
//             }
//         }

//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         // applying bfs

//         // get the inital color
//         int iniColor = image[sr][sc];

//         int n = image.size();
//         int m = image[0].size();

//         // make a copy of the image matrix as ans matrix
//         vector<vector<int>> ans = image;
//         // int delrow[] = {-1,0,+1,0};
//         // int delcol[] = {0,+1,0,-1};
//         bfs(sr,sc,image,ans,iniColor,color);
//         return ans;

//     }
// };