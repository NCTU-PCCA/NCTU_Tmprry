#include<iostream>
#include <iomanip>
#include<cmath>
#include <stdio.h>
#include<fstream>
using namespace std;



int main() {


  for ( int i = 1 ; i <= 60;  i++ ) {
    fstream fp, fo;
    char s[10];
    sprintf(s, "%02d.in", i);
    char ss[10];
    sprintf(ss, "%02d.out", i);
    fp.open(s);
    fo.open(ss, ios::out);

    long long a, b, ans=0, now=1;
    fp >> a >> b;
    while(now < a){
        now<<=1;
        ans++;
    }
    now=1;
    while(now < b){
        now<<=1;
        ans++;
    }
    fo << ans;

    fp.close();
    fo.close();
  }
  return 0;
}
