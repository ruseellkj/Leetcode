#include<bits/stdc++.h>
using namespace std;


class Solution

{
    public:
    //Function to perform case-specific sorting of strings.
    // string caseSort(string str, int n)
    // {
    //     // your code here
    //     // make two arrays/vectors and push_back the lower and upper also sort it 
    //     vector<char> lower,upper;
    //     for(int i =0; i<n; i++){
    //         if(str[i]>=97){
    //             // defers
    //             lower.push_back(str[i]);
    //         }
    //         else{
    //             // RTSUXI
    //             upper.push_back(str[i]);
    //         }
    //     }
    //     // deefrs
    //     sort(lower.begin(),lower.end());
    //     // IRTSUX
    //     sort(upper.begin(),upper.end());
        
    //     // now merging it in one string 
    //     // iterate the original string and check the char if >=97 then in ans string put the char of lower and vice-versa
    //     string ans = "";
    //     int j=0,k=0;
    //     for(int i=0; i<n; i++){
    //         if(str[i]>=97){
    //             ans = ans + lower[j];
    //             j++;
    //         }
    //         else{
    //             ans = ans + upper[k];
    //             k++;
    //         }
    //     }
    //     return ans;
        
     
        
    // }

    // more optimized code

    string caseSort(string str, int n)
    {
        // your code here
        // make two strings and push_back the lower and upper also sort it 
        string lower = "";
        string upper = "";
        for(int i =0; i<n; i++){
            if(str[i]>=97){
                // defers
                lower+=str[i];
            }
            else{
                // RTSUXI
                upper+=str[i];
            }
        }
        // deefrs
        sort(lower.begin(),lower.end());
        // IRTSUX
        sort(upper.begin(),upper.end());
        
        // now merging it in one string 
        // iterate the original string and check the char if >=97 then in ans string put the char of lower and vice-versa
        int j=0,k=0;
        for(int i=0; i<n; i++){
            if(str[i]>=97){
                str[i] = lower[j];
                j++;
            }
            else{
                str[i] = upper[k];
                k++;
            }
        }
        return str;
    }


};