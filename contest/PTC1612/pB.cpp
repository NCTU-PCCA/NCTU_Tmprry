#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 40;
LL B[MAXN][5][5];

void build(){
    memset(B,0,sizeof(B));
    for (int i=0; i<5; i++ )B[1][i][i]=1LL;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            B[2][i][j]=1LL;
        }
    }
    B[2][3][2]=B[2][3][4]=B[2][4][2]=B[2][4][4]=0LL;
    for (int t=3; t<MAXN; t++){
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                for (int k=0; k<5; k++){
                    B[t][i][j] += B[t-1][i][k]*B[2][k][j];
                }
            }
        }
    }
}

int main(){
    build();
    int T, n; cin >>T;
    while (T--){
        cin >> n;
        LL ans = 0;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                ans += B[n][i][j];
            }
        }
        if (n==0)ans=1;
        cout << ans << endl;
    }
}
