#include <bits/stdc++.h>
using namespace std;

bool test(const string &s){
	int sta=0;
	for (int i=0; i<s.size(); i++){
		char c = s[i];
		if ('a'<=c && c<='j' )sta++;
		else if ( c=='Z' ){ if (sta<1)return 0;}
		else if ( c=='U' ){if (sta--<2)return 0;}
		else if ( c=='M' ){if (sta--<2)return 0;}
		else if ( c=='T' ){if (sta--<2)return 0;}
		else if ( c=='R' ){if (sta--<2)return 0;}
		else return 0;
	}
	return 1;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	string s;
	while (T--){
		cin >> s;
		puts( test(s) ?"YES":"NO");
	}
}
