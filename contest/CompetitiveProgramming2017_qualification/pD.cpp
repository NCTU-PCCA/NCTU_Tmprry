#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, BIT[MAXN], r[MAXN]; 
pair<int,int> a[MAXN];
long long ans;

void add(int pos){
    while (pos<=n){
        BIT[pos]++;
        pos += pos&(-pos);
    }
}

int sum(int pos){
    int re=0;

    while (pos>0){
        re += BIT[pos];
        pos -= pos&(-pos);
    }
    
    return re;
}

void input(){
    scanf("%d",&n);
    for (int i=0, ai; i<n; i++){
        scanf("%d",&ai);
        a[i] = pair<int,int>(ai,i);
    }
    sort(a,a+n);
    for (int i=0; i<n; i++){
        r[ a[i].second ]=i+1;
    }
}

void solve(){
    ans=0;
    memset(BIT,0,sizeof(BIT));
    
    for (int i=0; i<n; i++){
        ans += sum(n) - sum(r[i]);
        add(r[i]);
    }
    cout << ans << endl;
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        solve();
    }
}
