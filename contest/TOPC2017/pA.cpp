#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int A[20],B[20],n,m,AA[20],BB[20],a,b;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        a=b=0;
        for(int i = 0 ;i < n ;i++) scanf("%d",&A[i]);
        for(int i = 0 ;i < m ;i++) scanf("%d",&B[i]);
        for(int i = 0 ;i < 20 ;i++) AA[i] =0;
        
        for(int i = 0 ;i < n ;i++) AA[A[i]]++;
        for(int i = 0 ;i < m ;i++) AA[B[i]]++;
        for(int i = 0 ;i <= 10 ;i++){
            if(AA[i] == 2) a++;
            if(AA[i] > 0) b++;
        }

        if(a*2>b)puts("1");
        else puts("0");



    }
}
