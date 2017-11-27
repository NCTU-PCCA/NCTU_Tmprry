#include <bits/stdc++.h>
using namespace std;

typedef long long Int;
const int MAXN = 40004;

int n, K;
Int w[MAXN], d[MAXN];
Int wd[MAXN];
Int ans[MAXN];
int S[MAXN];

bool cmp(int i, int j){
    return wd[i] < wd[j];
}

void init(){
    cin >> n >> K;
    for (int i=0; i<n; i++) cin >> w[i];
    for (int i=0; i<n; i++) cin >> d[i];

    memset(ans,0,sizeof(ans));
    for (int i=0; i<n; i++) wd[i] = w[i] * d[i];
}

template<typename T>
T get_value(int i, T x){
    return w[i] * (d[i]+x);
}

double get_intersection(double y1, double r1, double y2, double r2){
    return (y2-y1)/(r1-r2);
}

const double INF = 1e20;
vector<double> Xs1;
vector<int> idx1;

Int cal1(Int x){
    Xs1.push_back(INF);
    int token = upper_bound(Xs1.begin(),Xs1.end(),x)-Xs1.begin();
    Xs1.pop_back();
    return get_value( idx1[token-1] , (Int)x);
}

void insert_seg1(int u){
    while ( Xs1.size() && get_value( idx1.back() , Xs1.back() ) <= get_value(u,Xs1.back()) ){
        Xs1.pop_back();
        idx1.pop_back();
    }
    if (Xs1.empty()){
        Xs1.push_back(0);
        idx1.push_back(u);
        return;
    }
    int i = u, j = idx1.back();
    if ( w[i] > w[j] ){
        double x = get_intersection(wd[i],w[i],wd[j],w[j]);
        Xs1.push_back(x);
        idx1.push_back(u);
    }
}

deque<double> Xs;
deque<int> idx;

Int cal(Int x){
    int token = lower_bound(Xs.begin(),Xs.end(),x)-Xs.begin();
    return get_value( idx[token], (Int)x );
}

void insert_seg(int u){
    while ( Xs.size() && get_value( idx.front() , Xs.front() ) <= get_value(u,Xs.front()) ){
        Xs.pop_front();
        idx.pop_front();
    }
    if (Xs.empty()){
        Xs.push_back(INF);
        idx.push_back(u);
        return;
    }
    int i = u, j = idx.front();
    if ( w[i] < w[j] ){
        double x = get_intersection(wd[i],w[i],wd[j],w[j]);
        Xs.push_front(x);
        idx.push_front(u);
    }
}

void solve(){
    for (int i=0; i<n; i++) S[i]=i;
    sort(S,S+n,cmp);

    // top-down ---------------------------------
    Xs1.clear(); Xs1.resize(1,0.0);
    idx1.clear(); idx1.resize(1,S[n-1]);
    for (int i=n-2; i>=0; i--){
        int u = S[i];
        ans[u] = max( ans[u] , cal1(d[u]) );
        insert_seg1(u);
    }

    // bottom up --------------------------------
    Xs.clear(); Xs.push_back(INF);
    idx.clear(); idx.push_back(S[0]);
    for (int i=1; i<n; i++){
        int u = S[i];
        ans[u] = max( ans[u] , cal(d[u]) );
        insert_seg(u);
    }
}

void output(){
    sort(ans,ans+n);
    cout << ans[K-1] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--){
        init();
        solve();
        output();
    }
	return 0;
}
