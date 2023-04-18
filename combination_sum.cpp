// this is a qs of recursion which will help in understading the concept of recursion and dp
#include <bits/stdc++.h>
using namespace std;

// tc : O(2^t x k) k is the time to put arr[] to ds
// sc : O(k x X) where X is the no of combinations

void PrintC(int ind, int target, vector<int> ds, int n, int arr[]) {
	//base condition
	if (ind == n) {
		if (target == 0) {
			for (auto it : ds) {
				cout << it << " ";
			}
			cout << endl;
		}
		return;
	}
	// take condition
	if (arr[ind] <= target) {
		ds.push_back(arr[ind]);
		PrintC(ind, target - arr[ind], ds, n, arr);
		ds.pop_back();

	}

// non-take condition
	PrintC(ind + 1, target, ds, n, arr);
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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int target;
	cin >> target;
	vector<int> ds;
	PrintC(0, target, ds, n, arr);


}