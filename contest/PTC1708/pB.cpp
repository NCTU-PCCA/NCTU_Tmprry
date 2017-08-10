#include <bits/stdc++.h>
using namespace std;

unsigned long long f[40];

int main(){
    f[0] = f[1] = 1;
    for (int i=2; i<=33; i++){
        f[i]=0;
        for (int j=1; j<i; j++){
            f[i] += f[j]*f[i-j];
        }
    }

    int T; cin >>T;
    int n;
    while (cin >> n)cout << f[n+1] << endl;
}
