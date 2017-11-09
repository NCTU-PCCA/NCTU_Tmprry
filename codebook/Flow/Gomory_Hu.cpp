Construct of Gomory Hu Tree

1. make sure the whole graph is clear
2. set node 0 as root, also be the parent of other nodes.
3. for every node i > 0, we run maxflow from i to parent[i]
4. hense we know the weight between i and parent[i]
5. for each node j > i, if j is at the same side with i,
   make the parent of j as i
-------------------------------------------------------

int e[MAXN][MAXN];
int p[MAXN]; 
void gomory_hu() {
    fill(p, p+n, 0);
    fill(e[0], e[n], -1);
    for ( int i = 1 ; i < n ; i++ ) {
        init(n); // the first step
        int tmp = flow.max_flow(i, p[i]);
        e[i][p[i]] = e[p[i]][i] = tmp;
        for ( int j = i + 1 ; j < n ; j++ ) {
            if ( flow.used[j] && p[i] == p[j] ) p[j] = i;
        }
    }
}
