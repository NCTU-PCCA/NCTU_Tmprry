#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MAXN = 12;

int n, m;
vector<int> G[MAXN];
int dp[1<<MAXN];
bool inque[1<<MAXN];

void input(){
	for (int i=0; i<MAXN; i++)G[i].clear();

	scanf("%d%d", &n, &m);
	n/=2;
	for (int i=0, u, v; i<m; i++){
		scanf("%d %d", &u, &v);
		u-=1, v-=n+1;
		G[u].push_back(v);	
	}
}


void solve(){
	memset(dp,0,sizeof(dp));
	memset(inque,0,sizeof(inque));
	queue< pii > que;
	dp[ (1<<n)-1 ] = 1;
	que.push( (pii){0,(1<<n)-1} );
	
	while (!que.empty()){
		int u = que.front().first;
		if (u==n)return;
		int S = que.front().second;
		que.pop();

		for (int v:G[u]){
			int vs = (1<<v);
			if (S&vs){
				dp[S^vs] ^= dp[S];
				if (!inque[S^vs])que.push((pii){u+1,S^vs}), inque[S^vs]=1;
			}
		}
	}
}

int main(){
	int T; scanf("%d",&T);

	while (T--){
		input();
		solve();
		printf("%d\n",dp[0]^1);
	}
}
