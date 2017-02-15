#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int SG(int n){
    int re=0;
    
    if (n%2==0){
        re++;
        while (n%2==0)n/=2;
    }

    for (int i=3; i*i<=n; i++){
        while (n%i==0){
            re++;
            n/=i;
        }
    }
    if (n!=1)re++;

    return re;
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        int n, ans=0;
        scanf("%d",&n);

        for (int i=0, ai; i<n; i++){
            scanf("%d",&ai);
            ans ^= SG(ai);
        }
        puts(ans==0?"Bob":"Alice");
    }
}
