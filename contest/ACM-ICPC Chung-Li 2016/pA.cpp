#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
LL c, a, b, tmp,rr;
int main(){
	while(1){
		scanf("%lld",&c);
		if(c == 0) return 0;
		scanf("%lld %lld",&a,&b);
		if(a ==b ){
			puts("false");
			continue;
		}
		tmp = abs(b-a);
		LL u,d;
		u = c; d = 2LL*tmp;
		tmp = __gcd(u,d);
		u /= tmp;
		d /= tmp;
		rr =a;
		a = abs(a);
		u *= a;

		tmp = __gcd(u,d);
		u /= tmp;
		d /= tmp;

		c *= d;
		u %= c;
		if(rr < 0){
			u= c-u;
		}
		printf("%lld",u);
		if(d != 1) printf("/%lld",d);
		puts("");
	}
}
