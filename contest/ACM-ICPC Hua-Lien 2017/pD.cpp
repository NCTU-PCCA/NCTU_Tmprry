#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202;
const int INF = 1<<29;
int n, m, d[MAXN][MAXN], cnt[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n!=0){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                d[i][j] = INF;
            }
            d[i][i]=0;
        }

        cin >> m;
        for (int i=0, u, v; i<m; i++){
            cin >> u >> v;
            d[u][v] = d[v][u] = 1;
        }

        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }

        memset(cnt,0,sizeof(cnt));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)if (i!=j){
                cnt[ d[i][j] ]++;
            }
        }

        for (int i=1; i<=n; i++)if (cnt[i]){
            cout << i << ' ' << cnt[i] << '\n';
        }
    }

	return 0;
}
