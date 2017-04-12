#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL w, h, ans[8];
struct Rec{
	char c;
	int x, X;
	int y, Y;
};

struct NODE{
	LL cnt[8], color[3];
};
int code(NODE &o){
	int re=0;
	if (o.color[0])re+=1;
	if (o.color[1])re+=2;
	if (o.color[2])re+=4;
	return re;
}


const int MAXN = 100005;

int n; Rec rec[MAXN];
NODE seg[MAXN*4];
vector< int > q[MAXN*2] ;
vector<int> dx;
vector<int> dy;

void Dis(int n, Rec r[]){
	static map<int,int> mx;
	dx.clear(); 
	mx.clear();
	for (int i=0 ;i<n; i++){
		dx.push_back( r[i].x );
		dx.push_back( r[i].X );
	}
	auto mid = unique(dx.begin(),dx.end());
	dx.resize( mid-dx.begin() ); 
	for (int i=0; i<dx.size(); i++){
		mx[ dx[i] ] = i;
	}
	for (int i=0; i<n; i++){
		r[i].x = mx[ r[i].x ];
		r[i].X = mx[ r[i].X ];
	}

	static map<int,int> my;
	dy.clear(); 
	my.clear();
	for (int i=0 ;i<n; i++){
		dy.push_back( r[i].y );
		dy.push_back( r[i].Y );
	}
	mid = unique(dy.begin(),dy.end());
	dy.resize( mid-dy.begin() ); 
	for (int i=0; i<dy.size(); i++){
		my[ dy[i] ] = i;
	}
	for (int i=0; i<n; i++){
		r[i].y = my[ r[i].y ];
		r[i].Y = my[ r[i].Y ];
	}
}
void pull(int x,int l, int r){
	if (l==r){
		int c = code(seg[x]);
		for (int i=0; i<8; i++){
			seg[x].cnt[i] = (i==c)*dy[l];
		}
	}

	for(int i = 0 ;i < 8 ;i++){
		seg[x].cnt[i] = seg[x+x].cnt[i] + seg[x+x+1].cnt[i];
	}
	for (int i=0; i<8; i++){
		int c = code(seg[x]);
		if ( (i|c) != i ){
			seg[x].cnt[i|c] += seg[x].cnt[i];
			seg[x].cnt[i]=0;
		}
	}
}
void add(int l, int r, int ll, int rr, int x, int c,int w){
	if(ll<=l && r<=rr){
		seg[x].color[c]+=w;
		pull(x,l,r);
		return;
	}
	else if (r<ll || rr<l)return;
	else{
		int mid = (l+r ) >> 1;
		add(l,mid,ll,rr,x+x,c,w);
		add(mid+1,r,ll,rr,x+x+1,c,w);
		pull(x,l,r);
	}
	
}
int change(char x){
	if(x == 'R') return 0;
	if(x == 'G')return 1;
	if(x == 'B')return 2;
}
int main(){	
	int T=0,qaq=0; 
	while (1){
		qaq++;
		memset(ans,0,sizeof(ans));
		memset(seg,0,sizeof(seg));
		scanf("%lld %lld ",&w,&h);
		if(w + h == 0) break;
		
		scanf("%d",&n);
		for (int i=0; i<n; i++){
			auto &r = rec[i];
			scanf(" %c %d %d %d %d", &r.c, &r.x, &r.y, &r.X, &r.Y);
			r.X++;
			r.Y++;
		}

		Dis(n,rec);
		for(int i = 0 ;i < n ;i++){
			auto &r = rec[i];
			q[r.x].push_back(i);
			q[r.X].push_back(i);
		}
		for(int i = 0 ;i < dx.size(); i++){
			for(int j = 0 ;j < q[i].size() ;j++){
				int idx = q[i][j];
				if(rec[idx].x == i){
					add(1,n*2,rec[idx].y,rec[idx].Y,1,change(rec[idx].c),1);
				}else{
					add(1,n*2,rec[idx].y,rec[idx].Y,1,change(rec[idx].c),-1);
				
				}
			}
			for(int j = 0 ;j < 8 ;j++) {
				ans[j] += seg[1].cnt[j]*dx[i];
			}
		}
		ans[0]=w*h;
		for(int i = 1 ;i < 8 ;i++)ans[0]-=ans[i];
		auto &a = ans;
		printf("Case %d: %d %d %d %d %d %d %d %d\n",qaq, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);

	}
}
