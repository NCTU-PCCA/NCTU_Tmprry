#include <bits/stdc++.h>
using namespace std;

long long calc(vector<int> v) {
	long long res = 0, pre = 0;
	for ( int i = 0 ; i < v.size() ; i++ ) {
		res += v[i] / 2 + pre;
		pre += v[i];
	}
	return res;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> a, b;
		for ( int i = 0 ; i < n ; i++ ) {
			int r;
			cin >> r;
			a.push_back(r);	
		}
		for ( int i = 0,r ; i < m ; i++ ) {
			cin >> r;
			b.push_back(r);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << calc(a) + calc(b) << endl;
	}
}
