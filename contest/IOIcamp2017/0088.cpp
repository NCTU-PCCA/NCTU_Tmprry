#include <bits/stdc++.h>
using namespace std;

void star(char *s){
    int n = strlen(s);

    s[2*n+1]=0;
    for (int i=2*n-1; i>=1; i-=2){
        s[i]=s[i/2];
    }
    for (int i=2*n; i>=0; i-=2){
        s[i]='*';
    }
}

const int MAXN = 200005;
int p[MAXN], ivp[MAXN] ,q=179433857;

void build_p(){
    p[0]=ivp[0]=1;
    p[1]=712271227;
    ivp[1]=156770592;

    for (int i=2; i<MAXN; i++){
        p[i] = (long long) p[i-1]*p[1]%q;
        ivp[i] = (long long) ivp[i-1]*ivp[1]%q;
    }
}

struct HashString{
    int n; char *s;
    int hl[MAXN], hr[MAXN];

    void build(char *_s){
        s = _s;
        n = strlen(s);

        for (int i=0; i<n; i++){
            hl[i] = (long long) s[i] * p[i] % q;
            hr[i] = (long long) s[i] * p[n-i-1] % q;
        }
        for (int i=1; i<n; i++){
            hl[i] = (hl[i]+hl[i-1])%q;
            hr[i] = (hr[i]+hr[i-1])%q;
        }
    }

    int H(int l, int r){
        if (l<=r){
            int d = hl[r]-(l==0?0:hl[l-1]);
            if (d<0)d+=q;
            return (long long) d * ivp[l] % q;
        }
        else {
            int d = hr[r]-(l==0?0:hr[l-1]);
            if (d<0)d+=q;
            return (long long) d * ivp[n-r-1] % q;
        }
    }
};

int n, m;
char s[MAXN], t[MAXN];

HashString hs, ht;

bool ok(int L){
    return 1;
}

int main(){
    build_p();

    int T; scanf("%d",&T);
    
    while (T--){
        scanf("%s%s",s,t);
        star(s); n=strlen(s);
        star(t); m=strlen(t);

        hs.build(s);
        ht.build(t);

        int l=1, r=min(n,m)/2;
        if (ok(r))l=r=r+1;
        while (l!=r){
            int mid = (l+r)>>1;
            if (ok(mid*2+1))l=mid+1;
            else r=mid;
        }

        cout << hs.H(0,2) << endl;
        cout << hs.H(2,0) << endl;
        cout << l-1 << endl;
    }
}
