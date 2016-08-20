#include <bits/stdc++.h>
using namespace std;

int solve(long long d){
	if (d<=1)return 0;
	return __lg(d-1)+1;
}

int main(){
	long long a, b;
	cin >> a >> b;
	cout << solve(a)+solve(b) <<endl;
}
