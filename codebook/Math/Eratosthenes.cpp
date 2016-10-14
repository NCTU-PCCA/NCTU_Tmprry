bool p[MAXP] = {0};

void eratosthenes() {
  p[0] = p[1] = 0;
  for ( int i = 2;  i < MAXP ; i++ ) {
    p[i] = 1;
  }
  for ( int i = 2 ; i < MAXP ; i++ ) {
    if ( !p[i] ) {
      for ( int j = i + i ; j < MAXP ; j++ ) {
        p[j] = 0;
      }
    }
  }
}
