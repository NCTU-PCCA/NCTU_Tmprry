#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include <cstring>
#include<fstream>
using namespace std;

const int MAXN = 100005;
int n, m;
int c[4][4];
int a[1005][1005];
long long dp[1005][1005];

int main() {

    memset(dp, 0, sizeof(dp));

    cin >> n >> m;
    for ( int i = 0 ; i < 3 ; i++ ) {
      for ( int j = 0; j < 3; j++ ) {
        cin >> c[i][j];
      }
    }
    for ( int i = 0; i < n ; i++ ) {
      for (int j = 0; j < m; j++ ) {

        cin >> a[i][j];
        if ( i - 1 >= 0 ) dp[i][j] = max(dp[i][j], dp[i-1][j] + c[a[i][j]][a[i-1][j]]);
        if ( i - 1 >= 0 && j - 1 >= 0 ) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + c[a[i][j]][a[i-1][j-1]]);
        if ( j - 1 >= 0 ) dp[i][j] = max(dp[i][j], dp[i][j-1] + c[a[i][j]][a[i][j-1]]);
      }
    }

    cout << dp[n-1][m-1];

  return 0;
}
