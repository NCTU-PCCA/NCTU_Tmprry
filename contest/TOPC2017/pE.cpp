#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int MAXN = 100;
const double PI = 3.1415926535897932;

int n;
double C, len[MAXN]; 

bool getType(){
    sort(len,len+n);
    double r = len[n-1]/2.0;
    double sum=0;
    for (int i=0; i<n-1; i++){
        sum += 2.0 * asin(len[i]/2.0/r);
    }
    return sum >= PI;
}

double DegSum(double r, bool type){
    double sum=0;
    for (int i=0; i<n-1+type; i++){
        sum += 2.0 * asin(len[i]/2.0/r);
    }
    return sum;
}

double Area(double r, bool type){
    double ans = 0.0;
    for (int i=0; i<n; i++){
        double S = (len[i]+r+r)/2.0;
        ans += sqrt(S*(S-len[i]))*(S-r);
    }
    if (type==0){
        double S = (len[n-1]+r+r)/2.0;
        ans -= 2.0*sqrt(S*(S-len[n-1]))*(S-r);
    }
    return ans;
}

int main(){
    int T; cin >>T;

    while ( T-- ){
        ~scanf("%lf %d", &C, &n);
        for (int i=0; i<n; i++) ~scanf("%lf", &len[i]);
        C /= PI*2;

        bool type = getType();
        double l=len[n-1]/2.0, r=10000;
        if (type==1)for (int i=0; i<100; i++){
            double mid = (l+r)/2.0;
            double deg = DegSum(mid,type);
            if (deg<2*PI)r=mid;
            else l = mid;
        }
        else for (int i=0; i<100; i++){
            double mid = (l+r)/2.0;
            double deg = DegSum(mid,type);
            if (deg > 2.0*asin(len[n-1]/2.0/mid) )r=mid;
            else l=mid;
        }

        //printf("type  = %d\n",type);
        //printf("r = %.15f\n",r);
        //printf("Area = %.15f\n", Area(r,type));

        double ans = C*C*PI - Area(r,type);
        printf("%.16f\n", ans);
    }
}
