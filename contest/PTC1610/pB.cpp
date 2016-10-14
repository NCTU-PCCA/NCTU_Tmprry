#include<bits/stdc++.h>

using namespace std;

const int MAXN = 505;
const int MAXT = 10000000;
int n, m;
int a[MAXN];
int mi;

void input() {
    cin >> n >> m;
    mi = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        mi = max(mi, a[i]);
    }
}

bool check(int val) {
//    printf("val = %d, mi = %d\n", val, mi);
    int tmp = 0, seq = 0;
    for (int i = 0 ; i < n ;  ) {

        while ( i < n && tmp <= val ) {
            if ( tmp + a[i] > val ) break;
            tmp += a[i];
            i++;
        }
        seq++;
        tmp = 0;
    }
    return seq <= m;
}

int solve() {
    int lo = mi, hi = MAXT * n + 1, mid;
    while ( lo != hi ) {
        mid = lo + (hi - lo)/2;
        if ( abs(hi - lo) < 10 ) {
            for ( int i = lo ; i <= hi ; i++ ) {
                if ( check(i) ) {
                    return i;
                }
            }
//            printf("lo hi = %d %d\n", lo, hi);
        }
        if ( check(mid) ) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    int T;
    cin >> T;
    while ( T-- ) {
        input();
        cout << solve() << endl;
    }

}
