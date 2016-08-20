#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> l;

void input(){
	scanf("%d %d", &n, &k);
	l.resize(n);
	for (auto &x:l)scanf("%d",&x);
}

int L, R;
void find_min(){
	R = l[0];
	for (int i=1; i<n; i++){
		R = min( R, l[i]);
	}
}

bool check(int d){
	int cnt=k;

	for (int i=0; i<n && cnt>0; i++){
		cnt -= l[i]/d-1;
	}

	return cnt<=0;
}

void solve(){
	L=0;
	if (check(R))L=++R;

	while (L!=R){
		int mid=(L+R)>>1;
		if (check(mid))L=mid+1;
		else R=mid;
	}
	printf("%d\n",L-1);
}

int main(){
	input();
	find_min();
	solve();
}
