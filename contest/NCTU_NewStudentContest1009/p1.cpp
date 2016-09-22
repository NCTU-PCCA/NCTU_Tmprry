#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, m, sum;
vector<LL> a;

void input(){
    cin >> n >> m;
    sum=0;
    a.resize(n);
    for (int i=0; i<n; i++){
        string ss;
        cin >> ss >> a[i];
        sum += a[i];
    }
}

LL Cnm(LL x, LL y){
    LL ans=1;
    for (LL i=0; i<y; i++){
        ans *= (x-i);
        ans /= (i+1);
    }
    return ans;
}

void solve(){
    sort(a.begin(),a.end());
    LL mi=0, mx=0;
    for (LL i=0; i<m; i++){
        mi += a[i];
        mx += a[n-i-1];
    }
    LL p = Cnm(n,m);
    LL S = p*m*sum/n;
    printf("%lld %lld %lld\n", mi, mx, S);
}

int main(){
    //freopen("data15.txt","r",stdin);
    input();
    solve();
}
