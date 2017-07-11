// 1 base
struct DijkstraTemplate{
typedef long long LL;
typedef pair<LL,int> PLI;
typedef pair<int,LL> PIL; // (to, dis)
static const int MAXN=50005;
static const LL INF=1LL<<62;
int n, m;
vector<PIL> G[MAXN];    // graph 
LL d[MAXN];             // answer
void init(){
    for (int i=0; i<MAXN; i++){
        G[i].clear();
    }
}
bool dijkstra(int from,int to){
	priority_queue<PLI,vector<PLI>,greater<PLI> > pq;
	for(int i=1;i<=n;++i)d[i]=INF;
	d[from]=0;
	pq.push(make_pair(d[from],from));
	while(pq.size()){
		PLI u=pq.top(); pq.pop();
		int x=u.second;
		if(d[x]<u.first)continue;
		for(size_t i=0;i<G[x].size();++i){
			if(d[G[x][i].first]>d[x]+G[x][i].second){
				d[G[x][i].first]=d[x]+G[x][i].second;
				pq.push(make_pair(d[G[x][i].first],G[x][i].first));
			}
		}
	}
	return d[to]==INF?0:1;  //有/無解 
}
}Dijkstra;
