#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int POW(int a, int n, int mod){
	int re=1;
	while (n){
		if (n&1) re = (long long)re*a%mod;
		a = (long long)a*a%mod;
		n>>=1;
	}
	return re;
}

int inv(int x){
	x %= MOD;
	return POW(x,MOD-2,MOD);
}

const int MAXN = 50004;
int n, m;
int dp[MAXN], ans[MAXN];
vector<int> G[MAXN];

void pullfs(int u, int fa=-1){
	dp[u]=1;
	for (int v:G[u])if (v!=fa){
		pullfs(v,u);
		dp[u] = (long long)dp[u]*(dp[v]+1)%MOD;
	}
}

void pushfs(int u, int fa=-1){
	for (int v:G[u])if (v!=fa){
		ans[v] = (long long) ans[v] * ((long long) ans[u] * inv(dp[v]+1) % MOD + 1) %MOD;
		pushfs(v,u);
	}
}

int main(){
	int T; cin >> T;

	while (T-- && cin >> n){
		for (int i=1; i<=n; i++){
			G[i].clear();
			dp[i]=ans[i]=0;
		}
		for (int u=2, v; u<=n; u++){
			scanf("%d", &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		pullfs(1);
		for (int i=1; i<=n; i++)ans[i]=dp[i];
		pushfs(1);
		
		int sum=0;
		for (int i=1; i<=n; i++){
			sum = (sum+ans[i])%MOD;
		}
		printf("%d\n",sum);
	}
}
