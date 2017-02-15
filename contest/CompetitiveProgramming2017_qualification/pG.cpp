#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b==0)return a;
    return gcd(b,a%b);
}

int phi(int m){
    int re=m;
    for (int i=2; i*i<=m; i++){
        if (m%i==0){
            re-=re/i;
            while (m%i==0)m/=i;
        }
    }
    if (m>1) re-=re/m;
    return re;
}

int POW(int a, int n, int mod){
    int re=1%mod;

    while (n>0){
        if (n&1)re=(long long)re*a%mod;
        a=(long long)a*a%mod;
        n>>=1;
    }

    return re;
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        int n, m; cin >> n >> m;
        if (gcd(n,m)!=1)cout << -1 << endl;
        else {
            int ans = POW(n,phi(m)-1,m);
            cout << ans << endl;
            assert((long long)ans*n%m==1LL);
        }
    }
}
