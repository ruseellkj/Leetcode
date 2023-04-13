#include <bits/stdc++.h>
using namespace std;

bool f(int i, string &s)

{
	if (i >= s.size() / 2) return true;
	if (s[i] != s[s.size() - i - 1]) return false;
	return f(i + 1, s);
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting the input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing the output at output/txt
	freopen("output.txt", "w", stdout);
#endif

	string s = "madam";
	cout << f(0, s);
	return 0;

}