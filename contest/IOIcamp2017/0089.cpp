#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 900720143;

int n, K, a[MAXN], pre[MAXN]; 
int S[MAXN], dp[MAXN];

void input(){
    scanf("%d %d", &n, &K);

    for (int i=1; i<=n; i++){
        scanf("%d",a+i);
    }
}

int last[MAXN];
void build_pre(){
    memset(last,0,sizeof(last));
    memset(pre,0,sizeof(pre));
    
    for (int i=1; i<=n; i++){
        pre[i] = max(pre[i-1],last[ a[i] ]);
        last[ a[i] ] = i;
    }
}

int z(int x){
    while (x<0)x+=MOD;
    while (x>=MOD)x-=MOD;
    return x;
}

void solve(){
    memset(S,0,sizeof(S));
    for (int i=1; i<=n; i++)dp[i]=!pre[i];
    //for (int i=1; i<=n; i++)printf("%d ",pre[i]); puts("");
    //for (int i=1; i<=n; i++)printf("%d ",dp[i]); puts("");
    for (int i=1; i<=n; i++) S[i] = z(S[i-1]+dp[i]);

    for (int i=2; i<=K; i++){
        for (int j=1; j<=n; j++){
            dp[j] = z(S[j-1]-S[ pre[j]?pre[j]-1:0 ]);
        }
     //   for (int j=1; j<=n; j++)printf("%d ",dp[j]); puts("");
        for (int j=1; j<=n; j++){
            S[j] = z(S[j-1] + dp[j]);
        }
    }
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        build_pre();
        solve();
        cout << z(dp[n]) << endl;
    }
}
