#pragma GCC optimize ("O3")
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string.h>
#include <assert.h>
#define INF 999999999
using namespace std;
struct XDD{
    int to,c;
    friend bool operator < (XDD a, XDD b){
        return a.c > b.c;
    }
};
vector<XDD> G[10005];
vector<int> need;
int ha[100];
int tp;
bool NY[10005],NEED[10005];
char in[10005],*token;
int dis[10][10005];
int n,T;
inline void input(){
    for(int i = 0 ;i <10005 ;i++){G[i].clear();}
    for(int k = 0 ;k < 10;k++)for(int i = 0 ;i < 10005 ; i++){dis[k][i]=INF;}
    memset(NEED,0,sizeof(NEED));
    need.clear();

    int a,b,c;
    if(gets(in)==NULL) exit(0);
    n = atoi(in);
    while(1){}
        gets(in);
        sscanf(in,"%d %d %d",&a,&b,&c);
        //printf("%d %d %d aaa\n",a,b,c);
        G[b].push_back((XDD){a,c});
    }
    gets(in);
    gets(in);
    token=strtok(in," ");
    while(token != NULL){
        a = atoi(token);
        need.push_back(a);
        token=strtok(NULL," ");
        NEED[a]=true;
    }
    gets(in);
    gets(in);
    T = atoi(in);
}
inline void input2(){
    tp = 0;
    gets(in);
    gets(in);
    token=strtok(in," ");
    while(token != NULL){
        int a = atoi(token);
        ha[tp++]=a;
        token=strtok(NULL," ");
    }
}
void GGG(){
    for(int k = 0 ;k < need.size(); k++){
        priority_queue<XDD> que;
        dis[k][need[k] ]=0;que.push( (XDD){need[k],0} );
        while (!que.empty()){
            int L = que.top().c;
            int u = que.top().to;
            que.pop();
            //if (L>=dis[u])continue;
            for (int i=0; i<G[u].size(); i++){
                int v = G[u][i].to;
                int el = G[u][i].c;
                if (dis[k][v]>dis[k][u]+el){
                    dis[k][v] = dis[k][u] + el;
                    que.push( (XDD){v,el+dis[k][u]} );
                }
            }
        }
    }
}
inline void solve(){
    int ans = 0;
    for(int i = 0 ;i < need.size(); i++){
        int tmp = INF;
        for(int j = 0 ;j < tp ; j++){
            tmp = min(tmp,dis[i][ ha[j] ]);
        }
        ans = max(ans,tmp);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("testdata.in","r",stdin);
    freopen("tes.out","w",stdout);

    while(1){
        input();
        GGG();
        while(T--){
            input2();
            solve();
        }
        if(gets(in)==NULL) break;
    }
    //assert(false);
    //puts("GGG");
}
