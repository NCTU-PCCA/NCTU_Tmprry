#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
using namespace std;
vector<int> G[50], GG[50];
int n,m;
int in[50];
int inin[50];
int ans[50];
int start,tp;
bool NY[50];
bool wak[50];
void input(){
    for(int i = 0 ;i < 50 ;i++){
        inin[i]=in[i] =0;
        wak[i]=NY[i]=false;
        G[i].clear();
        GG[i].clear();
		ans [i] = 0;
    }
    scanf("%d",&n);
    if(n == 0) exit(0);
    scanf("%d", &m);
    tp = m;
    int a, b;
    for(int i = 0 ;i < m ;i++){
        scanf("%d %d",&a ,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        in[a] ++;  in[b] ++;
    }
    for(int i = 1 ;i <= n ;i++){
        if(in[i] > 1) NY[i]=true;
    }
    for(int i = 1 ;i <=n ;i++){
        if(NY[i]){
            for(int j = 0;j < G[i].size(); j++){
                if(NY[ G[i][j] ]){
                    GG[i].push_back(G[i][j]);
                    inin[i]++;
                }
            }
        }
    }
    for(int i = 1 ;i <= n ;i++){
        if(GG[i].size() == 1)    {
            start = i;
            ans[i] = 0;
            break;
        }
    }
}
void dfs(int now, int lv){
    wak[now]=true;
    for(int i = 0 ;i < G[now].size() ;i++)    {
        int next = G[now][i];
        if(!NY[next]){
            ans[next] = ans[now]+lv*tp;
            tp--;
        }
    }
    for(int i = 0 ;i < GG[now].size() ;i++){
        int next = GG[now][i];
        if(!wak[next]){
            ans[next] = ans[now]+lv*tp;
            tp--;
            dfs(next,-lv);
        }
    }

}
void solve(){
	if(n == 2){
		puts("0 1");
		return ;
	}
    dfs(start,1);
    for(int i = 1 ;i < n; i++){
        printf("%d ",ans[i]);
    }
	printf("%d",ans[n]);
    puts("");
}
int main(){
    while(1){
        input();
        solve();
    }
}
