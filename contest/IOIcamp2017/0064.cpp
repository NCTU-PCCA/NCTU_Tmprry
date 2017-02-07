#include <bits/stdc++.h>
using namespace std;
char s[200];
int main() {
  int T;
  scanf("%d\n",&T);
  while(T--) {
    fgets(s, 200, stdin);
    int n = strlen(s);
    for(int i=0;i<n;i++)
      if(s[i] <= 'z' && s[i] >= 'a')
        s[i] = (s[i]-'a'+13)%26+'a';
      else if(s[i] <= 'Z' && s[i] >= 'A')
        s[i] = (s[i]-'A'+13)%26+'A';
    printf("%s",s);
  }
  return 0;
}
