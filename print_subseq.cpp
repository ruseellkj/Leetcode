#include <bits/stdc++.h>
using namespace std;


void printF(int ind, vector<int> &ds, int arr[], int n)
{
	if (ind >= n) {
		for (auto it : ds) {
			cout << it << " ";
		}
		if (ds.size() == 0) {
			cout << "[]" << endl;
		}
		cout << endl;
		return;
	}

	// if this is not the base case
	// first we add the first ind element to the empty array
	ds.push_back(arr[ind]);
	// now we call the func again for the next index
	printF(ind + 1, ds, arr, n);
	// now we remove the element so in order to get all the subseq
	ds.pop_back();
	// not pick or not take condition
	printF(ind + 1, ds, arr, n);

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
	vector<int> ds; //empty array to store the ans
	printF(0, ds, arr, n);
}