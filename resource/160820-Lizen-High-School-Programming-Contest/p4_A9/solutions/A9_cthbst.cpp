#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

void solve(int n, bool pull=1){
	if (pull){
		if (n-2>0) solve(n-2,pull);
		printf("Move ring %d %s\n", n, (pull?"out":"in") );
		if (n-2>0) solve(n-2,pull^1);
		if (n-1>0) solve(n-1,pull);
	}
	else {
		if (n-1>0) solve(n-1,pull);
		if (n-2>0) solve(n-2,pull^1);
		printf("Move ring %d %s\n", n, (pull?"out":"in") );
		if (n-2>0) solve(n-2,pull);
	}
}

LL bin_pow(LL a, LL n){
	LL re=1;
	while (n>0){
		if (n&1) re = re*a %MOD;
		a = a*a %MOD;
		n>>=1;
	}
	return re;
}

void step(LL n){
	LL ans = bin_pow(2,2+n) - bin_pow(MOD-1,n%2) -3 ;
	if (ans<0) ans += MOD;
	ans = ans * bin_pow(6,MOD-2) % MOD;
	cout << ans << endl;
}

int main(){
	LL n; cin >> n;
	step(n);
	if (n<=10)solve(n);
}
