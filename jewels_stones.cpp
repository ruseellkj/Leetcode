#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> mpp;
        for (int i = 0; i < jewels.size(); i++)
        {
            ++mpp[jewels[i]];
        }

        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (mpp.find(stones[i]) != mpp.end())
            {
                count += 1;
            }
        }
        return count;
    }
};

int main()
{
    string jewels;
    cin >> jewels;

    string stones;
    cin >> stones;

    // int res = numJewelsInStones(jewels, stones);
    // cout << res;
}