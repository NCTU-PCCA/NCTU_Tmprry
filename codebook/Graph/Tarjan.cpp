int n;
vector<int> G[MAXN];
stack<int> stk;
int dfn[MAXN], low[MAXN];
bool ins[MAXN];
int scc[MAXN], scn, count;

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

void GetSCC(){
  count = scn = 0;
  for(int i = 0 ; i < n ; i++ ){
    if(!dfn[i]) tarjan(i);
  }
}
