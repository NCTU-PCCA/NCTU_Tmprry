#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x, y;
	bool in;

	Point (int _x=0, int _y=0):x(_x),y(_y){ }

	int operator % ( const Point &b )const {
		return x*b.y-y*b.x;
	}

	bool operator < (const Point &b)const {
		int D = (*this)%b;
		if (D!=0)return D<0;
		return in>b.in;
	}
};

const int MAXN = 200005;

int n;
Point p[MAXN];

void input(){
	cin >> n;
	Point *a = p;
	Point *b = p+n;
	for (int i=0; i<2*n; i+=2){
		cin >> x1 >> y1 >> x2 >> y2;
		Point &p1 = p[i];
		Point &p2 = p[i+1];

		scanf("%d%d", &p[i].x, &p[i+1].y);
		p[i+1].in = 0;
		scanf("%d%d", &p[i+1].x, &p[i].y);
		p[i].in = 1;
	}
}

void solve(){
	sort(p,p+2*n);
	Point e = p[0];
	int mnt=0;
	int cnt=0;
	for (int i=0; i<2*n; i++){
		if (p[i].in==1)cnt++;
		else cnt--;
		if (cnt>mnt){
			mnt = cnt;
			e = p[i];
		}
	}

	int a = e.x; 
	int b = e.y;
	int d = __gcd(a,b);
	a/=d, b/=d;
	printf("%d/%d %d\n", b, a, mnt);
}

int main(){
	int T; cin >> T;

	while (T--){
		input();	
		solve();
	}
}
