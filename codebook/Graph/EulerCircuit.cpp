//CF 723E
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;

struct EDGE{
    int u ,v ;
    int type;
};

int n, m, deg[MAXN];
vector <EDGE> edges;
vector<int> G[MAXN];
bool vis[MAXN*MAXN];
bool alive[MAXN][MAXN];
bool visN[MAXN];
vector<int> ans;

void add_edge(int u, int v, int type=0){
    edges.push_back( EDGE{u,v,type} );
    edges.push_back( EDGE{v,u,type} );
    G[u].push_back( edges.size()-2 );
    G[v].push_back( edges.size()-1 );
    deg[u]++, deg[v]++;
    alive[u][v]=alive[v][u]|=type^1;
}

void input(){
    memset(visN,0,sizeof(visN));
    memset(vis,0,sizeof(vis));
    memset(alive,0,sizeof(alive));
    memset(deg,0,sizeof(deg));
    edges.clear();
    ans.clear();
    for (int i=0; i<MAXN; i++)G[i].clear();

    scanf("%d%d",&n ,&m);
    for (int i=0, u, v; i<m; i++){
        scanf("%d%d", &u, &v);
        add_edge(u,v);
    }
}

void add_Graph(){
    vector<int> tmp;
    for (int i=1; i<=n; i++)if (deg[i]%2==1){
        tmp.push_back(i);
    }
    printf("%d\n",n-tmp.size());
    for (int i=0; i<tmp.size(); i+=2){
        add_edge(tmp[i],tmp[i+1],1);
    }
}

void dfs(int u){
    visN[u]=1;
    for (int i=0; i<G[u].size(); i++)if (!vis[ G[u][i]>>1 ]){
        EDGE &e = edges[ G[u][i] ];
        int v = e.v;
        vis[ G[u][i]>>1 ]=1;
        dfs(v);
    }
    ans.push_back(u);
}

int main(){
    int T; scanf("%d",&T);
    while (T--){
        input();
        add_Graph();
        for (int i=1; i<=n; i++)if (!visN[i]){
            dfs(i);
            for (int j=0 ;j<ans.size()-1; j++){
                int u = ans[j], v=ans[j+1];
                if (alive[u][v]){
                    alive[u][v]=alive[v][u]=0;
                    printf("%d %d\n",u ,v);
                }
            }
            ans.clear();
        }
    }
}
