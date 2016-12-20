#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
using namespace std;
char x[10];
char ma[]="CELAMGIGOOC";
int main(){
    int T,n,ta,tb;
    scanf("%d",&T);
    while(T--){
        scanf("%d %s", &n, x);
        ta=atoi(x);
        reverse(x,x+n);
        tb=atoi(x);
        ta=abs(ta-tb);
        sprintf(x,"%d",ta);
        reverse(x,x+n);
        tb=atoi(x);
        ta += tb;
        ta *= 40;
        sprintf(x,"%d",ta);
        int len = strlen(x);
        for(int i = 0 ;i < len ;i++){
            ta = x[i]-'0';
            printf("%c",ma[ta]);
        }
        puts("");
    }
}
