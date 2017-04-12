#include <bits/stdc++.h>
using namespace std;

long long fac(int n) {
	long long res = 1;
	for ( int i = 1 ; i <= n ; i++ ) {
		res *= i;
	}
	return res;
}

long long C(int n, int m){
	if (m<0 || m>n)return 0;
	m = min(m,n-m);
	long long re = 1;
	for (int i=1; i<=m; i++){
		re *= (n-i+1);
		re /= i;
	}
	return re;
}

long long solve(int n) {
	long long res = 0;
	for (int i=0; i<= n/2; i++){
		int w = (n - i*2);
		if (w%2!=0)continue;
		res += C(i,w/2);
	}
	return res;

}

int main(){
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
