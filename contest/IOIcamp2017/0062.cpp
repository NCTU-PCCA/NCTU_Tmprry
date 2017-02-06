// by =＾● ⋏ ●＾=
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        if(n==1) puts("NO"); // meow!
        else {
            int up = sqrt(n)+0;
            for(int i=2;i<=up;i++)
              if(n%i==0)up=0;
            if(up==0) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}
