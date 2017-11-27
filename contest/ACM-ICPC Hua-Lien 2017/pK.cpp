#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
int n, m;
vector <int> G[MAXN];

int time_stamp;
vector<int> S;
bool vis[MAXN];
int din[MAXN];
int c[MAXN];
int par[MAXN];

void dfs(int u){
    din[u] = time_stamp++;
    S.push_back(u);
    vis[u]=1;
    for (int v:G[u]){
        if (vis[v])continue;
        par[v]=u;
        dfs(v);
    }
}

void input(){
    scanf("%d %d",&n,&m);

    for(int i = 0 ;i < n ;i++) {
        G[i].clear();
        vis[i] = false;
        c[i]=0;
    }
    for(int i = 0 ,a ,b;i < m ;i++){
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

bool dog(int i){
    int u = S[i];
    for (int v:G[ S[i] ]){
        if (din[v]<din[u]){
            if (c[u] == c[v]) return 0;
        }
    }
    if (i==n-1)return 1;
    bool ok=0;
    if (c[ par[S[i+1]] ]!=1){
        c[ S[i+1] ] = 1;
        ok |= dog(i+1);
    }
    if (c[ par[S[i+1]] ]!=2){
        c[ S[i+1] ] = 2;
        ok |= dog(i+1);
    }
    if (c[ par[S[i+1]] ]!=3){
        c[ S[i+1] ] = 3;
        ok |= dog(i+1);
    }
    return ok;
}

void solve(){
    S.clear();
    time_stamp=0;
    for (int i=0; i<n; i++){
        if (!vis[i]){
            par[i]=0;
            dfs(i);
        }
    }
    c[0] = 1;
    puts(dog(0)?"Y":"N");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        input();
        solve();
    }
	return 0;
}
