#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int N;
vector<int> G[MAXN];

long long int sz[MAXN], ans[MAXN];

void input(){
    scanf("%d",&N);
    for (int i=1; i<=N; i++)G[i].clear();

    for (int i=2, fa; i<=N; i++){
        scanf("%d",&fa);
        G[fa].push_back(i);
    }
}

void dfssz(int u){
    sz[u]=1LL;
    for (int v:G[u]){
        dfssz(v);
        sz[u]+=sz[v];
    }
    ans[u]=sz[u];
    for (int v:G[u]){
        ans[u] += sz[v]*(sz[u]-sz[v]);
    }
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        dfssz(1);
        for (int i=1; i<=N; i++){
            printf("%lld",ans[i]);
            if (i==N)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
