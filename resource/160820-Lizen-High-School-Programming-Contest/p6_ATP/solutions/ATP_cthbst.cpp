#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

int n, L, R;
char s[MAXN];

void getLR(){
	L=R=0;
	for (int i=0 ;i<n; i++){
		s[i]=='L' ? L++ : R++;
	}
}

void solve(){
	long long ans=0;
	int pl=0, pr=n-1; 
	
	while (pl<pr){
		while (pl<n  && s[pl]=='L')L--, pl++;
		while (0<=pr && s[pr]=='R')R--, pr--;
		if (pl>pr)break;

		if (L<R)
			ans += L, R--, pl++;
		else
			ans += R, L--, pr--;	
	}

	cout << ans;
}

int main(){
	scanf("%d%s", &n, s);
	getLR();
	solve();
}
