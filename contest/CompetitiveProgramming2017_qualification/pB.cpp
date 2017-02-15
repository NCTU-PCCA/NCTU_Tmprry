#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while ( ~scanf("%d",&n) ){
        long long sum=0;
        for (int i=1, ai; i<=n; i++){
            scanf("%d",&ai);
            sum += (long long )ai*ai;
        }
        printf("%.03f\n",sqrt(sum));
    }
}
