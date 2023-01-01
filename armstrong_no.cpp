#include <bits/stdc++.h>
using namespace std;

string isArmstrong(int n)
{
    int x = n;
    int c = 0;
    int y = n;
    while (x != 0)
    {
        x = x / 10;
        c++;
    }

    int sum = 0;
    while (n != 0)
    {
        int d = n % 10;
        sum += pow(d, c);
        n /= 10;
    }
    if (y == sum)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main()
{
    int n = 153;
    cout << "Is the number armstrong number? " << isArmstrong(n);
}