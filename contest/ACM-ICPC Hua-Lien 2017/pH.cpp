#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int MAXP = 1000006;
vector<Int> P;
bitset<MAXP> ok;

void build_prime(){
    ok.set();

    for (Int i=2; i<MAXP; i++)if (ok[i]){
        P.push_back(i);
        for (Int j=i+i; j<MAXP; j+=i)ok[j] = 0;
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    build_prime();
    int T; cin >>T;

    Int n; 
    while (T-- && cin >> n){
        vector<int> v;

        for (Int p:P){
            if (p*p>n)break;
            if (n%p==0){
                v.push_back(0);
                while (n%p==0){
                    n/=p;
                    v.back()++;
                }
            }
        }
        if (n!=1)v.push_back(1);

        Int pro = 1;
        for (Int x:v){
            pro *= (x+1);
            //cout << x << ',';
        }
        Int ans=0;
        for (Int x:v ) ans += pro / (x+1) * x;
        cout << ans << '\n';
    }

	return 0;
}
