#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

int n, m;
int C[3][3], A[MAXN][MAXN];
int dp[MAXN][MAXN];

void input(){
	scanf("%d %d",&n ,&m);
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			scanf("%d",&C[i][j]);
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d",&A[i][j]);
		}
	}
}

void solve(){
	dp[0][0]=0;
	for (int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + C[ A[i][0] ][ A[i-1][0] ];
	for (int i=1; i<m; i++) dp[0][i] = dp[0][i-1] + C[ A[0][i] ][ A[0][i-1] ];

	for (int i=1; i<n; i++){
		for (int j=1; j<m; j++){
			dp[i][j]=0;
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] + C[ A[i][j] ][ A[i-1][j-1] ] );
			dp[i][j] = max(dp[i][j], dp[i][j-1] + C[ A[i][j] ][ A[i][j-1] ] );
			dp[i][j] = max(dp[i][j], dp[i-1][j] + C[ A[i][j] ][ A[i-1][j] ] );
		}
	}

	printf("%d\n",dp[n-1][m-1]);
}

int main(){
	input();
	solve();
}
