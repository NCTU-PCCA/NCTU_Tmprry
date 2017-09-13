typedef double T;
struct Point {
	T x,y;
	Point (T _x=0, T _y=0):x(_x),y(_y){}

	bool operator < (const Point &b)const{
		//return tie(x,y) < tie(b.x,b.y);
		//return atan2(y,x) < atan2(b.y,b.x);
		assert(0 && "choose compare");
	}
	bool operator == (const Point &b)const{
		//return tie(x,y) == tie(b.x,b.y);
		//return atan2(y,x) == atan2(b.y,b.x);
		assert(0 && "choose compare");
	}
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	T operator * (const Point &b)const{
		return x*b.x + y*b.y;
	}
	T operator % (const Point &b)const{
		return x*b.y - y*b.x;
	}
	Point operator * (const T &d)const{
		return Point(d*x,d*y);
	}
	double abs2() { return x*x+y*y; }
	double abs() { return sqrt( abs2() ); }
};
typedef Point pdd;
double abs2(pdd a){
	return a.abs2();
}
