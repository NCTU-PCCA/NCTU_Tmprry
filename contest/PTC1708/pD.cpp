#include <cstdio>
#include <cstdlib>
using namespace std;
long long ori;
long long n,x,y;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",&n,&x,&y);
		ori = n*(n-1)*(n*2-1)/6+(n-1)*(n-1)*(n-2)*(n)/12;
//		printf("ori = %lld\n",ori);
		for(int i = 1 ;i <= n ;i++){
			for(int j = 1 ;j <= n ;j++){
				long long dx = i-x;
				long long dy = j-y;
				long long sx = i+x;
				long long sy = j+y;

				long long xx1 = sx+dy, yy1 = sy+dx;
				long long xx2 = sx-dy, yy2 = sy-dx;
				if(xx1%2 + xx2%2 + yy1%2 + yy2%2 >0){
					continue;
				}
				if(xx1 < 1 || xx2 < 1 || yy1 <1 || yy2 <1)
					continue;
				if(xx1/2>n || xx2/2>n || yy1/2>n || yy2/2>n)
					continue;
//				printf("sub %d %d\n",i,j);
				ori--;
			}
		}
		printf("%lld\n",ori+1);
	}
}
