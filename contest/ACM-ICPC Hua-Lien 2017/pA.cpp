#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
int n, d, a[MAXN], b[MAXN];

int ABS(int x){
    if (x<0)return -x;
    return x;
}

bool check(int a[MAXN]){
    for (int i=1; i<n; i++){
        if ( ABS(a[i]-a[i-1]) > d ) return 0;
    }
    return 1;
}

void cp(){
    for (int i=0; i<n; i++)b[i]=a[i];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n!=0){
        cin >> d;
        for (int i=0; i<n; i++) cin >> a[i];

        bool ans = check(a);

        cp();
        b[0] = b[1];
        ans |= check(b);

        cp();
        b[n-1] = b[n-2];
        ans |= check(b);

        for (int i=1; i<n-1; i++){
            cp();
            b[i] = (b[i+1]+b[i-1])/2;
            ans |= check(b);
        }
        cout << (ans?"Y":"N") << '\n';
    }

	return 0;
}
