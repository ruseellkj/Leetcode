int maxChildren(int n, int m, vector<int> &g, vector<int> &s) {
        // code here
         sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0,i=0,j=0;
       while(i<n && j<m)
       {
           if(g[i]<=s[j])
           {
               i++;
              // j++;
               c++;
           }
           j++;
       }
       return c;
    }