#include<cstdio>
#include<cstdlib>
#include<cstring>
const int maxn = 105;
int best;
int m ,n;
int num[maxn];
// int x[maxn];
int path[maxn];
int g[maxn][maxn];

bool dfs( int *adj, int total, int cnt ){
    int i, j, k;
    int t[maxn];
    if( total == 0 ){
        if( best < cnt ){
            // for( i = 0; i < cnt; i++) path[i] = x[i];
            best = cnt; return true;
        }
        return false;
    }
    for( i = 0; i < total; i++){
        if( cnt+(total-i) <= best ) return false;
        if( cnt+num[adj[i]] <= best ) return false;
        // x[cnt] = adj[i];
        for( k = 0, j = i+1; j < total; j++ )
            if( g[ adj[i] ][ adj[j] ] )
                t[ k++ ] = adj[j];
                if( dfs( t, k, cnt+1 ) ) return true;
    } return false;
}
int MaximumClique(){
    int i, j, k;
    int adj[maxn];
    if( n <= 0 ) return 0;
    best = 0;
    for( i = n-1; i >= 0; i-- ){
        // x[0] = i;
        for( k = 0, j = i+1; j < n; j++ )
            if( g[i][j] ) adj[k++] = j;
        dfs( adj, k, 1 );
        num[i] = best;
    }
    return best;
}

void input(){
    for(int i = 0 ; i < maxn ;i++)for(int j = 0 ; j < maxn ;j++)g[i][j]=1;
    scanf("%d %d", &m, &n);
    int a ,b;
    for(int i = 0; i < m ;i++){
        scanf("%d %d", &a, &b);
        g[b][a]=g[a][b]=0;
    }
}
int main(){
    input();
    int ans = MaximumClique();
    printf("%d\n",ans);
}
