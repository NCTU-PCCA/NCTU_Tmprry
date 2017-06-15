#include <bits/stdc++.h>
using namespace std;
double a[50005];
string s;
int main(){
	int T;
	cin >> T;
	a[1] = 0;
	for(int i = 2 ;i <50005 ;i++){
		a[i]=a[i-1]+log10((double)i);
	}
/*	for(int i = 1 ;i < 20 ;i++){
		printf("%d %f\n",i,a[i]);
	}*/
	while(T--){
		cin >> s;
		if(s.size()<=8){
			int tmp = stoi(s,nullptr,10);
			int a = 1;
			for(int i = 1 ;;i++){
				a*=i;
				if(a == tmp){
					printf("%d\n",i);
					break;
				}
			}
		}else{
			double sz = (double)s.size();
			for(int i = 11 ;i < 50005 ;i++){
				if(sz-1 < a[i]){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}
