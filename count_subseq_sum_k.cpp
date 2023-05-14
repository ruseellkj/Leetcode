// count the subsequences with sum = k
#include <bits/stdc++.h>
using namespace std;


int printS(int ind, int s, int sum, int arr[], int n) {
	// this condition will never be satisified
	// strictly done only if array contains positives only
	if (s > sum) return 0;
	// the base condition
	if (ind == n) {
		// if the condition is satisfied
		if (s == sum) {
			return 1;
		}
		// cout << endl;
		return 0;
	}
	// add the element to the vector ds
	// ds.push_back(arr[ind]);
	s += arr[ind];

	int l = printS(ind + 1, s, sum, arr, n);

	// ds.pop_back();
	s -= arr[ind];

	// not take or not  pick condition
	int r = printS(ind + 1, s, sum, arr, n);

	return l + r;

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
	int arr[n];
	for (int i = 0; i < n ; i++) {
		cin >> arr[i];
	}
	int sum = 10;
	// vector<int> ds;
	cout << printS(0, 0, sum, arr, n);

	return 0;


}