#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long l, r, num[5];
long long dp[3][16384*5+5],in[5][4150];
void input(){
    for(long long i = 0; i < 3; i++)for(long long j= 0; j < 13684*5+5;j++) dp[i][j]=0;
    scanf("%lld %lld", &l, &r);
    scanf("%lld %lld %lld %lld %lld", num, num+1, num+2, num+3, num+4);
    for(long long i = 0 ; i < 5; i++){
        for(long long j = 0 ; j < num[i] ;j++){
            scanf("%lld",&in[i][j]);
        }
    }
}
void solve(){
    for(long long i = 0; i < num[1]; i++){
        for(long long j = 0; j < num[2] ; j++){
            dp[0][ in[1][i]+in[2][j] ]++;
        }
    }
    for(long long i = 0; i < num[0] ; i++){
        for(long long j = 0 ;j <= 16384*2+2 ;j++){
            dp[2][j+in[0][i] ]+=dp[0][j];
        }
    }
    dp[0][0]=0;
    for(long long i = 1; i <= 16384*5 ;i++){
        dp[0][i]=dp[0][i-1]+dp[2][i];
    }

    /*puts("");
    for(long long i = 0; i < 10 ; i++) printf("%lld ",dp[0][i]);
    puts("\n");*/

    for(long long i = 0; i < num[3]; i++){
        for(long long j = 0; j < num[4] ; j++){
            dp[1][ in[3][i]+in[4][j] ]++;
        }
    }
    long long ans=0;
    for(long long i = 0 ;i <= 16384*2;i++){
        if(i>=r)break;
        else if (i<l){
            int nl = l-i, nr = r-i;
            ans += (dp[0][nr]-dp[0][nl-1])*dp[1][i];
        }
        else {
            int nr = r-i;
            ans += dp[0][nr]*dp[1][i];
        }
        /*
        long long nl= i<l ? l-i : 0;
        long long nr= r-i;
        //printf("gg %lld %lld %lld\n",i,nl,nr);
        if(nl==0)ans+=dp[0][nr]*dp[1][i];
        else ans+=(dp[0][nr]-dp[0][nl-1])*dp[1][i];
        */
    }
    printf("%lld\n",ans);

}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        input();
        solve();
    }
}
