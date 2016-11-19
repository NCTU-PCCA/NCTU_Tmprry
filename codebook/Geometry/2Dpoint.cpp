typedef double T;
struct Point {
	T x,y;
	Point (T _x=0, T _y=0):x(_x),y(_y){}

	bool operator < (const Point &b)const{
		return atan2(y,x) < atan2(b.y,b.x);
	}
	bool operator == (const Point &b)const{
		return atan2(y,x) == atan2(b.y,b.x);
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
	T abs2() { return x*x+y*y; }
	T abs() { return sqrt( abs2() ); }
};
typedef Point pdd;
inline double abs2(pdd a){
	return a.abs2();
}
