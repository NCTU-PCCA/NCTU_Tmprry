#include "2Dpoint.cpp"

pdd circumcentre(pdd &p0, pdd &p1, pdd &p2){
	pdd a = p1-p0;
	pdd b = p2-p0;
	double c1 = a.abs2()*0.5;
	double c2 = b.abs2()*0.5;
	double d = a % b;
	double x = p0.x + ( c1*b.y - c2*a.y ) / d;
	double y = p0.y + ( c2*a.x - c1*b.x ) / d;
	return pdd(x,y);
}
