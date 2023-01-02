#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        int len = s.length();

        transform(s.begin(), s.end(), s.begin(), :: tolower);

        return s;


    }
};

