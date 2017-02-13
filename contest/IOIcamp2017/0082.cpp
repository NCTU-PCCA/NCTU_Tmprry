#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
const long long int INF = (1LL<<60);
int n, m, a[MAXN];
long long int dp[2][MAXN][MAXN];

void input(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
}

void solve(){
    dp[0][0][0]=0;
    dp[1][0][0]=-INF;
    for (int j=1; j<=n; j++){
        dp[0][0][j]=dp[0][0][j-1]+a[j];
        dp[1][0][j]=-INF;
    }
    for (int i=1; i<=m; i++){
        dp[0][i][0]=dp[1][i][0]=0;

        for (int j=1; j<=n; j++){
            dp[0][i][j] = max( dp[0][i][j-1]+a[j], dp[1][i][j-1]+2LL*a[j]);
            dp[1][i][j] = max( dp[0][i-1][j-1]+2LL*a[j], dp[1][i-1][j-1]+4LL*a[j]);
        }
    }

    printf("%lld\n",max(dp[0][m][n],dp[1][m][n]));
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        solve();
    }
}
