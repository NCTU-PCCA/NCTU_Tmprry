#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100005;
const int P = 0xdefacedLL;
const int X = 20160820LL;

int n, H[MAXN], rp[MAXN];
string s;

int aph;
bool inRange(){
	for (int i=0; i<n; i++){
		int idx = s[i]-'A';
		if ( 0<= idx && idx <aph )continue;
		return 0;
	}
	return 1;
}

int bin_pow(int A, int N, int MOD){
	int re=1;
	while (N>0){
		if (N&1)re = (LL)re*A%MOD;
		A=(LL)A*A%MOD;
		N>>=1;
	}
	return re;
}

void build_H(){
	int xi=1;
	for (int i=0; i<n; i++){
		int idx=(int)s[i]-'A'+1;
		H[i] = (LL)idx*xi %P;
		xi = (LL)xi*X%P;
		if (i!=0)H[i] = (H[i]+H[i-1]) %P;
	}
	rp[0]=1, rp[1]=bin_pow(X,P-2,P);
	for (int i=2; i<n; i++){
		rp[i] = (LL)rp[i-1]*rp[1]%P;
	}
}

int Hash(int l, int r){
	if (l==0)return H[r];
	int re = H[r]-H[l-1];
	if (re<0)re+=P;
	re = (LL)re*rp[l]%P;
	return re;
}


int cnt=0;
bool same(int la ,int ra, int lb, int rb){
	if ( Hash(la,ra) != Hash(lb,rb) )return 0;
	
	cnt++;
	for (int i=0; i<ra-la; i++){
		if (s[la+i]!=s[lb+i])return 0;
	}

	return 1;
}

bool judge(){
	build_H();
	
	for (int len=1; len*2<=n; len++){
		for (int j=0; j+2*len<=n; j++){
			if ( same(j,j+len-1,j+len,j+len*2-1) ) return 0;
		}
	}
	return 1;
}

int main(int argc, char **argv){
	ifstream fres, fout;
	fres.open(argv[2],ifstream::in);
	fout.open(argv[3],ifstream::in);

	fout >> s;
	fres >> aph;
	n=s.size();

	if (n<=100000 && inRange() && judge()){
		fprintf(stderr,"OK hash:%d\n",cnt);
		printf("%.6f\n",0.1*pow(n,0.20));
	}
	else {
		fprintf(stderr,"Bad");
		puts("0.0");
	}
}
