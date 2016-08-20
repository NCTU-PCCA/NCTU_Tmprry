#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL Mo, Mx, Co, Cx;

void solve(){
    if (Co==0 || Cx==0){
        LL ans=0;
        if (Co==0) ans = max(ans, min(Mx,Cx) );
        if (Cx==0) ans = max(ans, min(Mo,Co) );
        cout << ans << endl;
        return;
    }

    LL Po, Px;
    Po=Px=min(Mo,Mx);
    if (Mo>Po)Po++;
    if (Mx>Px)Px++;

    Po = min(Po*Co,Mo);
    Px = min(Px*Cx,Mx);

    cout << Px+Po <<endl;
    return ;
}

int main(){
    int T;
    cin >>T;
    while (T--){
        cin >> Mo >> Mx >> Co >> Cx;
        solve();
    }
}
