#!/usr/bin/env python3

N = 302
J = [ 1 for i in range(N) ]
for i in range(1,N):
    J[i] = J[i-1] * i

T = int( input() )
for _ in range(T):
    n,k,d = [ int(x) for x in input().split() ]
    
    A = J[n]//J[k]//J[n-k]
    ans = []
    
    while A>0:
        ans.append(A%d)
        A = A//d
    ans.reverse()
    print( ''.join( str(x) for x in ans) )

