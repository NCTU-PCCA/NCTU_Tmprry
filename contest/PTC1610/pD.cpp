#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
char a[50004], b[50004];
int T, n;
const int INF = 88888888;
int dp[50004][260];
void input(){
    scanf("%d",&n);
    scanf("%s %s",a , b);
}
void solve(){
    int tp  = 0;
    for(int i = 0 ;i < n ;i++){
        if(a[tp] == b[i]){
            dp[tp++][0] = i;
            continue;
        }
    }
    for(int i = tp ; i < n ;i++) dp[i][0] = INF;

    for(int j = 1 ; j < min(n,260) ;j++){
        for(int i = 0 ; i < n ;i++){
            if(i < j){
                dp[i][j]=-1;
                continue;
            }
            dp[i][j]=dp[i-1][j-1];
            int gg = min(dp[i][j],n);
            for(int k = dp[i-1][j]+1 ; k < gg ;k++){
                if(a[i] == b[k]){
                    dp[i][j]=k;
                    break;
                }
            }
        }
    }
    int ans;
    for(int i = 0 ;i < min(n,260) ;i++){
       if(dp[n-1][i] != INF){
            ans = n - i;
            break;
       }
    }
    if(n*995 > ans*1000){
        puts("different");
    }else{
        printf("%d/%d\n",ans,n);
    }
    //printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--){
        input();
        solve();
    }
}
