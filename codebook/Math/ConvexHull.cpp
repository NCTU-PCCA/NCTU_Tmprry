#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 100005;
const LL INF = (1LL)<<62;

struct Point{
    LL x, y;
    Point (LL x=0, LL y=0):x(x),y(y){}
    bool operator < (const Point &B)const {
        if (x!=B.x)return x<B.x;
        return y<B.y;
    }
    Point operator - (Point B){
        return Point(x-B.x,y-B.y);
    }
};
LL cross(Point A, Point B){
    return A.x*B.y-A.y*B.x;
}
LL Abs(LL x){
    return x>0?x:-x;
}
LL AreaU[MAXN], AreaD[MAXN];
void find_CH(int N, Point P[], LL Area[]){
    static vector<Point> U, D;
    static vector<int> Ui, Di;
    U.clear(), Ui.clear();
    D.clear(), Di.clear();
    int uz=0, dz=0;

    for (int i=0; i<N; i++){
        while (uz>=2 && cross(P[i]-U[uz-2],U[uz-1]-U[uz-2])<=0)U.pop_back(), Ui.pop_back(), uz--;
        if (uz<=1)AreaU[i]=0;
        else AreaU[i] = AreaU[ Ui[uz-1] ] + Abs(cross(P[i]-U[0],U[uz-1]-U[0]));
        U.push_back(P[i]),Ui.push_back(i),uz++;

        while (dz>=2 && cross(P[i]-D[dz-2],D[dz-1]-D[dz-2])>=0)D.pop_back(), Di.pop_back(), dz--;
        if (dz<=1)AreaD[i]=0;
        else AreaD[i] = AreaD[ Di[dz-1] ] + Abs(cross(P[i]-D[0],D[dz-1]-D[0]));
        D.push_back(P[i]),Di.push_back(i),dz++;

        Area[i] = AreaU[i] + AreaD[i];
        //printf("Area[%d]=%lld\n",i ,Area[i]);
    }
    //puts("");
}

int N;
Point P[MAXN];
LL AreaL[MAXN], AreaR[MAXN];

int main(){
    input();

    find_CH(N,P,AreaL);
    for (int i=0; i<N; i++)P[i].x*=-1;
    reverse(P,P+N);
    find_CH(N,P,AreaR);
    reverse(AreaR,AreaR+N);
    reverse(P,P+N);

    LL Ans = min(AreaL[N-1],AreaR[0]);
    for (int i=0; i<N-1; i++){
        if (P[i].x!=P[i+1].x){
            Ans = min (Ans,AreaL[i]+AreaR[i+1]);
        }
    }
	if (P[0].x==P[N-1].x)Ans=0;
    printf("%lld\n",(Ans+1)/2LL);
}
