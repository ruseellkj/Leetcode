#include <bits/stdc++.h>
using namespace std;


int reverse_int(int n){
    int x = n;
    int reverse =0;
    while(x !=0){
        int d = x%10;
        reverse = reverse*10 + d;
        x = x/10;
    }
    return reverse;
}
int main(){
    int n;
    cin >> n;
    cout << reverse_int(n);

    return 0;

}