#include <bits/stdc++.h>
using namespace std;

const int MAXV = 2003;
const double INF = 1e9;

struct Edge{
    int from, to, dis, v;
    double t;
};
vector<Edge> edges;
vector<int> G[MAXV]; int V;

void add_edge(int u, int v, int dis, int v1, int v2){
    edges.push_back((Edge){u,v,dis,v1,(double)dis/v1});
    edges.push_back((Edge){v,u,dis,v2,(double)dis/v2});
    G[u].push_back( edges.size()-2 );
    G[v].push_back( edges.size()-1 );
}

map< pair<int,int> , vector< pair< pair<int,int> ,int> > > Fuck;
// u ,v ,len edgeid id

int new_vertex(int u, int v, int len){
    for (int i=0; i<edges.size(); i++){
        const auto &e = edges[i];
        if (e.from==u && e.to==v){
            if (len>e.dis)break;
            int id = V++;
            add_edge(id,v,e.dis-len,e.v,edges[i^1].v);
            add_edge(u,id,len,e.v,edges[i^1].v);

            int j=i;
            if (u>v){
                len = e.dis-len;
                swap(u,v);
                j^=1;
            }
            // u < v
            Fuck[ make_pair(u,v) ].push_back( make_pair( make_pair(len,j) ,id) );

            return V-1;
        }
    }
    return -1;
    puts("Error");
}

double dis[MAXV];
int pre[MAXV];
double Dijkstra(int s, int t){
    typedef pair<double,int> pdi;
    priority_queue<pdi, vector<pdi> ,greater<pdi> > que;
    for (int i=0 ;i<MAXV; i++)dis[i] = INF, pre[i] = -1;
    dis[s]=0.0; que.push( make_pair(0.0,s) );
    while (!que.empty()){
        double L = que.top().first;
        int u = que.top().second;
        que.pop();
        //if (L>=dis[u])continue;
        for (int i=0; i<G[u].size(); i++){
            int v = edges[ G[u][i] ].to;
            double el = edges[ G[u][i] ].t;
            if (dis[v]>dis[u]+el){
                dis[v] = dis[u] + el;
                pre[v] = u;
                que.push( make_pair(dis[v],v) );
            }
        }
    }
    return dis[t];
}

int Car[MAXV] ,Pes[MAXV];
int Boss;

void build(){
    for (auto www:Fuck){
        auto &vec = www.second;

        for (int i=0; i<vec.size(); i++){
            for (int j=i+1; j<vec.size(); j++){
                int u= vec[i].second;
                int v= vec[j].second;
                int v1 = edges[ vec[j].first.second ].v;
                int v2 = edges[ vec[j].first.second^1 ].v;
                int L1 = vec[i].first.first;
                int L2 = vec[j].first.first;
                if (L1>L2){
                    swap(L1,L2);
                    swap(u,v);
                    swap(v1,v2);
                }
                add_edge(u,v,L2-L1,v1,v2);
            }
        }
    }
}

void input(){
    edges.clear();
    for (int i=0; i<MAXV; i++)G[i].clear();
    V = 1001;
    memset(Car,-1,sizeof(Car));
    memset(Pes,-1,sizeof(Pes));


    int cmd;
    while (cin >> cmd && cmd!=0){
        if (cmd==1){
            int u, v, dis ,v1 ,v2;
            cin >> u >> v >> dis >> v1 >> v2;
            add_edge(u,v,dis,v1,v2);
        }
        else if (cmd==2){
            int car_id, u, v, len, ss;
            cin >> car_id >> u >> v >> len >> ss;
            Car[car_id] = new_vertex(u,v,len);

            if (ss==1){
                int v3, v4, len2;
                cin >> v3 >> v4 >> len2;
                Pes[car_id] = new_vertex(v3,v4,len2);
            }
            else Pes[car_id]=-1;
        }
        else if (cmd==3){
            int u, v, len;
            cin >> u >> v >> len;
            Boss = new_vertex(u,v,len);
        }
    }
    build();
}

int Ca;
double AL = INF ;
vector<int> Path;
void solve(){
    AL=INF;
    Path.clear();
    double dd;
    for (int i=0; i<=100; i++)if (Car[i]!=-1){
        if (Pes[i]==-1){
            if ((dd=Dijkstra(Car[i],Boss))<AL){
                Ca = i;
                AL = dd;
                Path.clear();
                int w=pre[Boss];
                while (pre[w]!=-1){
                    Path.push_back(w);
                    w=pre[w];
                }
            }
        }
        else { // have person
            if ((dd=Dijkstra(Car[i],Pes[i])+Dijkstra(Pes[i],Boss))<AL){
                Ca=i;
                AL=dd;
                Dijkstra(Pes[i],Boss);
                Path.clear();
                int w=pre[Boss];
                while (pre[w]!=-1){
                    Path.push_back(w);
                    w=pre[w];
                }

                Dijkstra(Car[i],Pes[i]);
                w = pre[ Pes[i] ];
                while (pre[w]!=-1){
                    Path.push_back(w);
                    w=pre[w];
                }
                //Path.push(Car[i]);
            }
        }
    }
    reverse(Path.begin(),Path.end());
    printf("%d\n",Ca);
    for (int station : Path)if (station<=1000)printf("%d ",station); puts("");
    printf("%.f\n",AL);
}

int main(){
    freopen("data3.txt","r",stdin);
    int T; cin >> T;
    while (T--){
        input();
        solve();
    }
}
