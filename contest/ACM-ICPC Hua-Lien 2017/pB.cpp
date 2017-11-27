#include <bits/stdc++.h>
using namespace std;

const int MAXN = 302;
int n, ans;
int d[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- && cin >> n){

        for (int i=n*(n-1)/2; i>0; i--){
            int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = w;
        }

        ans = d[1][2] + d[2][3] + d[3][1];
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++)if (j!=i){
                for (int k=1; k<=n; k++)if (k!=j && k!=i){
                    ans = max(ans,d[i][j]+d[j][k]+d[k][i]);
                }
            }
        }
        cout << ans <<'\n';
    }
	return 0;
}
