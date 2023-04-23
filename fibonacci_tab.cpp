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
	// step1: declare an array named as dp
	vector<int> dp(n + 1, -1);


	// step2: base condition
	dp[0] = 0;
	dp[1] = 1;


	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;


}