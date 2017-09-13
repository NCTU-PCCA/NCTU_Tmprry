#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10004;
int n, m, c[MAXN];
vector<int> G[MAXN];
bool ok;

void dfs(int u){
	c[u]=1;
	for (int v:G[u]){
		if (c[v]==0)dfs(v);
		else if (c[v]==1)ok=0;
	}
	c[u]=2;
}

int main(){
	int T; cin >> T;
	while (T-- && scanf("%d %d", &n, &m)){
		for (int i=1; i<=n; i++){
			c[i]=0;
			G[i].clear();
		}
		for (int i=0, u, v; i<m; i++){
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}

		ok=1;
		for (int i=1; i<=n; i++)if (c[i]==0){
			dfs(i);
		}
		puts(ok?"VALID":"INVALID");
	}
}
