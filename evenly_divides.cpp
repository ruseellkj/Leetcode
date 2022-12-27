#include <bits/stdc++.h>
using namespace std;

int evenly_divides(int N){
    int x = N;
    int count = 0;
    while(x!=0){
        int d = x%10;
        x = x/10;
        if(d>0 && N%d == 0){
            count++;
        }
    }
    return count;
}
int main(){
    int N;
    cin >> N;
    cout << "count of number " << N << " is " << evenly_divides(N);

    return 0;
}