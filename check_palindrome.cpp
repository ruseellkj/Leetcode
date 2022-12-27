#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x == 0)
    {
        return true;
    }

    if (x < 0 || x % 10 == 0)
    {
        return false;
    }
    int n = x;
    int reverse = 0;
    while (n != 0)
    {
        int d = n % 10;
        reverse = reverse * 10 + d;
        n = n / 10;
    }
    cout << "reversed number is " << reverse << endl;
    
    if (x == reverse || x == reverse/10)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}