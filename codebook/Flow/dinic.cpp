struct Edge{
	int from, to, cap, flow;
};

const int INF = 1<<29;
const int MAXV = 5003;
struct Dinic{	//O(VVE)
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[MAXV];
	bool vis[MAXV];
	int d[MAXV];
	int cur[MAXV];

	void AddEdge(int from, int to, int cap){
		edges.push_back( {from,to,cap,0} );
		edges.push_back( {to,from,0,0} );
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	
	bool dinicBFS(){
		memset(vis,0,sizeof(vis));
		queue<int> que;
		que.push(s); vis[s]=1;
		while (!que.empty()){
			int u = que.front(); que.pop();
			for (int ei:G[u]){
				Edge &e = edges[ei];
				if (!vis[e.to] && e.cap>e.flow ){
					vis[e.to]=1;
					d[e.to] = d[u]+1;
					que.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int dinicDFS(int u, int a){
		if (u==t || a==0)return a;
		int flow=0, f;
		for (int &i=cur[u]; i<(int)G[u].size(); i++){
			Edge &e = edges[ G[u][i] ];
			if (d[u]+1!=d[e.to])continue;
			f = dinicDFS(e.to, min(a, e.cap-e.flow) );
			if (f>0){
				e.flow += f;
				edges[ G[u][i]^1 ].flow -=f;
				flow += f;
				a -= f;
				if (a==0)break;
			}
		}
		return flow;
	}

	int maxflow(int s, int t){
		this->s = s, this->t = t;
		int flow=0, mf;
		while ( dinicBFS() ){
			memset(cur,0,sizeof(cur));
			while ( (mf=diniDFS(s,INF)) )flow+=mf;
		}
		return flow;
	}
};
