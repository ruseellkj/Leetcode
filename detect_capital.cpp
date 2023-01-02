#include <bits/stdc++.h>
using namespace std;

string word;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int len = word.length();
        // if first letter is in uppercase
        if (isupper(word[0]))
        {
            // if the second letter is in uppercase
            if (isupper(word[1]))
            {
                // but from 3rd letter to the end of the string is it upper?
                for (int i = 2; i < len; i++)
                {
                    if (islower(word[i]))
                    {
                        return false;
                    }
                }
            }
            else
            {
                // if the second letter is in lowercase
                for (int i = 1; i < len; i++)
                {
                    // but from 2nd letter to the end of the end of the string is it lower?
                    if (isupper(word[i]))
                    {
                        return false;
                    }
                }
            }
        }
        // if the first letter is in lowercase
        else
        {
            for (int i = 0; i < len; i++)
            {
                // but from starting is it in lowercase?
                if (isupper(word[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    string word;
    cin >> word;
    // if(detectCapitalUse(word)){
    //     return true;
    // }
    
    // cout << ans << endl;
    // return 0;
}