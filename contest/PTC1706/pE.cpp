#include <bits/stdc++.h>
using namespace std;
int m;
struct XDD{
	int a[22],s;
	friend bool operator <(XDD a, XDD b){
		for(int i = 0;i < m ;i++){
			if(a.a[i] != b.a[i]) return a.a[i] > b.a[i];
		}
		return false;
	}
}ori[22],pre,tmp,now;
int main(){
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&m,&n,&k);
		for(int i = 0 ;i < n ;i++){
			ori[i].s = m;
			for(int j = 0 ;j < m ;j++){
				scanf("%d",&ori[i].a[j]);
			}
		}
		priority_queue<XDD> pp;
		for(int i = 0 ;i < n ;i++){
			pp.push(ori[i]);
		}
		for(int i = 0 ;i < k ;i++){
			now = pp.top();pp.pop();
			if(i != 0){
				while(now < pre ==false && pre < now == false){
					now = pp.top();pp.pop();
				}
			}
			for(int i = 0 ;i < n ;i++){
				tmp.s=m;
				for(int j = 0 ;j < m ;j++){
					tmp.a[j] = now.a[j]+ori[i].a[j];
				}
				pp.push(tmp);
			}
			pre = now;
		}
		for(int i = 0 ;i < m ;i++){
			if(i == m-1)  printf("%d\n",pre.a[i]);
			else printf("%d ",pre.a[i]);
		}

	}
}
