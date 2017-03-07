#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535897932;

struct Complex{
    typedef double T;
    T x, y;
    Complex (T _x=0.0, T _y=0.0)
        :x(_x),y(_y){ }
    Complex operator + (const Complex &b) { return Complex(x+b.x,y+b.y); }
    Complex operator - (const Complex &b) { return Complex(x-b.x,y-b.y); }
    Complex operator * (const Complex &b) { return Complex(x*b.x-y*b.y,x*b.y+y*b.x); }
};

void FFT(Complex *a, int s, int d, int n, int rev=1){
    static const int MAXN = 65536;
    static Complex tmp[MAXN];

    // call FFT(0,1,n) n=2^k
    // rev = 1 or -1

    if (n==1) return;

    Complex wn( cos(2*PI*rev/n) , sin(2*PI*rev/n) );
    Complex w(1,0);

    FFT(a,s,d*2,n/2,rev);   // y0[i] = a[ s+d*2i ]
    FFT(a,s+d,d*2,n/2,rev); // y1[i] = a[ s+d*(2i+1) ]
    
    for (int k=0; k<(n>>1); k++){
        Complex t = w * a[ (s+d) + d*(2*k) ];
        Complex u = a[ s+d*(2*k) ];
        tmp[ s+d*k ] = u+t;
        tmp[ s+d*(k+n/2) ] = u-t;
        w = w*wn;
    }

    for (int i=0; i<n; i++){
        a[s+d*i] = tmp[s+d*i];
    }

    if (rev==-1){
        for (int i=0; i<n; i++){
            a[s+d*i].x /= 2.0;
            a[s+d*i].y /= 2.0;
        }
    }
}

const int MAXN = 65536;
int n;
Complex a[MAXN], b[MAXN];

void input(){
    scanf("%d", &n);

    for (int i=0 ,ai; i<n; i++){
        scanf("%d", &ai);
        a[i] = Complex(ai,0);
    }

    for (int i=0, bi; i<n; i++){
        scanf("%d", &bi);
        b[i] = Complex(bi,0);
    }

    for (int i=n; i<MAXN; i++){
        a[i] = b[i] = Complex(0,0);
    }
}

void solve(){
    FFT(a,0,1,MAXN);
    FFT(b,0,1,MAXN);

    for (int i=0; i<MAXN; i++){
        a[i] = a[i]*b[i];
    }
    
    FFT(a,0,1,MAXN,-1);
    for (int i=0; i<2*n-1; i++){
        printf("%.0f%c", a[i].x, i==2*n-2?'\n':' ');
    }
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        solve();
    }
}
