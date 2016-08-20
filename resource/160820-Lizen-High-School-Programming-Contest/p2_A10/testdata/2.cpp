#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
#include<algorithm>
using namespace std;

const int MAXN = 100005;
int n, k;
int a[MAXN];

int main() {


  for ( int iii = 1 ; iii <= 60;  iii++ ) {
    fstream fp, fo;
    char s[10];
    sprintf(s, "%02d.in", iii);
    char ss[10];
    sprintf(ss, "%02d.out", iii);
    fp.open(s);
    fo.open(ss, ios::out);

    fp >> n >> k;
    int mi = 0xFFFFFFF;
    for ( int i = 0 ; i < n ; i++ ) {
      fp >> a[i];
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
            fo << j;
            cout << tmp << endl;
            cout << iii << endl;
            goto t;
          }
        }
      }

      for ( int i = 0 ; i < n ; i++ ) {
        tmp += a[i] / mid - 1;
      }
      if ( tmp >= k ) lo = mid;
      else hi = mid;
    }
    t:;
    fp.close();
    fo.close();
  }
  return 0;
}
