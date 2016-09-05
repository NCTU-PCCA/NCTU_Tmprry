typedef pair<int, int> pii;
pii extgcd(int a, int b){
	if(b == 0) return make_pair(1, 0);
	else{
		int p = a / b;
		pii q = extgcd(b, a % b);
		return make_pair(q.second, q.first - q.second * p);
	}
}
