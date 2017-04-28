#include<bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(5);
	s.erase(s.begin());
	cout << *s.begin() << endl;
	while(1);
}
