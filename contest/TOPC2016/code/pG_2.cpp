
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL L, R, P;

LL POW(LL a, LL n){
    LL re=1;
    while (n>0){
        if (n&1)re=re*a%P;
        a=a*a%P;
        n>>=1;
    }
    return re;
}
LL MUL(LL a, LL b){
    return a*b%P;
}
LL INV(LL a){
    return POW(a,P-2);
}

void build(map<LL, vector<LL> > &S,vector<LL> p){
    //for (auto ele:p)cout << ele <<" "; puts("");
    S.clear();
    LL s;
    LL D[4][27];
    D[0][0]=D[1][0]=D[2][0]=D[3][0]=1;
    for (int i=0; i<4; i++){
        for (int j=1; j<=26; j++){
            D[i][j]=MUL(D[i][j-1],p[i]);
        }
    }
    for (int a='A'-'A'; a<='Z'-'A'; a++){s+=a*26*26*26;
    for (int b='A'-'A'; b<='Z'-'A'; b++){s+=b*26*26;
    for (int c='A'-'A'; c<='Z'-'A'; c++){s+=c*26;
    for (int d='A'-'A'; d<='Z'-'A'; d++){s+=d;
        LL Hash=1;
        Hash=MUL(Hash, D[0][a+1] );
        Hash=MUL(Hash, D[1][b+1] );
        Hash=MUL(Hash, D[2][c+1] );
        Hash=MUL(Hash, D[3][d+1] );
        auto &v=S[Hash];
        if (v.size()<2)v.push_back(s);
    if (p[3]==1)break;}
    if (p[2]==1)break;}
    if (p[1]==1)break;}
    if (p[0]==1)break;}
}

map<LL, vector<LL> > A, B;
LL p[8]={2,3,5,7,11,13,17,19};

void Build(){
    vector<LL> ps; ps.clear();
    for (int i=0; i<4 && i<L; i++){
        ps.push_back(p[i]);
    }
    while (ps.size()<4)ps.push_back(1);
    build(A,ps);

    ps.clear();
    for (int i=4; i<8 && i<L; i++){
        ps.push_back(p[i]);
    }
    while (ps.size()<4)ps.push_back(1);
    build(B,ps);
}

void solve(){
    LL cnt=0;
    vector<LL> ans;
    if (L>4){
        for (auto &pp:A){
            LL val = pp.first;
            LL ival = MUL(R,INV(val));
            auto &vec = pp.second;
            if (B[ival].size()>0){
                cnt += vec.size()*B[ival].size();
                if (cnt>1)break;
                ans.push_back(vec[0]);
                ans.push_back(B[ival][0]);
            }
        }
    }
    else {
        cnt = A[R].size();
        if (cnt==1)ans.push_back(A[R][0]);
    }
    string anss;
    for (LL ele:ans){
        anss.append(1, 'A'+ele/(26*26*26) );
        anss.append(1, 'A'+ele%(26*26*26)/(26*26) );
        anss.append(1, 'A'+ele%(26*26)/(26) );
        anss.append(1, 'A'+ele%(26)/(1) );
    }
    if (anss.size()>0)ans.resize(L);
    if (cnt==0)puts("not a word");
    else if (cnt>1)puts("ambiguous");
    else cout <<anss << endl;
}

int main(){
    while ( cin >> L >> R >> P ){
        if (P==0)return 0;
        Build();
        solve();
    }
}
