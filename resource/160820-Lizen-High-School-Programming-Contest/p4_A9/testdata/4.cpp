#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;
void putt(int n);
void ttup(int n);
long long ans,a;
void gett(long long now){
    long long tmp=1;
    long long need=now+1,tt=2;
    while(need){
        if(need&1){
            tmp*=tt;
            tmp%=1000000007;
        }
        tt*=tt;
        tt%=1000000007;
        need>>=1;
    }
//printf("%lld\n",tmp);
    if(now&1){
        tmp++;
    }
    tmp+=1000000007;
    tmp-=2;
    tmp*=333333336;
    tmp%=1000000007;
    printf("%lld\n",tmp);
}
int main(){
  for (int i=0; i<30; i++){
    char fin[100], fout[100];
    sprintf(fin,"%02d.in",i+1);
    sprintf(fout,"%02d.out",i+1);

    freopen(fin,"r",stdin);

    scanf("%lld",&a);

    freopen(fout,"w",stdout);
    gett(a);
    if(a<=10) putt(a);

  }

}
void putt(int n){
    if(n==2){
        ans+=2;
        printf("Move ring %d out\n",2);
        printf("Move ring %d out\n",1);
    }else if(n==1){
        ans++;
        printf("Move ring %d out\n",n);
    }else{
        ans++;
        putt(n-2);
        printf("Move ring %d out\n",n);
        ttup(n-2);
        putt(n-1);
    }
}
void ttup(int n){
    if(n==2){
            ans+=2;
        printf("Move ring %d in\n",1);
        printf("Move ring %d in\n",2);
    }else if(n==1){
            ans++;
        printf("Move ring %d in\n",n);
    }else{
            ans++;
        ttup(n-1);
        putt(n-2);
        printf("Move ring %d in\n",n);
        ttup(n-2);
    }
}
