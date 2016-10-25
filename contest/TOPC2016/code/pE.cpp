#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100005;
int n ,m;
struct XDD{
    int x, y, id;
}po[MAXN],po2[MAXN];
struct BAN{
    int a,b,c;
    friend bool operator <(BAN a, BAN b){
        return a.c < b.c;
    }
};
vector<BAN> ban; // E
auto &E=ban;

bool cmp1(XDD a,XDD b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
bool cmp2(XDD a,XDD b){
    if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}
void input(){
    ban.clear();
    scanf("%d",&n);
    int a,b;
    for(int i = 0 ;i < n ;i++){
        scanf("%d %d",&a,&b);
        po[i].x=a;
        po[i].y=b;
        po[i].id=i;
        po2[i].x=a;
        po2[i].y=b;
        po2[i].id=i;
    }
    sort(po,po+n,cmp1);
    for(int i = 0 ;i < n-2 ;i++){
        ban.push_back((BAN){po[i].id,po[i+1].id,abs(po2[po[i].id].x-po2[po[i+1].id].x)+abs(po2[po[i].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i+2].id,po[i+1].id,abs(po2[po[i+2].id].x-po2[po[i+1].id].x)+abs(po2[po[i+2].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i].id,po[i+2].id,abs(po2[po[i].id].x-po2[po[i+2].id].x)+abs(po2[po[i].id].y-po2[po[i+2].id].y)});
    }
    sort(po,po+n,cmp2);
    for(int i = 0 ;i < n-2 ;i++){
        ban.push_back((BAN){po[i].id,po[i+1].id,abs(po2[po[i].id].x-po2[po[i+1].id].x)+abs(po2[po[i].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i+2].id,po[i+1].id,abs(po2[po[i+2].id].x-po2[po[i+1].id].x)+abs(po2[po[i+2].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i].id,po[i+2].id,abs(po2[po[i].id].x-po2[po[i+2].id].x)+abs(po2[po[i].id].y-po2[po[i+2].id].y)});
    }
    for(int i = 0 ;i < n ;i++){
        int tx=po[i].x;
        int ty=po[i].y;
        po[i].x=tx+ty;
        po[i].y=tx-ty;
    }
    sort(po,po+n,cmp1);
    for(int i = 0 ;i < n-2 ;i++){
        ban.push_back((BAN){po[i].id,po[i+1].id,abs(po2[po[i].id].x-po2[po[i+1].id].x)+abs(po2[po[i].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i+2].id,po[i+1].id,abs(po2[po[i+2].id].x-po2[po[i+1].id].x)+abs(po2[po[i+2].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i].id,po[i+2].id,abs(po2[po[i].id].x-po2[po[i+2].id].x)+abs(po2[po[i].id].y-po2[po[i+2].id].y)});
    }
    sort(po,po+n,cmp2);
    for(int i = 0 ;i < n-2 ;i++){
        ban.push_back((BAN){po[i].id,po[i+1].id,abs(po2[po[i].id].x-po2[po[i+1].id].x)+abs(po2[po[i].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i+2].id,po[i+1].id,abs(po2[po[i+2].id].x-po2[po[i+1].id].x)+abs(po2[po[i+2].id].y-po2[po[i+1].id].y)});
        ban.push_back((BAN){po[i].id,po[i+2].id,abs(po2[po[i].id].x-po2[po[i+2].id].x)+abs(po2[po[i].id].y-po2[po[i+2].id].y)});
    }
}

int fa[MAXN];
int root(int x){
    if (fa[x]==x)return x;
    return fa[x]=root(fa[x]);
}

void solve(){
    sort(ban.begin(),ban.end());
    for (int i=0; i<n; i++)fa[i]=i;

    long long ans=0;
    for (auto e:E){
       // printf("(%d,%d,%d)\n",e.a,e.b,e.c);
        int u = root(e.a), v=root(e.b), w=e.c;
        if (u==v)continue;
       // printf("--- %d,%d,%d ---\n",e.a,e.b,e.c);
        ans+=w;
        fa[u]=v;
    }
    printf("%lld\n",ans*2);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        input();
        solve();
    }
}
