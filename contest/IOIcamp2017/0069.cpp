#include <bits/stdc++.h>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int limit;
int dp[505][505];
int edd(string &user, string &problem) {
  int s = SZ(user), t = SZ(problem);
  if(abs(s-t) > limit) return limit + 1;
  for (int i=0; i<505; i++)dp[i][0]=dp[0][i]=i;
  for(int i=0;i<s;i++)
    for(int j=0;j<t;j++) {
      dp[i+1][j+1] = dp[i][j] + !(user[i] == problem[j]);
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + 1);
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + 1);
    }
  return dp[s][t];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    string user_code = "", problem_code = "";
    cin >> user_code >> problem_code;
    cin >> limit;
    int dis = edd(user_code, problem_code);
    if(dis > limit)
      printf("WA: Edit distance limit exceeded ( %d ).\n", limit);
    else
      printf("AC: Edit distance: %d\n", dis);
  }
  return 0;
}
