#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool A[5][5],B[5][5];
int n ,m;
void input(){
    for(int i = 0 ;i < 5 ;i++)for(int j = 0 ;j < 5 ;j++)A[i][j]=B[i][j]=false;
    int a ,b;
    scanf("%d",&n);
    for(int i = 0 ;i < n ;i++){
        scanf("%d %d",&a, &b);
        A[a][b]=A[b][a]=true;
    }
    scanf("%d",&m);
    for(int i = 0 ;i < m ;i++){
        scanf("%d %d",&a, &b);
        B[a][b]=B[b][a]=true;
    }

}
void solve(){
    if(n != m){
        puts("no");
        return ;
    }
    int tp[] = {0,1,2,3};
    bool ans = false;
    do{
        bool flag = false;
        for(int i = 1 ;i < 4;i++){
            for(int j = 1 ;j < 4 ;j++){
                if(A[i][j] != B[ tp[i] ][ tp[j] ])
                    flag=true;
            }
        }
        if(!flag) ans=true;
    }while(next_permutation(tp+1,tp+4));
    if(ans)puts("yes");
    else puts("no");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        input();
        solve();
    }
}
