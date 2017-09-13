#include <bits/stdc++.h>
using namespace std;
int T,len;
char in[10005];
bool ans[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",in);
		for(int i = 0 ;i < 105 ;i++) ans[i] = false;
		len = strlen(in);
		char *token;
		token = strtok(in,",");
		while(token != NULL){
			int len2 = strlen(token);
			bool sp =false;
			for(int  i= 0 ;i < len2 ;i++){
				if(token[i] == '~') sp =true;
			}
			int a, b;
			if(sp){
				sscanf(token,"%d~%d",&a,&b);
				for(int i=a ;i <= b ;i++ )
					ans[i]=true;
			}else{
				sscanf(token,"%d",&a);
				ans[a] = true;
			}
			token = strtok(NULL,",");
		}
		int cnt = 0;
		for(int i = 0 ;i < 105 ; i++)if(ans[i]) cnt++;
		printf("%d:",cnt);
		for(int i = 0 ;i < 105 ; i++)if(ans[i]) printf(" %d",i);
		puts("");

	}
}
