#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
struct XDD{
    long long a,x;
    friend bool operator < (XDD a, XDD b){
        return a.a < b.a;
    }
};
vector<XDD> vec;
int T;
int main(){
    scanf("%d",&T);
    while(T--){
        vec.clear();
        int n;
        scanf("%d",&n);
        for(int i = 0 ;i < n ;i++){
            long long  a, b;
            scanf("%lld %lld",&a,&b);
            vec.push_back((XDD){a,1});
            vec.push_back((XDD){b,-1});
        }
        sort(vec.begin(),vec.end());
        int now=0,ans=0;
        for(int i = 0 ;i < vec.size() ;i++){
            if(vec[i].x == 1) now++;
            ans = max(ans,now);
            if(vec[i].x == -1) now--;
        }
        printf("%d\n",ans);
    }
}
