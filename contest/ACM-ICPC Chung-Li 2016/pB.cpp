#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef LL T;

const LL INF = (1LL)<<50;

struct Point {
	T x, y;
	Point (T _x=0, T _y=0):x(_x),y(_y){}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	bool operator < (const Point &b)const{
		if (x!=b.x)return x<b.x;
		return y<b.y;
	}
	T abs2(){ return x*x+y*y; }
};

int N;
vector<Point> p;

void input(){
	scanf("%d",&N);
	p.resize(N);
	for (auto &pp:p)scanf("%lld %lld", &pp.x, &pp.y);
	sort(p.begin(),p.end());
}

void solve(){
	LL ans = INF;

	for (int i=0; i<N; i++){
		for (int j=i+1; j<N; j++){
			if ( (p[i].x-p[j].x)*(p[i].x-p[j].x) > ans )break;
			ans = min(ans, (p[i]-p[j]).abs2() );
		}
	}
	double A = floor(sqrt(ans)*100.0);
	printf("%.2f\n",A*0.01);
}

int main(){
	int T; scanf("%d",&T);

	while (T--){
		input();
		solve();
	}
}
