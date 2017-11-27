#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL<<60;
struct Dinic {
    static const int MAXN = 5003;
    struct Edge {
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init() {
        edges.clear();
        for ( int i = 0  ; i < MAXN ; i++ ) {
            G[i].clear();
        }
    }

    void add_edge(int u, int v,  long long cap) {
        edges.push_back((Edge) {u, v, cap, cap});
        edges.push_back((Edge) {v, u, 0, 0LL});
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    bool bfs() {
        memset(d, -1, sizeof(d));
        queue<int> que;
        que.push(s); d[s] = 0;
        while ( !que.empty() ) {
            int u = que.front(); que.pop();
            for ( int ei: G[u] ) {
                Edge &e = edges[ei];
                if ( d[e.v] < 0 && e.rest > 0 ) {
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a) {
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i = cur[u] ; i < (int) G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest));
            if ( f > 0 ) {
                e.rest -= f;
                edges[G[u][i] ^ 1].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 ) break;
            }
        }
        return flow;
    }

    long long maxflow(int s, int t) {
        this->s = s; this->t = t;
        long long flow = 0, mf;
        while ( bfs() ) {
            memset(cur, 0, sizeof(cur));
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }

} dinic;

int n, m, e, s, t;

void solve() {
    dinic.init();
    s = 0, t = 200;
    for ( int i = 0 ; i < e ; i++ ) {
        int u, v;
        cin >> u >> v;
        u++; v++;
        v += n;
        dinic.add_edge(u, v, 1);
    }
    for ( int i= 1 ; i <= n ; i++ ) {
        dinic.add_edge(s, i, 1);
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        dinic.add_edge(i + n, t, 1);
    }
    int fl = dinic.maxflow(s, t);
    cout <<  fl << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    while ( cin >> n && n != 0 ) {
        cin >> m >> e;
        solve();
    }
	return 0;
}
