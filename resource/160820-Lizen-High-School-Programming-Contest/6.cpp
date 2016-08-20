#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
using namespace std;

const int MAXN = 100005;
int n, m;


int main() {





    cin >> n;
    long long res = 0, sum = 0;

    for ( int i = 0 ; i < n ; i++ ) {
      char c;
      cin >> c;
      if ( c == 'R' ) sum++;
      else res += sum;
    }

    cout << res;

  return 0;
}
