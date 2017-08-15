#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;
struct edge {
    int id, to, cost;
};

int n, q, s;
int a[MAXN], b[MAXN], w[MAXN];
int type[MAXQ];
int x[MAXQ], t[MAXQ];

vector<edge> G[MAXN];
int root;
int vs[MAXN*2];
int depth[MAXN*2];
int id[MAXN];
int es[MAXN *2];

typedef pair<int, int> pii;

void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0 ; i < G[v].size() ; i++ ) {
        edge &e = G[v][i];
        if ( e.to != p ) {
            add(k, e.cost);
            es[e.id * 2] = k;
            dfs(e.to, v, d+1, k);
            vs[k] = v;
            depth[k++] = d;
            add(k, -e.cost);
            es[e.id*2 + 1] = k;
        }
    }
}

int stack_v[MAXN+10];
int stack_i[MAXN+10];

void init(int v) {
    bit_n = (v-1) * 2;
    int k = 0;
    dfs(root, -1, 0, k);
    rmq_init(depth, v*2 - 1);
}

int bit[MAXN * 2];

void add(int i, int val) {
    while ( i < MAXN ) {
        bit[i] += val;
        i += i&(-i);
    }
}

long long query(int i) {
    long long rr = 0;
    while (i > 0) {
        rr += bit[i];
        i -= i & (-i);
        
    }
    return rr;
}

int lca(int u, int v) {
    return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}

void solve() {
    memset(bit, 0, sizeof(bit));
    root = n / 2;
    for (int i = 0 ; i < n - 1; i ++) {
        G[a[i]].push_back((edge){i, b[i], w[i]});
        G[b[i]].push_back((edge){i, a[i], w[i]});
    }
    init(n);


    int v = 0;
    vector<pii> vvv;
    int kkk;
    scanf("%d", &kkk);
    for (int i = 0 ; i < kkk ; i++) {
        pii tmp;
        scanf("%d", &tmp.second);
        tmp.first = id[tmp.second];
        vvv.push_back(tmp);
    }
    long long res = 0;
    int v = vvv[0].second;
    for (int i = 1 ; i < q ; i++ ) {
        int u = vvv[i].second;
        int p = lca(u, v);
        res = (sum(id[v]) + sum(id[u]) - sum(id[p]) * 2)*i+res+res;
        v = u;
    }
    cout << res * 2 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 0 ; i < n - 1 ; i++ ) {
            scanf("%d %d", &a[i], &b[i]);
            w[i] = 1;
        }
        solve();
    }

}
