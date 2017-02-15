#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(int a, int b){
    if (b==0)return a;
    return gcd(b,a%b);
}

LL f(int n, int m){
    return (2LL*n+1LL)*(2LL*m+1LL)-5LL+2LL*((LL)(n-1)*(m-1)-gcd(n,m)+1);
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        int n, m; cin >> n >> m;
        n--,m--;
        unsigned long long ans=0;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                ans += f(i+1,j+1)*(LL)(n-i)*(LL)(m-j);
            }
        }
        cout << ans << endl;
    }
}
