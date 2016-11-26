#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 1003;
int n, k;
int in[MAXN];
int dp[MAXN][MAXN];
void input(){
	scanf("%d %d",&n, &k);
	for(int i = 1 ;i <= n ;i++) scanf("%d",&in[i]);
}
void solve(){
	int ans = 0;
	for(int i = 0 ;i < MAXN ;i++) for(int j = 0 ;j < MAXN ;j++) dp[i][j]=0;
//	for(int i = 0 ;i < MAXN ;i++) dp[i][0] = 0;
	for(int j = 1 ;j <= k ;j++ ){
		for(int i = 2 ;i <= n; i++){
			dp[i][j]=max(dp[i][j], dp[i-1][j] + ( in[i]-in[i-1] ));
			dp[i][j]=max(dp[i][j], dp[i-2][j-1] + (in[i]-in[i-1] ));
			if(j <= k) ans = max(ans, dp[i][j]);
		}
		for(int i = 1; i <= n ;i++){
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	printf("%d",ans);
	if(ans != 0 ) printf("000");
	puts("");
	
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		solve();
	}
}
