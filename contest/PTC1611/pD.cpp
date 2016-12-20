#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;

struct Point{
    int x, y;
    Point operator - (Point &B){
        return (Point){x-B.x,y-B.y};
    }
};

int sgn(int x){
    return x<0?-1:x>0;
}
int cross(Point A, Point B){
    return A.x*B.y-A.y*B.x;
}
int sgcs(Point A, Point B){
    return sgn( cross(A,B) );
}
int dis2(Point A, Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}


int n, r;
Point p[MAXN];

bool ok(vector<Point> s){
    int sz=s.size(); if (sz==1)return 1;
    for (int i=0; i<sz; i++){
        for (int j=0; j<sz; j++)if (i!=j){
            double dx = double(s[i].x-s[j].x);
            double dy = double(s[i].y-s[j].y);
            double ox = (double)(s[i].x+s[j].x)/2.0;
            double oy = (double)(s[i].y+s[j].y)/2.0;
            swap(dx,dy); dx=-dx;

            double dis = sqrt(dx*dx+dy*dy);
            if ((double)r*r-(double)(dx*dx+dy*dy)/4.0<0 )continue;
            double ris = sqrt( (double)r*r-(double)(dx*dx+dy*dy)/4.0 );
            dx *= ris/dis;
            dy *= ris/dis;

            ox += dx;
            oy += dy;

            bool haha=1;
            for (int k=0; k<sz; k++){
                double len = pow((double)s[k].x-ox,2) + pow((double)s[k].y-oy,2);
                if (len > (double)r*r){
                    haha=0;
                    break;
                }
            }
            if (haha){
                //printf("%f %f\n", ox, oy);
                return 1;
            }
        }
    }
    return 0;
}

bool solve(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)if (i!=j){
            vector<Point> s1, s2;
            for (int k=0; k<n; k++){
                int state = sgcs(p[k]-p[i],p[j]-p[i]);
                if (state==0){
                    if (dis2(p[k],p[i])<=dis2(p[i],p[j]) && dis2(p[k],p[j])<=dis2(p[i],p[j]))
                        s1.push_back(p[k]);
                    else
                        s2.push_back(p[k]);
                }
                else if (state== 1)s1.push_back(p[k]);
                else if (state==-1)s2.push_back(p[k]);
            }
            if (ok(s1)&&ok(s2))return 1;
        }
    }
    return 0;
}

int main(){
    int T; scanf("%d",&T);

    while (T-- && scanf("%d%d", &n, &r)){
        for (int i=0; i<n; i++)scanf("%d%d", &p[i].x, &p[i].y);
        puts(solve()?"yes":"no");
    }
}
