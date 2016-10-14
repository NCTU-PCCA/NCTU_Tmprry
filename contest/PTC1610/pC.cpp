#include<bits/stdc++.h>
using namespace std;

int n, m, q;

const int MAXN = 1003;
vector<int> s[1003];

char getc(){
  static const int bufsize = 1<<16;
  static char B[bufsize], *S=B, *T=B;
  return (S==T&&(T=(S=B)+fread(B,1,bufsize,stdin),S==T)?0:*S++);
}

template <class T>
bool input(T& a){
  a=(T)0;
  register char p;
  while ((p = getc()) < '-')
    if (p==0 || p==EOF) return false;
  if (p == '-')
    while ((p = getc()) >= '0') a = a*10 - (p^'0');
  else {
    a = p ^ '0';
    while ((p = getc()) >= '0') a = a*10 + (p^'0');
  }
  return true;
}

template <class T, class... U>
bool input(T& a, U&... b){
  if (!input(a)) return false;
  return input(b...);
}


void inut() {
    input(n, m ,q);
    for (int i=0; i<MAXN; i++)s[i].clear();

    for ( int i = 1 ,a ; i <= m ; i++ ) {
        input(a);
        s[i].resize(a);
        for (int &x:s[i])input(x);
    }
    s[0].push_back(n+1);
    s[++m].push_back(-1);
}

bool cmp(vector<int> a, vector<int> b) {
    int len = min(a.size(),b.size());

    for ( int i = 0 ; i < len ; i++) {
        if ( a[i] == b[i] ) continue;
        if ( i % 2 == 0 ) {
            return a[i] < b[i];
        } else {
            return a[i] > b[i];
        }
    }
    return 1;
}

bool same(vector<int> a, vector<int> b) {
    if (a.size()!=b.size())return 0;
    int len = min(a.size(),b.size());

    for ( int i = 0 ; i < len ; i++) {
        if (a[i]!=b[i])return 0;
    }
    return 1;
}

int bs(vector<int> v) {
    int l=0, r=m+1, mid;
    while (l!=r){
        mid = (l+r)>>1;
        if ( cmp(v,s[mid]) )l=mid+1;
        else r=mid;
    }
    return l;
}

vector<int> v;
void solve() {
    for ( int i = 0 ,a; i < q; i ++ ) {
        input(a);
        v.resize(a);
        for (int &x:v)input(x);

        int lo = bs(v);

        if ( same(v,s[lo-1]) ){
            printf("%d\n",lo-1);
            continue;
        }

        if ( lo == 1 ) puts("<1");
        else if ( lo == m ) printf(">%d\n", m - 1);
        else printf("%d %d\n", lo-1, lo);
    }
}


int main() {
    int T; cin >> T;
    while ( T-- ) {
        inut();
        solve();
    }
}
