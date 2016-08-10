#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 5005;
char s[MAXN];
int dp[MAXN][MAXN];
int n;

int getDP(int L, int R) {

    if ( L < 1 ) return n-R+1;
      if ( R > n ) return L;
        if ( L == 1 && R == n ) {

              return s[L - 1] != s[R - 1];
                }
          if ( dp[L][R] != -1 ) return dp[L][R];
            int ret = 100000;
              if ( s[L - 1] == s[R - 1] ) {
                    ret = min(ret, getDP(L - 1, R + 1));
                      } else {
                            ret = min(ret, getDP(L - 1, R + 1) + 1);
                                ret = min(ret, getDP(L - 1, R) + 1);
                                    ret = min(ret, getDP(L, R + 1) + 1);
                                      }

                return dp[L][R] = ret;
}

void solve() {
    n = strlen(s);
      int res = 10000000;
        memset(dp, -1, sizeof(dp));

          if ( n == 1 ) {
                cout << 0 << endl;
                    return;
                      }
            for ( int i = 1 ; i <= n - 1 ; i++ ) {

                  res = min(res, getDP(i, i+1));
                      if ( i + 2 <= n)
                            res = min(res, getDP(i, i+2));
                        }
              cout << res << endl;
}

int main() {
    int T;
      cin >> T;
        while ( T-- ) {
              cin >> s;

                  solve();
                    }
          return 0;
}

