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

void build(map<LL, vector<string> > &S,vector<LL> p){
    //for (auto ele:p)cout << ele <<" "; puts("");
    S.clear();
    string s; s.resize(4);


    LL D[4][27];
    D[0][0]=D[1][0]=D[2][0]=D[3][0]=1;
    for (int i=0; i<4; i++){
        for (int j=1; j<=26; j++){
            D[i][j]=MUL(D[i][j-1],p[i]);
        }
    }

    for (char a='A'; a<='Z'; a++){s[0]=a;
    for (char b='A'; b<='Z'; b++){s[1]=b;
    for (char c='A'; c<='Z'; c++){s[2]=c;
    for (char d='A'; d<='Z'; d++){s[3]=d;
        LL Hash=1;
        Hash=MUL(Hash, D[0][a-'A'+1] );
        Hash=MUL(Hash, D[1][b-'A'+1] );
        Hash=MUL(Hash, D[2][c-'A'+1] );
        Hash=MUL(Hash, D[3][d-'A'+1] );
//        Hash=MUL(Hash, POW(p[0],a-'A'+1) );
//        Hash=MUL(Hash, POW(p[1],b-'A'+1) );
//        Hash=MUL(Hash, POW(p[2],c-'A'+1) );
//        Hash=MUL(Hash, POW(p[3],d-'A'+1) );
        auto &v=S[Hash];
        if (v.size()<2)v.push_back(s);
    if (p[3]==1)break;}
    if (p[2]==1)break;}
    if (p[1]==1)break;}
    if (p[0]==1)break;}
}

map<LL, vector<string> > A, B;
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
    string ans;
    if (L>4){
        for (auto &pp:A){
            LL val = pp.first;
            LL ival = MUL(R,INV(val));
            auto &vec = pp.second;
            if (B[ival].size()>0){
                cnt += vec.size()*B[ival].size();
                if (cnt>1)break;
                ans.append(vec[0]);
                ans.append(B[ival][0]);
            }
        }
    }
    else {
        //puts("HI");
        cnt = A[R].size();
        //for (auto ele:A[R])cout <<ele << endl;
        if (cnt==1)ans=A[R][0];
    }
    if (ans.size()>0)ans.resize(L);
    if (cnt==0)puts("not a word");
    else if (cnt>1)puts("ambiguous");
    else cout <<ans << endl;
}

int main(){
    while ( cin >> L >> R >> P ){
        if (P==0)return 0;
        Build();
        solve();
    }
}
