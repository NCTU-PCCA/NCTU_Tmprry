#include<bits/stdc++.h>
using namespace std;

int n;
struct State {
    int to;
    int dir;
    int symbol;
};

State st[15][4];
void input() {
    cin >> n;
    char ch;
    for ( int i = 1 ; i <= n - 1 ; i++ ) {
        int a, b, c;
        for ( int j = 0 ; j < 3 ; j++ ) {
            cin >> ch >> a >> ch >> b >> ch >>c >> ch;
            st[i][j] = (State) {a, b, c};
        }
    }
}

const int MAXT = 150;
int turing[MAXT];
int kase = 1;

void init() {
    for ( int i = 0 ; i < MAXT ; i++ ) turing[i] = 2;
}

bool autometa() {
    if ( n == 1 ) return true;
    int steps = 0, pos = 50, state = 1;
    while ( steps < 10 ) {
        steps++;
        State id = st[state][turing[pos]];
        turing[pos] = id.symbol;
        pos += id.dir;
        state = id.to;
//        printf("State: %d\n", state);
//        for ( int i = 45 ; i <= 55 ; i++ ) cout <<turing[i];
//        cout << endl;
        if ( state == n ) return true;
    }
    return false;
}

void solve() {
    int m, len, sym;
    cin >> m;
    cout << "Machine #" << kase++ << ":" << endl;
    for ( int i = 0 ; i < m ; i++ ) {
        cin >> len;
        init();
        for ( int j = 50 ; j < len + 50 ; j++ ) {
            cin >> turing[j];
        }
        cout << (autometa() ? "yes" : "no") << endl;
    }

}

int main(){
    int T;
    cin >> T;
    while ( T-- ) {
        input();
        solve();
    }
}
