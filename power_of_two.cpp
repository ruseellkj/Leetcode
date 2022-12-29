#include <bits/stdc++.h>
using namespace std;

// using the constriants method #4 
// if (n == 0) return false;
// return (n > 0) && (1073741824 % n == 0);

// uisng bit manupilation method #3 ~the best method
// if (n <= 0) return false;
// return ((n & (n - 1)) == 0);

// using ceil-floor method #2
// if (n <= 0)
//     return false;
// return ceil(log2(n)) == floor(log2(n));

// remainder-divident method #1
bool isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n % 2 == 0)
        n = n / 2;
    return n == 1;
}
int main()
{
    int n;
    cin >> n;
    int res = isPowerOfTwo(n);
    cout << res << endl;
}