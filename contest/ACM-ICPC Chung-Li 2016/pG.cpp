#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1<<29;
int n;
vector<int> G[MAXN];

string s;
void input(){
	for (int i=0; i<MAXN; i++)G[i].clear();
	
	getline(cin,s);
	for (int i=1; i<=n; i++){
		getline(cin,s);
		stringstream ss; ss << s;
		while (ss >> s)G[i].push_back( stoi(s) );
	}
}

int ans;
int deep[MAXN];
void dfs(int u, int fa){
	for (int v:G[u])if (v!=fa){
		if (deep[v]==-1){
			deep[v] = deep[u]+1;
			dfs(v,u);
		}
		else {
			int len = deep[u] - deep[v] + 1;
			if (len>=3)ans = min(ans,len);
		}
	}
}

int main(){
	while ( scanf("%d",&n) ){
		if (n==0)return 0;
		input();
		ans=INF;
		memset(deep,-1,sizeof(deep));
		deep[1]=0;
		dfs(1,1);
		if (ans==INF)ans=0;
		printf("%d\n",ans);
	}
}
