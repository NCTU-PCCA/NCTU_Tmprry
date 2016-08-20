#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
using namespace std;

const int MAXN = 100005;
int n, m;


int main() {


  for ( int iii = 1 ; iii <= 60;  iii++ ) {
    fstream fp, fo;
    char s[10];
    sprintf(s, "%02d.in", iii);
    char ss[10];
    sprintf(ss, "%02d.out", iii);
    fp.open(s);
    fo.open(ss, ios::out);



    fp >> n;
    long long res = 0, sum = 0;

    for ( int i = 0 ; i < n ; i++ ) {
      int c;
      fp >> c;
      if ( c == 'R' ) sum++;
      else res += sum;
    }

    fo << res;

    fp.close();
    fo.close();
  }
  return 0;
}
