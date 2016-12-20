#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL POW(LL a, LL n, LL MOD){
    LL re=1;
    while (n>0){
        if (n&1)re=re*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return re;
}

LL solve(LL k, LL L){
    if (L==0)return 0;
    if (k==1)return 3%(1LL<<L);
    return POW(3,solve(k-1,L-1),1LL<<L);
}

int main(){
    int T; scanf("%d",&T);
    while (T--){
        LL k, L; cin >> k >> L;
        printf("%lld\n",solve(k,L));
    }
}
