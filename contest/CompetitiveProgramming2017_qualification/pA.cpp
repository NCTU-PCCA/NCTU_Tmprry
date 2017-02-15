#include <bits/stdc++.h>
using namespace std;

typedef __int128 LLLL;
typedef long long LL;

string s;
vector<LL> a,b; LL x;
stringstream ss(s);

int main(){
    while ( getline(cin,s) ){
        ss = stringstream(s);
        
        a.clear();
        b.clear();

        while (ss >> x){
            a.push_back(x);
        }
        
        getline(cin,s);
        ss = stringstream(s);

        while (ss >> x){
            b.push_back(x);
        }
        
        LLLL sum=0;

        for (int i=0; i<a.size(); i++){
            sum += (LLLL)a[i]*b[i];
        }

        
        if (sum<0){
            printf("-");
            sum*=-1;
        }

        LL base = 10000000000LL;
        LL x = sum/base;
        LL y = sum%base;

        if (x>0)
            printf("%lld%010lld\n",x,y);
        else 
            printf("%lld\n",y);
    }
}
