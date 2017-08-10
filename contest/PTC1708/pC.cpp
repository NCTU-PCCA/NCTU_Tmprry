#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
ULL J[21];

void build(){
    J[0] = J[1] = 1;
    for (int i=2; i<=20; i++){
        J[i] = J[i-1]*i;
    }
}

int n;
char s[100];
int cnt[26];

ULL cal(){
    int sz=0;
    for (int i=0; i<26; i++)sz += cnt[i];
    ULL ans = J[sz];
    for (int i=0; i<26; i++)ans /= J[ cnt[i] ];
    return ans;
}

int main(){
    build();

    int T; cin >> T;
    while (T-- && scanf("%s", s)){
        memset(cnt,0,sizeof(cnt));

        n = strlen(s);
        for (int i=0; i<n; i++){
            cnt[ s[i]-'a' ]++;
        }

        ULL ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<26; j++){
                if (cnt[j]==0)continue;
                if (s[i]-'a'==j)break;
                cnt[j]--;
                ans += cal();
                cnt[j]++;
            }
            cnt[ s[i]-'a' ]--;
        }
        cout << ans << endl;
    }
}
