#include <bits/stdc++.h>
using namespace std;

// now the array contains the duplicate elements
// we need to remove thr duplicates and return the ds also print the subsets
// refer the recursion tree of the notes

void printS2(int ind, vector<int> &ds, int arr[], int n) {
	// for selecting multiple sizes ds

	for (int i = ind; i < n; i++) {
		if (i != ind && arr[i] == arr[i - 1]) continue;
		ds.push_back(arr[i]);
		printS2(ind + 1, ds, arr, n);
		ds.pop_back();
	}
}

int main() {

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

	vector<int> ds;
	sort(arr, arr + n);
	printS2(0, ds, arr, n);

}