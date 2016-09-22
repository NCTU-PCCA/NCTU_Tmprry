#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char inn[10];
int in[4];
int ans,anscnt,mm=-1;
void input(){
    scanf("%s",inn);
    anscnt=0;
    ans=99999;
    in[0]=inn[0]-'0';
    in[1]=inn[1]-'0';
    in[2]=inn[2]-'0';
    in[3]=inn[3]-'0';
}
int cnt(int a, int b){
    if(a>b)swap(a,b);
    return min(b-a,a+10-b);
}
void solve(){
    for(int i = 0 ; i <= 9; i++){
        for(int j = 0; j <= 9 ;j++){
            if(i == j) continue;
            for(int u = 0; u <= 9; u++){
                if(j == u || i == u) continue;
                for(int v = 0; v <= 9 ;v++){
                    if(u == v || j == v || i == v) continue;
                    int tmp=cnt(in[0],i)+cnt(in[1],j)+cnt(in[2],u)+cnt(in[3],v);
                    if(tmp<ans){
                        ans=tmp;
                        anscnt=1;
                        mm=i*1000+j*100+u*10+v;
                    }else if(tmp == ans){
                        anscnt++;
                    }
                }
            }
        }
    }
    printf("%d %d %04d\n",anscnt,ans,mm);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        input();
        solve();
    }
}
