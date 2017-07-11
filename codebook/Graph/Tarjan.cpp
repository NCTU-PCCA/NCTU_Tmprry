// 0 base
struct TarjanSCC{
	static const int MAXN = 1000006;
	int n, dfn[MAXN], low[MAXN], scc[MAXN], scn, count;
	vector<int> G[MAXN];
	stack<int> stk;
	bool ins[MAXN];

	void tarjan(int u){
		dfn[u] = low[u] = ++count;
		stk.push(u);
		ins[u] = true;

		for(auto v:G[u]){
			if(!dfn[v]){
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}else if(ins[v]){
				low[u] = min(low[u], dfn[v]);
			}
		}

		if(dfn[u] == low[u]){
			int v;
			do {
			v = stk.top();
			stk.pop();
			scc[v] = scn;
			ins[v] = false;
			} while(v != u);
			scn++;
		}
	}

	void getSCC(){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(ins,0,sizeof(ins));
		memset(scc,0,sizeof(scc));
		count = scn = 0;
		for(int i = 0 ; i < n ; i++ ){
			if(!dfn[i]) tarjan(i);
		}
	}

}SCC;
