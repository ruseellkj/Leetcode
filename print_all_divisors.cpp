#include <bits/stdc++.h>
using namespace std;

// time complexity = O(N);
// int main(){
//     int n ;
//     cin >> n;
//     for(int i=1; i<=n; i++){
//         if(n%i==0){
//             cout << i << " ";
//         }
//     }
// }

// alternate way of doing having O(sqrt(N));
vector<int> ls;
void printDivisors(int num)
{
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            ls.push_back(i);
        }
        if ((num / i) != i)
        {
            ls.push_back(num / i);
        }
    }

    // internal sorting
    // O(n log n ) where n is the number of factors
    // sort(ls.begin(), ls.end());
    for(auto it : ls){
        cout << it << " ";
    }
    cout << endl;
    
    cout<<accumulate(ls.begin(),ls.end(),0);
}
int main()
{
    int num;
    cin >> num;
    printDivisors(num);
}
