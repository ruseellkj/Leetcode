#include <bits/stdc++.h>
using namespace std;


// approach 1
int count_digits(int n){
    int x = n;
    int count =0;
    while( x != 0){
        x = x/10;
        count++;
    }
    return count;
}


// approach 2
// converting integer to string using to_string function


// approach 3
// uisng floor(log base 10 and adding 1 to it)
int main(){
    int n = 12345;
    cout << "The number of digits in the number " << n << " is " << count_digits(n);

    return 0;
}


