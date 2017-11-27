#include <bits/stdc++.h>
using namespace std;
int n, d;
int cnt[22][22];  //  [s][t]

void input(){
    for(int i = 0 ;i < 22 ;i++)
        for(int j = 0 ;j < 22 ;j++)
            cnt[i][j] = 0;
    scanf("%d",&n);
    if(n == 0 ) exit(0);
    scanf("%d",&d);
}
bool check(int now){
    int heap[22];
    for(int i = 0 ;i < 22 ;i++) heap[i]=0;
    int left = 0;
    for(int i = 1 ;i <= d ;i++){
        left = now;
        for(int j = i ;j <= d ;j++){
            heap[j]+=cnt[i][j];
        }
        if(now < heap[i]) return false;
        for(int j = i ;j <= d ;j++){
            int token = min(left,heap[j]);
            heap[j]-=token;
            left-=token;
            if(left == 0 ) break;
        }
    }
    return true;
}
void solve(){
    int now = 0;
    int s, t;

    for(int i = 0 ;i < n ;i++){
        scanf("%d %d",&s,&t);
        cnt[s][t]++;
        if(!check(now)){
            now++;
            printf("%d ",i+1);
        }
    }
    puts("");
}
int main(){
    while(1){
        input();
        solve();
    }
	return 0;
}
