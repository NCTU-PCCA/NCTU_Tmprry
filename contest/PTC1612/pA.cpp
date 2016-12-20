#include <bits/stdc++.h>
using namespace std ;

typedef long long LL;
const LL INF = (1LL)<<62;

int n;
vector<LL> a;
vector<LL> dp[2];

void input(){
    cin >> n;
    a.resize(n);
    for (auto &x:a)cin >> x;
}

void solve(){
    dp[0].resize(n);
    vector<LL> LIS; LIS.push_back(INF);
    for (int i=0; i<n; i++){
        int l=0, r=LIS.size()-1, mid;
        while (l!=r){
            mid = (l+r)>>1;
            if ( LIS[mid]>a[i] )r=mid;
            else l=mid+1;
        }
        if (LIS[l]==INF)LIS.push_back(INF);
        LIS[l] = a[i];
        dp[0][i] = l;
    }
    dp[1].resize(n);
    vector<LL> LDS; LDS.push_back(-INF);
    for (int i=0; i<n; i++){
        int l=0, r=LDS.size()-1, mid;
        while (l!=r){
            mid = (l+r)>>1;
            if ( LDS[mid]<a[i] )r=mid;
            else l=mid+1;
        }
        if (LDS[l]==-INF)LDS.push_back(-INF);
        LDS[l] = a[i];
        dp[1][i] = l;
    }
}
int main(){
    input();
    reverse(a.begin(),a.end());
    solve();
    LL ans = 0 ;
    for (int i=0; i<n; i++){
        ans = max(ans, dp[0][i]+dp[1][i]+1 );
    }
    cout << ans << endl;
}
