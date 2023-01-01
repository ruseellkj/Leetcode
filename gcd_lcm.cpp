#include <bits/stdc++.h>
using namespace std;
#define ll long long

// function to get gcd of two numbers
long long gcd(ll A, ll B){
    if(B == 0)
        return A;
    return gcd(B,A%B);
}


// function to get lcm of two numbers
long long lcm(ll A, ll B){
    return (A*B/gcd(A,B));
}



int main(){
    ll A, B;
    cin >> A >> B;
    // ll ans;
    cout << lcm(A,B) << " " << gcd(A,B);

    // alternate approach : method-2
    // for(int i = 1; i<= min(A,B); i++){
    //     if(A%i == 0 && B%i==0){
    //         ans = i;
    //     }
    // }
    // cout << "The gcd of two numbers is " << ans;
}