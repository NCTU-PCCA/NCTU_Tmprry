#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

vector<int> S;
int cnt[15];

void input() {
    S.clear();
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0 ; i < 6;  i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
}

void solve() {
    for (int i = 1 ; i <= 13 ; i++ ) {
        if (cnt[i]) S.push_back(cnt[i]);
    }
    sort(S.begin(), S.end());
    if ( S.size() == 6 ) {
        puts("single");
    } else if ( S.size() == 5 ) {
        puts("one pair");
    } else if ( S.size() == 4 ) {
        if ( S[2] == 2 ) puts("two pairs");
        else if ( S[2] == 1 ) puts("one triple");
    } else if ( S.size() == 3) {
        if ( S[2] == 2 ) puts("three pairs");
        else if ( S[2] == 3 ) puts("full house");
        else if ( S[2] == 4 ) puts("tiki");
    } else if ( S.size() == 2) {
        if ( S[0] == 2 ) puts("tiki pair");
        else if ( S[1] == 3 ) puts("two triples");
    }
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        input();
        solve();
    }
}
