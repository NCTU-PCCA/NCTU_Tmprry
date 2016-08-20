#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
using namespace std;

const int MAXN = 100005;
int n, k;
int a[MAXN];

int main() {


    cin >> n >> k;
    int mi = 0xFFFFFFF;
    for ( int i = 0 ; i < n ; i++ ) {
      cin >> a[i];
      mi = min(mi, a[i]);
    }

    int lo = 1, hi = mi, mid;
    while ( 1 ) {
      mid = (hi - lo)/2 + lo;
      long long tmp = 0;
      if ( hi - lo < 10 ) {
        for ( int j = hi ; j >= lo ; j--) {
          tmp = 0;
          for ( int i = 0 ; i < n ; i++ ) {
            tmp += a[i] / j - 1;
          }
          if ( tmp >= k ) {
            cout << j;
            return 0;
          }
        }
      }

      for ( int i = 0 ; i < n ; i++ ) {
        tmp += a[i] / mid - 1;
      }
      if ( tmp >= k ) lo = mid;
      else hi = mid;
    }

  return 0;
}
