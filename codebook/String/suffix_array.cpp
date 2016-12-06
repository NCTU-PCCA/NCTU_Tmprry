const int MAX_N = 100000 + 10;
char str[MAX_N];
int sa[MAX_N] , cnt[MAX_N] , rk[2][MAX_N] , ht[MAX_N];
inline void build_sa(int n , int m) {
    int *x = rk[0] , *y = rk[1];
    REP(i , m) cnt[i] = 0;
    REP(i , n + 1) cnt[x[i] = str[i]]++;
    REP1(i , 1 , m - 1) cnt[i] += cnt[i - 1];
    for(int i = n; i >= 0; i--) sa[--cnt[x[i]]] = i;
    for(int k = 1; ; k <<= 1) {
        int p = 0;
        REP1(i , n - k + 1 , n) y[p++] = i;
        REP(i , n + 1) if(sa[i] >= k) y[p++] = sa[i] - k;
        REP(i , m) cnt[i] = 0;
        REP(i , n + 1) cnt[x[y[i]]]++;
        REP1(i , 1 , m - 1) cnt[i] += cnt[i - 1];
        for(int i = n; i >= 0; i--) sa[--cnt[x[y[i]]]] = y[i];
        swap(x , y);
        p = 1;
        x[sa[0]] = 0;
        REP1(i , 1 , n) x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++);
        if(p >= n + 1) break;
        else m = p;
    }
}
void build_ht(int n) {
	int *x = rk[0];
	REP1(i , 1 , n) x[sa[i]] = i;
	for(int i = 0 , h = 0; i < n; i++) {
		int j = sa[x[i]-1];
		if(h) h--;
		while(str[i + h] == str[j + h]) h++;
		ht[x[i]] = h;
	}
}
int main() {
	scanf("%s",str);
	int n = strlen(str);
	build_sa(n , 128);
	build_ht(n);
	REP1(i , 1 , n) printf("%d%c",sa[i] + 1," \n"[i == n]);
	REP1(i , 2 , n) printf("%d%c",ht[i]," \n"[i == n]);
	return 0;
}
