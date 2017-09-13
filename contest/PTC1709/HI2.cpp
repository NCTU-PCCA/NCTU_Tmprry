#include <bits/stdc++.h>
using namespace std;

char expr[20005];
typedef long long LL;
const LL MOD = 1000000007;
bool flag;
LL Eval2(char *expr, char *&end) {
    LL Eval0(char *, char *&,int);
    LL res=0;
    if (*(end=expr) == '(') {
        res = Eval0(end+1, end,1);
        if (*end == ')') {
			++end;
		}
		else{
			flag = true;
			return -1;
		}
    } else if((*end)<='9' && (*end)>='0'){ res=(*end)-'0';end++; }
	else {
		flag = true;
		return -1;
	}
    return res;
}

LL Eval1(char* expr, char *&end) {
	if(flag) return -1;
    LL res = Eval2(expr, end);
    while (*end=='*' && !flag)res = ( res * Eval2(end+1,end) )%MOD;
    return res;
}

LL Eval0(char* expr, char *&end,int cnt) {
	if(flag) return -1;
    LL res = Eval1(expr, end);
    while ((*end=='+' || *end=='-') && !flag)res = ( res + Eval1(end+1,end) )%MOD;
	if(*end!='\0' && cnt == 0) {
		flag = true;
	}
    return res;
}
char in[5005];
int main() {
//	puts("HI");
	int T,tp=0;
	scanf("%d",&T);
    while (T--){
		tp = 0;
		scanf("%s",in+1);
		in[0] ='(';
		int len = strlen(in);
		for(int i = 0 ;i < len ;i++){
			if(in[i] == '*') in[i] = '+';
//			if(in[i] == '-') in[i] = '+';
			if(in[i] == '/') in[i] = '+';
		}
		in[len++]=')';
		in[len]='\0';
		for(int i = 0 ;i < len ;i++){
			if(in[i] <='9' && in[i] >= '0'){
				if(in[i+1] <='9' && in[i+1] >= '0')
					continue;
				expr[tp++]='0';
			}else{
				if(in[i] == '(' && in[i+1] == '-'){
					expr[tp++]=in[i];
					i++;
					continue;
				}
				if(in[i] == '-')
					expr[tp++]='+';
				else expr[tp++]=in[i];
			}
		}
		expr[tp]='\0';
		//printf("%d ",tp);
		//puts(expr);
        char *pos=0;
		flag = false;
		LL ans = Eval0(expr,pos,0);
		if(flag || ans == -1) puts("illegal expression");
		else printf("legal expression\n");
    }
}
