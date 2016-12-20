#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 12;

int trans[MAXN][1<<MAXN];
int n, m, K;
LL dp[MAXN+1][1<<MAXN];

void build_trans(){
    for (int i=(1<<MAXN)-1; i>=0; i--){
        for (int j=0; j<MAXN; j++){
            int next=i;
            for (int k=j; k<MAXN; k++){
                if ((i>>k)&1){
                    next ^= (1<<k);
                    break;
                }
            }
            next^=(1<<j);
            trans[j][i]=next;
        }
    }
}

int main(){
    build_trans();

    int T; scanf("%d",&T );
    while (T--){
        scanf("%d%d%d",&n, &m, &K);

        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1; i<=n; i++){
            for (int j=(1<<m)-1; j>=0; j--){
                for (int k=0; k<m; k++){
                    dp[i][ trans[k][j] ] += dp[i-1][j];
                }
            }
        }
        LL ans=0;
        for (int i=(1<<m)-1; i>=0; i--){
            if (__builtin_popcount(i)==K)ans+=dp[n][i];
        }
        printf("%lld\n",ans);
    }
}
