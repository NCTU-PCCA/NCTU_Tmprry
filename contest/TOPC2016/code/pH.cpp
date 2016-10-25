#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main(){
    int T, n; scanf("%d",&T);
    while (T-- && scanf("%d",&n)){
        a.resize(n);
        b.resize(n);
        for (auto &x:a)scanf("%d",&x);
        for (auto &x:b)scanf("%d",&x);
        int ans=0;
        for (int i=0; i<n; i++){
            if (a[i]!=b[i])ans++;
        }
        printf("%d\n",ans);
    }
}
