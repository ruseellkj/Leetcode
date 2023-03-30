class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // here there are m rows and n columns
        // tc = o(m+n) this is the better solution and the code following this is the optimal solution o(n*logm)

        // these are the no of rows and no of columns
        int m = matrix.size();
        int n = matrix[0].size();
        // int i = 0;
        // int j = n -1;

        // // condition for the bound
        // while(i<m && j>=0 ){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }
        //     else if(matrix[i][j] > target){
        //         j--;
        //     }
        //     else if(matrix[i][j] < target){
        //         i++;
        //     }
        // }
        // return false;


        // tc = o(log(m*n))
        int lo = 0;
        // created an imaginery 1D array of size from 0 to n*m-1
        int hi = (n*m) -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j] == target){
                return 1;
            }
            else if(matrix[i][j] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return 0;


        
    }
};