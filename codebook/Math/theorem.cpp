/*
Lucas's Theorem
	For non-negative integer n,m and prime P,
	C(m,n) mod P = C(m/M,n/M) * C(m%M,n%M) mod P
	= mult_i ( C(m_i,n_i) )
	where m_i is the i-th digit of m in base P.
-------------------------------------------------------
Pick's Theorem
  A = i + b/2 - 1
-------------------------------------------------------
Kirchhoff's theorem
  A_{ii} = deg(i), A_{ij} = (i,j) \in E ? -1 : 0
  Deleting any one row, one column, and cal the det(A)
-------------------------------------------------------
Nth Catalan recursive function:
C_0 = 1, C_{n+1} = C_n * 2(2n + 1)/(n+2)
-------------------------------------------------------
Mobius Formula
u(n) = 1        , if n = 1
       (-1)^m   , 若 n 無平方數因數，且 n = p1*p2*p3*...*pk
       0        , 若 n 有大於 1 的平方數因數
- Property
1. (積性函數) u(a)u(b) = u(ab)
2. ∑_{d|n} u(d) = [n == 1]
-------------------------------------------------------
Mobius Inversion Formula
if      f(n) = ∑_{d|n} g(d)
then    g(n) = ∑_{d|n} u(n/d)f(d)
             = ∑_{d|n} u(d)f(n/d)
- Application
the number/power of gcd(i, j) = k
- Trick
分塊, O(sqrt(n))

*/
