#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
long long a, b, anslen, ansM;
map<long long ,long long> ans, ans2;
long long gett(long long now){
    //printf("%lld\n",ans);
    if(ans[now] != 0) return ans[now];
    if(now&1) ans[now] = gett(now*3+1) + 1;
    else ans[now] = gett(now/2) + 1;
    return ans[now];
}
long long gett2(long long now){
    if(ans2[now] != 0) return ans2[now];
    if(now&1) ans2[now] = gett2(now*3+1);
    else ans2[now] = max(gett2(now/2), now);
    return ans2[now];
}

void solve(){
    ansM=anslen=-1;

    for(long long i = a; i <= b; i++){
        long long tmp = gett(i);
        anslen = max(anslen, tmp);
        tmp = gett2(i);
        ansM = max(ansM, tmp);
    }
    printf("%8lld %8lld\n", anslen ,ansM);
}
int main(){
    //freopen("data4.txt","r",stdin);
    ans[1]=1;ans2[1]=1;
    while(~scanf("%lld %lld", &a, &b)){
        printf("%8lld %8lld ", a, b);
        if(a > b) swap(a, b);
        solve();
    }
}
