vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin() , intervals.end()) ; 
         int n = intervals.size() ; 
         int res = 0 ; 
         for(int i = 1 ; i<n ; i++){
             if(intervals[res][1] >= intervals[i][0]){
                 intervals[res][1] = max( intervals[res][1] ,  intervals[i][1]);
                 intervals[res][0] = min( intervals[res][0] ,  intervals[i][0]) ;
             }
             else{
                 res++;
                 intervals[res] = intervals[i] ; 
             }
         }
         intervals.resize(res+1) ; 
         return intervals ; 
    }