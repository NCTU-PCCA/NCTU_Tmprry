typedef Point pdd;
typedef ld double;
vector<pdd> interCircle(pdd o1, double r1, pdd o2, double r2) {
	ld d2 = (o1 - o2).abs2();
	ld d = sqrt(d2);
	if (d < fabs(r1-r2)) return {};
	if (d > r1+r2) return {};
	pdd u = 0.5*(o1+o2) + ((r2*r2-r1*r1)/(2.0*d2))*(o1-o2);
	double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
	pdd v = A / (2.0*d2) * pdd(o1.S-o2.S, -o1.F+o2.F);
	return {u+v, u-v};
}

