#include <bits/stdc++.h>
using namespace std;

typedef long long T;
struct Point {
	T x,y;
	Point (T _x=0, T _y=0):x(_x),y(_y){}

	bool operator < (const Point &b)const{
		if (x!=b.x)return x<b.x;
		return y<b.y;
	}
	bool operator == (const Point &b)const{
		if (x!=b.x)return 0;
		if (y!=b.y)return 0;
		return 1;
	}
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	T operator * (const Point &b)const{
		return x*b.x + y*b.y;
	}
	T operator % (const Point &b)const{
		return x*b.y - y*b.x;
	}
	Point operator * (const T &d)const{
		return Point(d*x,d*y);
	}
};

void ConvexHull(vector<Point> &P, vector<Point> &H){
    int n = P.size(), m=0;
    sort(P.begin(),P.end());
	n = unique(P.begin(),P.end())-P.begin();
    H.clear();
    
    for (int i=0; i<n; i++){
        while (m>=2 && (P[i]-H[m-2]) % (H[m-1]-H[m-2]) <0)H.pop_back(), m--;
        H.push_back(P[i]), m++;
    }

    for (int i=n-2; i>=0; i--){
        while (m>=2 && (P[i]-H[m-2]) % (H[m-1]-H[m-2]) <0)H.pop_back(), m--;
        H.push_back(P[i]), m++;
    }
}

int n;
vector<Point> P, H;

int main(){
	int nT; cin >>nT;
	while (nT-- && cin >> n){
		P.clear();
		H.clear();
		for (int i=0; i<n;i ++){
			int x, y;
			scanf("%d %d", &x, &y);
			x = x+1;
			y = y+1;
			P.push_back( (Point){x,y} );
		}
		ConvexHull(P,H);

		long long ans = 0;
		for (int i=1; i<H.size(); i++){	
			ans += H[i]%H[i-1];
		}
		if (ans<0) ans = -ans;

		if (ans%2==0)printf("%lld.00", ans/2);
		else printf("%lld.50", ans/2);
		puts("");
	}
}
