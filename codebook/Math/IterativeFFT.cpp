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

void BitReverse(Complex *a, int n){
    for (int i=1, j=0; i<n; i++){
        for (int k = n>>1; k>(j^=k); k>>=1);
        if (i<j) swap(a[i],a[j]);
    }
}

void FFT(Complex *a, int n, int rev=1){ // rev = 1 or -1
    BitReverse(a,n);
    Complex *A = a;

    for (int s=1; (1<<s)<=n; s++){
        int m = (1<<s);

        Complex wm( cos(2*PI*rev/m) , sin(2*PI*rev/m) );
        for (int k=0; k<n; k+=m){
            Complex w(1,0);
            for (int j=0; j<(m>>1); j++){
                Complex t = w * A[k+j+(m>>1)];
                Complex u = A[k+j];
                A[k+j] = u+t;
                A[k+j+(m>>1)] = u-t;
                w = w*wm;
            }
        }
    }

    if (rev==-1){
        for (int i=0; i<n; i++){
            A[i].x /= n;
            A[i].y /= n;
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
    FFT(a,MAXN);
    FFT(b,MAXN);

    for (int i=0; i<MAXN; i++){
        a[i] = a[i]*b[i];
    }
    
    FFT(a,MAXN,-1);
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
