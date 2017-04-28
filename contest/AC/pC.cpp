#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2003;

typedef long long LL;
typedef int T;

struct Point {
	T x, y;
	Point (T _x=0, T _y=0):x(_x),y(_y){ }
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
};
Point p[MAXN];

typedef pair<Point,Point> Rec;
vector<Rec> recs;

int w, l, n;
void input(){
	for (int i=0; i<n; i++){
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	recs.clear();
	for (int i=1; i<n; i++){
		Point p00 = p[i-1], p10 = p[i];
		Point p01 = p00 + Point(w,l);
		Point p11 = p10 + Point(w,l);
		Point d0 ,d1;
		d0.x = min(p00.x,p10.x);
		d0.y = min(p00.y,p10.y);
		d1.x = max(p01.x,p11.x);
		d1.y = max(p01.y,p11.y);
		//printf("(%d,%d) (%d,%d)\n",d0.x,d0.y,d1.x,d1.y);
		recs.push_back( (Rec){d0,d1} );
	}
	//puts("");
}

map<int,int> Hashx, Hashy;
map<int,int> unHashx, unHashy;
typedef tuple<int,int,int> tiii;
vector< tiii > Q[MAXN];
set<int> xs, ys;

void build_query(){
	for (int i=0; i<MAXN; i++)Q[i].clear();
	
	xs.clear();
	ys.clear();
	Hashx.clear(); unHashx.clear();
	Hashy.clear(); unHashy.clear();
	for (auto &rec:recs){
		xs.insert(rec.first.x);
		ys.insert(rec.first.y);
		xs.insert(rec.second.x);
		ys.insert(rec.second.y);
	}
	
	{	int i=0;
		for (int ele:xs){
			Hashx[ele]=i;
			unHashx[i]=ele;
//			printf("uHashx[%d]=%d\n",i,unHashx[i]);
			i++;
		}
	}
	//puts("");
	{	int i=0;
		for (int ele:ys){
			Hashy[ele]=i;
			//printf("Hashy[%d]=%d\n",ele,i);
			unHashy[i]=ele;
			i++;
		}
	}
	for (auto &rec:recs){
		int y0 = rec.first.y; y0 = Hashy[y0];
		int y1 = rec.second.y; y1 = Hashy[y1];
		Q[ Hashx[rec.first.x]  ].push_back( (tiii){y0,y1,1} );
		Q[ Hashx[rec.second.x] ].push_back( (tiii){y0,y1,-1} );
		//printf("(%d,%d,%d,%d)\n",Hashx[rec.first.x],y0,y1,1);
		//printf("(%d,%d,%d,%d)\n",Hashx[rec.second.x],y0,y1,-1);
	}
}

int sum[MAXN], pre[MAXN];
void count_area(){
	memset(pre,0,sizeof(pre));
	long long ans = 0;
	for (int i=0; i<xs.size(); i++){
		sum[0]=pre[0];
		for (int j=1; j<ys.size(); j++)sum[j]=sum[j-1]+pre[j];
//		for (int j=0; j<ys.size(); j++)printf("%2d",sum[j]);
//		puts("");
		for (int j=0; j<ys.size(); j++)if (sum[j]){
//			printf("unHashx[i+1]=%d, unHashx[i]=%d\n",unHashx[i+1], unHashx[i]);
			int dx = unHashx[i]-unHashx[i-1];
			int dy = unHashy[j+1]-unHashy[j];
//			printf("dxdy %d %d\n",dx,dy);
			ans += (LL)dx*dy;
		}

//		printf("pre %d\n",i);
		for (auto que:Q[i]){
			pre[ get<0>(que) ]+=get<2>(que);
			pre[ get<1>(que) ]-=get<2>(que);
//			printf("(%d %d %d)",get<0>(que),get<1>(que),get<2>(que));
//			puts("");
		}
//		for (int j=0; j<ys.size(); j++)printf("%3d",pre[j]);
//		puts("");
	}

	printf("%lld\n",ans);
}

int main(){
	while ( scanf("%d%d%d", &w, &l, &n) ){
		if (w==0 && l==0 && n==0)return 0;
		input();
		build_query();
		count_area();
	}
}

