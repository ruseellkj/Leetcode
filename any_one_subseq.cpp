// techniuq to print anyone subseq from the rest without using global variable
#include <bits/stdc++.h>
using namespace std;

bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	// the base condition
	if (ind == n) {
		// if the condition is satisfied
		if (s == sum) {
			for (auto it : ds) {
				cout << it <<  " ";
			}
			cout << endl;
			return true;
		}
		// cout << endl;
		return false;
	}
	// add the element to the vector ds
	ds.push_back(arr[ind]);
	s += arr[ind];

	if (printS(ind + 1, ds, s, sum, arr, n) == true) {
		return true;
	};

	ds.pop_back();
	s -= arr[ind];

	// not take or not pick condition
	if (printS(ind + 1, ds, s, sum, arr, n) == true) return true;

	return false;

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