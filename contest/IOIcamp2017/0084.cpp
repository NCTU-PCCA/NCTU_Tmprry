#include<bits/stdc++.h>
using namespace std;
int dgr[100010];
int main(void){
    int T,n,u,v;
    scanf("%d",&T);
    while(T--){
        memset(dgr,0,sizeof(dgr));
        scanf("%d",&n);
        for(int i=1;i<n;i++) scanf("%d%d",&u,&v), dgr[u]++, dgr[v]++;
        if(n==2){
            printf("1\n");
        } else {
            int ans=0;
            for(int i=1;i<=n;i++) if(dgr[i]==1) ans++;
            printf("%d\n",ans);
        }
    }
}

