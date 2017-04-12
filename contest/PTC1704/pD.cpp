#include <bits/stdc++.h>
using namespace std;
int n ,seg[100005*4];
int find(int l,int r,int need,int x){
	if(l == r) return seg[x];
	seg[x+x] += seg[x];
	seg[x+x+1] += seg[x];
	seg[x] = 0;
	int mid = (l+r)>>1;
	if(need <= mid) return find(l, mid, need, x+x);
	else return find(mid+1, r, need, x+x+1);
}
void add(int l,int r,int ll,int rr,int x){
	if(rr < l || r < ll) return ;
	if( ll <= l && r <= rr) {seg[x]++; return ;}
	
	int mid = (l + r )>>1;
	add(l,mid,ll,rr,x+x);
	add(mid+1,r,ll,rr,x+x+1);
	
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n == 0)break;
		fill(seg,seg+100005*4,0);
		int a, b;
		for(int i = 0 ;i < n; i++){
			scanf("%d %d",&a,&b);a++,b++;
			int need = find(1,n,b,1);
			int l=b ,r=n;
			if ( find(1,n,n,1)==need ) l = r = n+1;
			while (l!=r){
				int mid = (l+r)>>1;
				if ( find(1,n,mid,1) <= need )l=mid+1;
				else r = mid;
			}
			b = l-1;
			add(1,n,a,b,1);
		}
		printf("%d\n",find(1,n,n,1));
	}
}



