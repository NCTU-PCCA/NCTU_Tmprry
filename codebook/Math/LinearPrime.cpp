int p[MAXN], np = 0;
int a[MAXN];

for ( int i = 2 ; i < n ; i++ ) {
  if ( a[i] == 0 ) p[np++] = i;
  for ( int j = 0; j < np && i * p[j] < n ; j++ ) {
    a[i * p[j]] = 1;
    if ( i % p[j] == 0) break;
  }
}
