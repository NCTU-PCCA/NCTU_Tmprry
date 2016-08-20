#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
#include<algorithm>
using namespace std;

long long tables[70];
int iter = 0;

void mk() {
  long long tmp = 2;
  while ( tmp <= 100000000000000000LL ) {
    tables[iter++] = tmp;
    tmp *= 2;
  }
  tables[iter++] = tmp;
}


int main() {

  mk();

    long long a, b;
    cin >> a >> b;
    cout << lower_bound(tables, tables+iter, a) - tables + lower_bound(tables, tables+iter, b) - tables + (a!=1) + (b!=1) << endl;

  return 0;
}
