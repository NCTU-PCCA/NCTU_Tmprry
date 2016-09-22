#include <bits/stdc++.h>
using namespace std;
//std::numeric_limits<double>
const double EPS = 0;//(1e-10);

// Point type -----------------------------------
struct Point{
    double x, y;

    Point (double _x=0.0, double _y=0.0):x(_x),y(_y){ }

    bool operator < (const Point B)const {
        if (x!=B.x)return x<B.x;
        return y<B.y;
    }
    Point operator - (Point B){
        return Point (x-B.x,y-B.y);
    }
};

typedef Point Vector;

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}
double dis(Point a, Point b){
    return sqrt( pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0) );
}

// Convex Hull ----------------------------------
vector<Point> ConvexHull(vector<Point> &P){
    vector<Point> Result;
    auto &R = Result;

    int n = P.size();
    int sz = 0;
    sort(P.begin(),P.end());
    //for (auto &p : P)printf("%.2f %.2f\n", p.x, p.y);

    for (int i=0; i<n; i++){
        auto p = P[i];
        while (sz>=2 && cross(R[sz-1]-R[sz-2],p-R[sz-1])<EPS )R.pop_back(), sz--;
        R.push_back(p), sz++;
        //for (auto &p : R)printf("(%.2f %.2f)", p.x, p.y);puts("");
    }
    for (int i=n-2; i>=0; i--){
        auto p = P[i];
        while (sz>=2 && cross(R[sz-1]-R[sz-2],p-R[sz-1])<EPS && p.x!=P[n-1].x)R.pop_back(), sz--;
        R.push_back(p), sz++;
        //for (auto &p : R)printf("(%.2f %.2f)", p.x, p.y);puts("");
    }
    R.pop_back();
    /*
    printf("CH---------------------------\n");
    for (auto &p : R)printf("%.2f %.2f\n", p.x, p.y);
    printf("CH end ----------------------\n");
    */
    return Result;
}

bool input(int n, vector<Point> &P){
    P.resize(n);

    for (auto &p : P){
        scanf("%lf %lf", &p.x, &p.y);
    }
}

double CHlen(vector<Point> &P){
    int n = P.size();
    double ans = 0.0;
    for (int i=0; i+1<P.size(); i++){
        ans += dis(P[i],P[i+1]);
    }
    ans += dis(P[n-1],P[0]);
    return ans;
}

double Area(vector<Point> &P){
    int n = P.size();
    double ans = 0.0;
    for (int i=1; i<n-1; i++){
        ans += cross(P[i]-P[0],P[i+1]-P[0]);
    }
    ans/=2.0;
    return ans;
}

int n;
vector<Point> points, CH;

int main(){
    freopen("data6.txt","r",stdin);
    int T=0;
    while (~ scanf("%d",&n) ){
        input(n,points);
        CH = ConvexHull(points);
        printf("Case %d: %d %.05f %.05f\n", ++T, CH.size(), CHlen(CH), Area(CH));
    }
}
