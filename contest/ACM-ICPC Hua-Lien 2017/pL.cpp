#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;
const int MAXN = 10004;
string s;
int n,dp[MAXN],cnt[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- && cin >> s){
        n = s.size();
        for (int i=0; i<=n; i++) dp[i] = INF;
        memset(cnt,0,sizeof(cnt));

        dp[0] = 0;
        for (int i=1; i<=n; i++){
            for (int k=1; k<=i; k++){

            }
        }
    }
	return 0;
}
