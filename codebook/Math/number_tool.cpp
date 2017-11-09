Int POW(Int a, Int n, Int mod){
	Int re=1;
	while (n>0){
		if (n&1LL) re = re*a%mod;
		a = a*a%mod;
		n>>=1;
	}
	return re;
}

Int C(Int n, Int m){
	if (m<0 || m>n)return 0;
	return J[n] * inv(J[m]*J[n-m]%MOD) %MOD;
}
