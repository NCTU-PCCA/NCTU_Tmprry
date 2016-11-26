#include<bits/stdc++.h>
using namespace std;

char s[3000];
typedef pair<int, int> pii;
map<pii, bool> vis;
map<pii, bool> toL;
map<pii, bool> toR;
map<pii, bool> toU;
map<pii, bool> toD;


void solve() {
    vis.clear();
    toL.clear();
    toR.clear();
    toU.clear();
    toD.clear();
    int x, y, len = strlen(s), res = 0;
    x = y = 2048;
    pii cur = pii(x, y);
    for ( int i = 0 ; i < len ; i++ ) {
//        printf("(%d, %d) %c\n", cur.first, cur.second, s[i]);
        pii nxt= cur;
        if ( s[i] == 'U' ) {
            nxt.first--;
            if ( !toU[cur] && vis[nxt] ) res++;
            toU[cur] = toD[nxt] = vis[cur] = 1;
        } else if ( s[i] == 'D' ) {
            nxt.first++;
            if ( !toD[cur] && vis[nxt] ) res++;
            toD[cur] = toU[nxt] = vis[cur] = 1;
        } else if ( s[i] == 'L' ) {
            nxt.second--;
            if ( !toL[cur] && vis[nxt] ) res++;
            toL[cur] = toR[nxt] = vis[cur] = 1;
        } else if ( s[i] == 'R' ) {
            nxt.second++;
            if ( !toR[cur] && vis[nxt] ) res++;
            toR[cur] = toL[nxt] = vis[cur] = 1;
        }
//        printf("nxt (%d, %d) %c\n", nxt.first, nxt.second, s[i]);
        cur = nxt;
    }
    cout << res+1 << endl;
}

int main(){
    int T;
    cin >> T;

    while ( T-- ) {
        cin >> s;
        solve();
    }
}
