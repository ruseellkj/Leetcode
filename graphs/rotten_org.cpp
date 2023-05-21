// class Solution {
// public:
//     int bfs(vector<vector<int>>& grid, int delrow[], int delcol[]) {
//         int n = grid.size();
//         int m = grid[0].size();

//         int freshCount = 0;  // Count of fresh oranges
//         int rottentime = 0;  // Initialize with -1

//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         queue<pair<pair<int, int>, int>> q;

//         // Enqueue all initially rotten oranges
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {
//                 if (grid[row][col] == 2) {
//                     q.push({{row, col}, 0});
//                     vis[row][col] = 1;
//                 } else if (grid[row][col] == 1) {
//                     freshCount++;
//                 }
//             }
//         }

//         while (!q.empty()) {
//             int row = q.front().first.first;
//             int col = q.front().first.second;
//             int t = q.front().second;
//             q.pop();

//             rottentime = max(rottentime, t);

//             // Traversing the neighbors in 4-directions
//             for (int i = 0; i < 4; i++) {
//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];

//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                  vis[nrow][ncol] == 0 &&   grid[nrow][ncol] == 1) {
//                     q.push({{nrow, ncol}, t + 1});
//                     vis[nrow][ncol] = 1;
//                     grid[nrow][ncol] = 2;
//                     freshCount--;
//                 }
//             }
//         }

//         return (freshCount == 0) ? rottentime : -1;
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
//         int delrow[] = {-1, 0, 1, 0};
//         int delcol[] = {0, 1, 0, -1};

//         return bfs(grid, delrow, delcol);
//     }
// };
