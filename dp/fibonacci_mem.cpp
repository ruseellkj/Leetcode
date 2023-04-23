#include  <bits/stdc++.h>
using namespace std;

// program for the finding the fibonacci number
int fib(int n, vector<int> &dp)
{
	//base condition
	if (n <= 1)
	{
		return n;
	}
	// step 2: check the value of in the dp array isnt -1
	if (dp[n] != -1) return dp[n];

	// step 3: writing dp[n] =
	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

}
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
	// step 1: declare an array named as dp of max size of subproblems
	// using vector already takes in the size and the memset of dup val as -1
	vector<int> dp(n + 1, -1);
	cout << fib(n, dp);
	return 0;


}