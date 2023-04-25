class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            mp[dep[i]+1]--;
        }
        int maxplat=1;
        int sum=0;
        for(auto t:mp){
            sum+=t.second;
            maxplat = max(maxplat,sum);
        }
        return maxplat;
    }
};