#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printS(int ind, int sum, vector<int> &arr, vector<int> &ds, int N)
    {
        // base condition
        if (ind >= N) {
            ds.push_back(sum);
            return;
        }

        // select/pick
        printS(ind + 1, sum + arr[ind], arr, ds, N);

        // not-select/not-pick
        printS(ind + 1, sum, arr, ds, N);

    }


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        // make a data structure
        vector<int> ds;
        printS(0, 0, arr, ds, N);
        sort(ds.begin(), ds.end());
        return ds;
    }
};