#include  <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	// for getting the input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing the output at output/txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int prev2 = 0;
	int prev = 1;
	for (int i = 2; i <= n; i++)
	{
		int curi = prev + prev2;
		prev2 = prev;
		prev = curi;
	}
	cout << prev << endl;
	return 0;



}