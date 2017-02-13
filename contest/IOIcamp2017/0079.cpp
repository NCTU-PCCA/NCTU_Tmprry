#include <bits/stdc++.h>
using namespace std;

typedef long long int LL; 

LL gcd(LL a, LL b){
    if (b==0)return a;
    return gcd(b,a%b);
}

LL A, B, C, D;
vector<LL> p;
void build_p(LL N){
    p.clear();
    for (LL i=2; i*i<=N; ++i){
        if (N%i!=0)continue;
        p.push_back(i);
        while (N%i==0)N/=i;
    }
    if (N!=1)p.push_back(N);
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        cin >> A >> B >> C >> D;

        if (C%D!=0 || gcd(B/gcd(B,D),C/D)!=1){
            puts("0");
            continue;
        }
        A = (A-1) / (B/gcd(B,D)) / D;
        C = C/D;
        // 1<=x<=A && gcd(x,C)=1
        build_p(C);

        LL ans = 0;
        for (int i=(1<<p.size())-1; i>=0; i--){
            int cnt=0; LL cc, P=1;
            for (int j=0; j<p.size(); j++)if (i&(1<<j)){
                cnt++;
                P*=p[j];
            }
            cc = A/P;
            if (cnt&1)ans-=cc;
            else ans+=cc;
        }
        cout << ans << endl;
    }
}
