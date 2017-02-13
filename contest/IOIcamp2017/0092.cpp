#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
vector<int> G[MAXN];

void input(){
    scanf("%d",&n);
    
    for (int i=1; i<=n; i++)G[i].clear();

    for (int i=1, u, v; i<n; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

vector<int> leaf;

void dfs(int u, int fa){
    if (G[u].size()==1)leaf.push_back(u);

    for (int v:G[u])if (v!=fa){
        dfs(v,u);
    }
}

void solve(){
    int m = leaf.size();
    printf("%d\n", (m+1)/2);

    if (m%2==1){
        printf("%d %d\n", leaf[0], leaf[m-1]);
        m--;
    }
    for (int i=0, j=m/2; j<m; i++, j++){
        printf("%d %d\n", leaf[i], leaf[j]);
    }
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        leaf.clear();
        for (int i=1; i<=n; i++){
            if (G[i].size()>1){
                dfs(i,i);
                break;
            }
        }
        solve();
    }
}
