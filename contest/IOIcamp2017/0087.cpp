#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,Q,a,b,c,d;
int tin[N+5], tout[N+5], timer;
int par[N+5][25];
vector<int> vct[N+5];
void DFs(int x,int px){
    par[x][0] = px;
    tin[x] = ++timer;
    for(int to:vct[x]) if(to!=px){
        DFs(to,x);
    }
    tout[x] = ++timer;
}
void Build(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            par[i][j] = par[par[i][j-1]][j-1];
}
void Init(){
    timer=0;
    for(int i=1;i<=n;i++) vct[i].clear();
}
inline bool anc(int x,int y){ // return x is y's son
    return tin[x]<=tin[y]
         &&tout[y]<=tout[x];
}
int LCA(int x,int y){
    if( anc(y,x) ) return y;
    for(int j=20;j>=0;j--)
        if( !anc( par[y][j], x ) ) y = par[y][j];
    return par[y][0];
}
int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&Q);
        Init();
        for(int i=1,u,v;i<n;i++){
            scanf("%d%d",&u,&v);
            vct[u].push_back(v);
            vct[v].push_back(u);
        }
        DFs(1,1); Build();
        while(Q--){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            /*
            int lcf = LCA(a,b), lcs = LCA(c,d), lct = LCA(lcf,lcs);
            if( lct==lcf||lct==lcs ) puts("tsan");
            else puts("hao");
            */
            int A=LCA(a,b);
            int B=LCA(c,d);
            //printf("HI %d %d %d %d %d %d\n",A,B,a,b,c,d);
            if ( anc(B,A) && (anc(A,c) || anc(A,d)) )puts("tsan");
            else if ( anc(A,B) && (anc(B,a) || anc(B,b)) )puts("tsan");
            else puts("hao");
        }
    }
    return 0;
}

