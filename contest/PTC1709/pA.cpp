#include <bits/stdc++.h>
using namespace std;
char in[1005],ch[1005];
int tp = 1;
int go(int now){
}
int main(){
	int T; cin >> T; 
	while(T--){
		ch[0]='(';
		scanf("%s",in);
		int len = strlen(in);
		for(int i = 0 ;i < len ;i++){
			if(in[i] <='9' && in[i] >= '0'){
				if(in[i+1] <='9' && in[i+1] >= '0')
					continue;
				ch[tp++]='0';
			}else{
				ch[tp++]=in[i];
			}
		}
		ch[tp++]=')';
		ch[tp]='\0';
				
		
	}
}
