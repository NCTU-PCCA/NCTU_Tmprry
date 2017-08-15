#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;
int a, b, p, J[10004];//, inv[10004];

int POW(int a, int n){
    int re=1;
    while (n>0){
        if (n&1)re = (LL)re * a %MOD;
        n>>=1;
        a= (LL)a*a%MOD;
    }
    return re;
}

int inv(int x){
    return POW(x,MOD-2);
}

void build(){
    J[0]=1;
    for (int i=1; i<p; i++){
        J[i] = (LL)J[i-1]*i%MOD;
    }
}

int C(int n, int m){    // C(n,m)%MOD, (n,m<p)
    if (m<0 || m>n)return 0;
    if (m==0 || m==n)return 1;

    int ans = J[n];
    ans = (LL) ans * inv( J[m] ) %MOD;
    ans = (LL) ans * inv( J[n-m] ) %MOD;

    return ans;
}

int cal(int n ,int m){
    if (n==0 && m==0)return 1;
    return (LL) C(n%p,m%p) * cal(n/p,m/p) % MOD;
}

int main(){
    int T; cin >>T;
    while (T--){
        scanf("%d %d %d", &a, &b, &p); 
        build();
        printf("%d\n", cal(a,b));
    }
}
