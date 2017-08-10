#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
double gg[23][23],tmp[23][23],ans=0;
int n,m,sx,sy,ex,ey;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d %d",&n,&m);
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		if(n ==1 && m == 1){
			printf("0.00");
			continue;
		}
		if(n == 1 || m == 1){
			if(m == 1){
				swap(n,m);
				swap(sx,sy);
				swap(ex,ey);
			}
			gg[sx][sy] = 1;
			for(int zz = 1 ; zz < 100000 ;zz++){
				for(int i = 0 ;i <= n ;i++)for(int j=0 ;j <=m ;j++ )
					tmp[i][j] = 0;
				for(int i = 2 ;i < m ;i++){
					tmp[1][i-1]+=gg[1][i]/2;
					tmp[1][i+1]+=gg[1][i]/2;
				}
				tmp[1][2]+=gg[1][1];
				tmp[1][m-1]+=gg[1][m];
	
				ans+=(double)zz*tmp[ex][ey];
				tmp[ex][ey]=0;
				for(int i = 0 ;i <= n ;i++)for(int j=0 ;j <=m ;j++ )
					gg[i][j]=tmp[i][j];
			}
			printf("%.2f\n",ans);
			continue;
		}
		gg[sx][sy] = 1;
		for(int zz =1 ;zz < 100000;zz++){
			for(int i = 0 ;i <= n ;i++)for(int j=0 ;j <=m ;j++ )
				tmp[i][j] = 0;
			tmp[1][2]+=gg[1][1]/2;
			tmp[2][1]+=gg[1][1]/2;

			tmp[n-1][m]+=gg[n][m]/2;
			tmp[n][m-1]+=gg[n][m]/2;

			tmp[n-1][1]+=gg[n][1]/2;
			tmp[n][2]+=gg[n][1]/2;

			tmp[1][m-1]+=gg[1][m]/2;
			tmp[2][m]+=gg[1][m]/2;
			for(int i = 2 ;i < n ;i++){
				tmp[i-1][1]+= gg[i][1]/3;
				tmp[i+1][1]+= gg[i][1]/3;
				tmp[i][2]+= gg[i][1]/3;

				tmp[i-1][m]+=gg[i][m]/3; 
				tmp[i+1][m]+=gg[i][m]/3; 
				tmp[i][m-1]+=gg[i][m]/3; 
			}
			for(int i = 2 ;i < m ;i++){
				tmp[1][i-1]+=gg[1][i]/3;
				tmp[1][i+1]+=gg[1][i]/3;
				tmp[2][i]+=gg[1][i]/3;

				tmp[n][i-1]+=gg[n][i]/3;
				tmp[n][i+1]+=gg[n][i]/3;
				tmp[n-1][i]+=gg[n][i]/3;
			}
			for(int i = 2 ;i < n ;i++){
				for(int j = 2 ;j < m ;j++){
					tmp[i+1][j]+=gg[i][j]/4;
					tmp[i-1][j]+=gg[i][j]/4;
					tmp[i][j+1]+=gg[i][j]/4;
					tmp[i][j-1]+=gg[i][j]/4;
				}
			}
			ans+=(double)zz*tmp[ex][ey];
			tmp[ex][ey]=0;
			for(int i = 0 ;i <= n ;i++)for(int j=0 ;j <=m ;j++ )
				gg[i][j]=tmp[i][j];
			
		}
		printf("%.2f\n",ans);
	}
}
