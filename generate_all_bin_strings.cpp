#include <bits/stdc++.h>
using namespace std;

void PrintB(int num, string ds, int ind) {
	// base condition
	if (ind >= num) {
		cout << ds << " ";
		cout << endl;
		return;
	}
	// cout << endl;

	if (ind != 0 && ds[ind - 1] == '1') {
		PrintB(num, ds + '0', ind + 1);
	}
	else {
		// we are on index == 0
		PrintB(num, ds + '0', ind + 1);
		PrintB(num, ds + '1', ind + 1);
	}





}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting the input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing the output at output/txt
	freopen("output.txt", "w", stdout);
#endif

	int num;
	cin >> num;

	string ds;
	PrintB(num, "" , 0);


}