class Solution {
public:
// naive recursive approach

    int f(int i, int j, string &text1, string &text2) {
        // base condition
        if (i < 0 || j < 0) return 0;

        // if the characs are equal then move the pointers backward
        if (text1[i] == text2[j]) return 1 + f(i - 1, j - 1, text1, text2);

        // if the characs are not matching then return the max of both
        return max(f(i, j - 1, text1, text2), f(i - 1, j, text1, text2));

    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return f(n - 1, m - 1, text1, text2);
    }
};