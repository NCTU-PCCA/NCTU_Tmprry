#include <bits/stdc++.h>
using namespace std;

int main(){
	for (int i=1; i<=100000; i++)
		putchar( 'A'+1 + (__builtin_popcount(i+1)&1) - (__builtin_popcount(i)&1) );
}
