#include <bits/stdc++.h>
using namespace std;

const int MAXN = 130;
const double INF = 1e9;

struct Point {
    double x, y;
    Point (int x=0, int y=0):x(x),y(y){ }
    Point operator - (Point B){
        return Point(x-B.x,y-B.y);
    }
    Point operator * (double d){
        return Point(x*d,y*d);
    }
};
double cross(Point a, Point b){
    return a.x*b.y-a.y*b.x;
}
double dis(Point a,Point b){
    return sqrt( pow(a.x-b.x,2)+pow(a.y-b.y,2) );
}
double dot(Point a,Point b){
    return a.x*b.x + a.y*b.y;
}
double len(Point a){
    return sqrt(dot(a,a));
}

int n;
Point P[MAXN];
typedef pair<Point,Point> Seg;
Seg seg[MAXN];

bool CHcmp(Point a ,Point b){
    a = a-P[1];
    b = b-P[1];
    return cross(a,b)>0;
}

void Sort(){
    sort(P+2,P+1+n,CHcmp);
    for (int i=1; i<=n; i++)printf("%.2f %.2f\n",P[i].x ,P[i].y); puts("");
}

bool input(){
    int ix, iy;
    cin >> n >> ix >> iy;
    if (n==0 && ix==0 && iy==0)return 0;
    P[0] = (Point){ix,iy};
    for (int i=1; i<=n; i++){
        cin >> P[i].x >> P[i].y;
    }
    Sort();
    return 1;
}

void set_seg(){
    for (int i=1; i<n; i++){
        seg[i-1]=make_pair(P[i],P[i+1]);
    }
    seg[n-1]=make_pair(P[n],P[1]);
}

bool fight(Seg e1,Seg e2){
    if ( cross(e2.first-e1.first,e1.second-e1.first)*cross(e1.second-e1.first,e2.second-e1.first)<0 )return 0;
    swap(e1,e2);
    if ( cross(e2.first-e1.first,e1.second-e1.first)*cross(e1.second-e1.first,e2.second-e1.first)<0 )return 0;
    return 1;
}
Point trans(Seg e,Point p){
    Point v = e.second-e.first;
    swap(v.x,v.y); v.y*=-1;
    Point r = e.second-p;
    double dd = dot(r,v)/len(v);

}

double test(){
}

void solve(){
    double ans = INF ;
    set_seg();
    for (int i=0; i<n; i++){
        ans = min(ans,test());
        Point tmp = P[1];
        for (int j=1; j<n; j++)P[j]=P[j+1];
        P[n] = tmp;
    }
    printf("%.2f\n",ans);
}

int main(){
    freopen("data5.txt","r",stdin);
    int T=0;
    while ( input() ){
        printf("case %d: ",++T);
        solve();
    }
}
