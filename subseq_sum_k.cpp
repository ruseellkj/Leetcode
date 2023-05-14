#include <bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	// the base condition
	if (ind == n) {
		if (s == sum) {
			for (auto it : ds) {
				cout << it <<  " ";
			}
			cout << endl;
		}
		// cout << endl;
		return;
	}
	// add the element to the vector ds
	ds.push_back(arr[ind]);
	s += arr[ind];

	printS(ind + 1, ds, s, sum, arr, n);

	ds.pop_back();
	s -= arr[ind];

	// not take or not pick condition
	printS(ind + 1, ds, s, sum, arr, n);

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
	int sum = 2;
	vector<int> ds;
	printS(0, ds, 0, sum, arr, n);

	return 0;


}