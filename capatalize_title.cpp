#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int len = title.length();
        string ans = "";

        ans.reserve(len);
        // approach using string stream
        stringstream ss(title);
        string word;

        while(ss>>word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if(word.length()> 2)
                word[0] = toupper(word[0]);

            ans+=word;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};