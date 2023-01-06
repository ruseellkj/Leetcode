#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,char> mpp;
        set <char> st;
        for(int i =0; i<s.size(); i++){
            if(mpp.find(s[i]) != mpp.end()){
                if(mpp[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(st.count(t[i])>0){
                    return false;
                }
                mpp[s[i]] = t[i];
                st.insert(t[i]);
            }
        }
        return true;
        
    }
};

int main(){
    
}