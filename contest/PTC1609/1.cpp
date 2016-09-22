#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

int oder_id = 0;

struct Paragraph {
  vector<char> str;
};

struct Reference {
  vector<char> str;
  int order;
  bool operator<(const Reference & b ) const {
    return order < b.order;
  }
};

struct Oder {
  int number;
  int appear;
};

set<int> stt;
vector<Paragraph> par;
vector<Reference> refff;
vector<Oder> rfid;

int mp[50000] = {0};

int generate_order(vector<char> str, int given = 0) {
  int len = str.size(), num = 0;
  for ( int i = 0; i < len;  ) {
    if ( str[i] == '[' ) {
      num = 0;
      i++;
      while ( str[i] <= '9' && str[i] >= '0' ) {
        num = num * 10 + str[i] - '0';
        i++;
      }
      if ( given ) {
        return num;
      }
      if ( !stt.count(num) && !given) {
        rfid.push_back((Oder) {num, oder_id++});
        stt.insert(num);
      }
    } else {
      i++;
    }
  }
  return num;
}


void output() {

  for (int i = 0; i < par.size(); i++ ) {
    int sz = par[i].str.size();
    int num = 0;
    for (int j = 0 ; j < sz; ) {

        cout << par[i].str[j];

      if ( par[i].str[j] == '[' ) {
        num = 0;
        j++;
        while ( par[i].str[j] >= '0' && par[i].str[j] <= '9' ) {
          num = num * 10 + par[i].str[j] - '0';
          j++;
        }
        cout << mp[num];
      } else {
        j++;
      }
    }

    puts("");
  }

  for (int i = 0; i < refff.size(); i++ ) {
    int sz = refff[i].str.size();
    int num = 0;
    for (int j = 0 ; j < sz; ) {

        cout << refff[i].str[j];

      if ( refff[i].str[j] == '[' ) {
        num = 0;
        j++;
        while ( refff[i].str[j] >= '0' && refff[i].str[j] <= '9' ) {
          num = num * 10 + refff[i].str[j] - '0';
          j++;
        }
        cout << mp[num];
      } else {
        j++;
      }
    }

    if ( i != refff.size() - 1 ) puts("");
  }

}

vector<char> ma_vec(vector<char> ori, string s) {
  int sz = s.length();
  for ( int i = 0 ; i < sz ; i++ ) {
    ori.push_back(s[i]);
  }
  return ori;
}

int main() {
  string s;

  //freopen("input.txt", "r", stdin);

  vector<char> vstr;
  bool is_ref = 0;
  while ( getline(cin, s) ) {

    if ( s == "" ) {
      if ( is_ref ) {
        refff.push_back((Reference) {vstr, 0});
      } else {
        par.push_back((Paragraph) {vstr});
      }
      vstr.clear();
      is_ref = 0;
    } else if ( s[0] == '[' ) {
      is_ref = 1;
      vstr = ma_vec(vstr, s);
      vstr.push_back('\n');
    } else {
      vstr = ma_vec(vstr, s);
      vstr.push_back('\n');
    }
  }
  if ( vstr.size() ) {
    if ( is_ref ) {
      refff.push_back((Reference) {vstr, 0});
    } else {
      par.push_back((Paragraph) {vstr});

    }
    vstr.clear();
    is_ref = 0;
  }
  for ( int i = 0; i < par.size() ; i++ ) {
    generate_order(par[i].str, 0);
  }

  for ( int i = 0 ; i < rfid.size() ; i++ ) {
    mp[rfid[i].number] = i + 1;
    //printf("(%d) -> %d\n", rfid[i].number ,i+1);
  }

  for ( int i = 0 ; i < refff.size() ; i++ ) {
    refff[i].order = mp[generate_order(refff[i].str, 1)];
  }


  sort(refff.begin(), refff.end());

  output();



  return 0;
}
