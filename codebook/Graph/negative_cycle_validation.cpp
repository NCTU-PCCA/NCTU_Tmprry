#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;
const int MAXN = 200;
int n, m, q;
int d[MAXN][MAXN];

int main () {
    while ( cin >> n >> m >> q && n) {
        
        for ( int i = 0 ; i <= n ; i++ ) {
            for ( int j = 0 ; j <= n ; j++ ) d[i][j] = (i==j ? 0 : INF);
        }

        for ( int i = 0 ; i < m ; i++ ) {
            int a, b, c;
            cin >> a >> b >> c;
            d[a][b] = min(d[a][b], c);
        }

        for ( int k = 0 ; k < n ; k++ ) {
            for ( int i = 0 ; i < n ; i++ ) {
                for ( int j = 0 ; j < n ; j++ ) {

                    if ( d[i][j] > d[i][k] + d[k][j] && d[i][k] < INF && d[k][j] < INF ) {
                        //printf("%d > %d + %d\n", d[i][j], d[i][k], d[k][j]);
                        //if ( d[i][k] >= INF || d[k][j] >= INF ) cout << "NO : " << i << " " << j << " " << k << "--"; 
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                for ( int k = 0 ; k < n && d[i][j] != -INF ; k++ ) {
                    if ( d[k][k] < 0 && d[i][k] != INF && d[k][j] != INF  ) 
                        d[i][j] = -INF;
                }
            }
        }
        int u, v;
        for (int i=0;i<q;i++){
            scanf("%d%d",&u,&v);

            if (d[u][v] == INF) printf("Impossible\n");
            else if (d[u][v] == -INF) printf("-Infinity\n");
            else printf("%d\n",d[u][v]);
        }
        puts("");
    }
    return 0;
}