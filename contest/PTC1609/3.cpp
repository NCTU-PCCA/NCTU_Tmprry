#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

map<int, vector<int> > G;
map<int,int> dis;

void test(string &s, int x, int y){
	int u = stoi(s);
	swap(s[x],s[y]);
	int v = stoi(s);
	G[u].push_back(v);
	swap(s[x],s[y]);
}

void build_edge(){
	string s="012345678";
	do {
		int id = stoi(s);
		dis[id] = INF;
		if (s[0]=='0'){
			test(s,0,1);
			test(s,0,3);
		}
		else if (s[1]=='0'){
			test(s,1,0);
			test(s,1,2);
			test(s,1,4);
		}
		else if (s[2]=='0'){
			test(s,2,1);
			test(s,2,5);
		}
		else if (s[3]=='0'){
			test(s,3,0);
			test(s,3,4);
			test(s,3,6);
		}
		else if (s[4]=='0'){
			test(s,4,1);
			test(s,4,3);
			test(s,4,5);
			test(s,4,7);
		}
		else if (s[5]=='0'){
			test(s,5,2);
			test(s,5,4);
			test(s,5,8);
		}	
		else if (s[6]=='0'){
			test(s,6,3);
			test(s,6,7);
		}
		else if (s[7]=='0'){
			test(s,7,4);
			test(s,7,6);
			test(s,7,8);
		}
		else if (s[8]=='0'){
			test(s,8,5);
			test(s,8,7);
		}
	}while( next_permutation(s.begin(),s.end()) );
}

void BFS(){
	int P=0;
	for (int i=1, ai; i<=9; i++){
		scanf("%d",&ai);
		P = P*10+ai;
	}
	static queue<int> que;
	que.push( P );
	dis[P]=1;

	while (!que.empty()){
		int u = que.front(); que.pop();
		for (int v:G[u]){
			if (dis[v]!=INF)continue;
			dis[v]=dis[u]+1;
			que.push(v);
		}
	}
}

void solve(){
	int P=0;
	for (int i=1, ai; i<=9; i++){
		scanf("%d",&ai);
		P = P*10+ai;
	}
	if (dis[P]==0 || dis[P]==INF)puts("Infinite");
	else printf("%d\n",dis[P]-1);
}

int main(){
	build_edge();
	int T; cin >> T;
	BFS();
	while (T--)solve();
}
