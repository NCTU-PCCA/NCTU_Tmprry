#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;
char in[500];
vector<int> a[10005];
void solve(){
    for(int i = 0 ;i < 10005 ;i++){a[i].clear();}
    bool flag = true;
    int tp = 0;
    while(1){
        tp++;
        scanf("%s",in);
        if(in[0]=='E') break;
        int tmp ;
        if(in[0]=='l'){
            sscanf(in,"line_%d",&tmp);
            scanf("%s",in);
        }else{
            scanf("%s",in);
            scanf("%s",in);
            scanf("%s",in);
            sscanf(in,"line_%d",&tmp);
            a[tmp].push_back(tp);
            a[tp].push_back(-tp);
        }
    }
    stack<int> sta;
    for(int i = 1 ; i < 10005 ;i++){
        for(int j = a[i].size()-1 ;j >=0 ;j--){
            //printf("%d ",a[i][j]);
            if(sta.empty()) sta.push(a[i][j]);
            else if(sta.top()+a[i][j] == 0){
                if(sta.top()<0) goto END;
                else sta.pop();
            }else{
                sta.push(a[i][j]);
            }
        }
    }
    END:;
    if(!sta.empty()) flag = false;
    if(flag)puts("good");
    else puts("bad");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
}
