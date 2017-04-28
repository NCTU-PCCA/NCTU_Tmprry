#include<bits/stdc++.h>
using namespace std;

const int MAXD = 205;
const int MAXS = 12005;
const int MAXP = 85;
int D, S, P;
int limit[MAXD];
int weight[MAXD][5];
int student[MAXS][5];
int prefer[MAXS][MAXP];

bool input() {
	scanf("%d", &D);
	if ( D == 0 ) return false;
	scanf("%d %d", &S, &P);
	for ( int i = 0 ; i < D; i++ ) {
		
		scanf("%d", &limit[i]);
		for ( int j = 0 ; j < 5 ; j++ ) {
			scanf("%d", &weight[i][j]);
		}
	}
	for ( int i = 0 ; i < S ; i++ ) {
		for ( int j = 0 ; j < 5 ; j++ ) {
			scanf("%d", &student[i][j]);
		}
	}
	for ( int i = 0 ; i < S ; i++ ) {
		for ( int j = 0 ; j < P ; j++ ) {
			scanf("%d", &prefer[i][j]);	
			prefer[i][j]--;
		}
	}
	return true;
}

struct admission {
	int department_id;
	int student_id;
	int student_next;
	int s[5];
	bool operator<(const admission&b) const {
		int tot = 0, totb = 0;
		for ( int i = 0 ; i < 5 ; i++ ) {
			tot += s[i] * weight[department_id][i];
			totb += b.s[i] * weight[department_id][i];
		}
		return tot < totb;
	}
	bool operator==(const admission&b) const {
		int tot = 0, totb = 0;
		for ( int i = 0 ; i < 5 ; i++ ) {
			tot += s[i] * weight[department_id][i];
			totb += b.s[i] * weight[department_id][i];
		}
		return tot == totb;
	}
};
multiset<admission> ads[MAXD];
typedef pair<int, int> pii;

vector<admission> get_bad(int department ) {
	vector<admission> res;
	admission tp = *ads[department].begin();
	res.push_back(tp);
	ads[department].erase(ads[department].begin());
	while ( !ads[department].empty() && *ads[department].begin() == tp ) {
		res.push_back(*ads[department].begin());
		ads[department].erase(ads[department].begin());
	}
	return res;
}

void solve() {
	for ( int i = 0 ; i < D ; i++ ) {
		ads[i].clear();
	}
	queue<pii> que;
	for ( int i = 0 ; i < S ; i++ ) {
		que.push({i,0});
	}
	while ( !que.empty() ) {
		pii the = que.front(); que.pop();
		int stu = the.first;
		int odr = the.second;
		int depart = prefer[stu][odr];
		if ( odr >= P ) continue;

		admission pending;
		pending.department_id = depart;
		pending.student_id = stu;
		pending.student_next = odr + 1;
		for ( int i = 0 ; i < 5 ; i++ ) pending.s[i] = student[stu][i];
		
		if ( ads[depart].size() < limit[depart] ) {
			ads[depart].insert(pending);
			continue;
		} // limit = 0? 
		vector<admission> bad;
		bad = get_bad(depart);
		if ( pending < bad[0] || pending == bad[0] ) {
			for (auto tt : bad) {
				ads[depart].insert(tt);
			}
			if ( bad[0] == pending ) {
				ads[depart].insert(pending);
			} else {
				que.push({stu, odr + 1});
			}
		} else {
			ads[depart].insert(pending);
			if ( ads[depart].size() >= limit[depart] ) {
				for (auto tt : bad) {
					que.push({ tt.student_id, tt.student_next });
				}
			} else {
				for (auto tt : bad) {
					ads[depart].insert(tt);
				}
			}
		}
	}
}

void print() {

	int ansa, ansb, ansc, ansd;
	ansa = ansb = ansc = ansd = 0;
	
	for ( int i = 0 ; i < D; i++ ) {
		ansa += ads[i].size();
		for ( auto it : ads[i] ) {
			if ( it.student_next == 1 ) {
				ansb++;
			}
		}
		if ( ads[i].size() > limit[i] ) ansc++;
		if ( ads[i].size() < limit[i] ) ansd++;
	}

	printf("%d %d %d %d\n", ansa, ansb, ansc, ansd);
}


int main() {
	while ( input() ) {
		solve();
		print();
	}
}
