#include "circumcentre.cpp"
pair<pdd,double> SmallestCircle(int n, pdd _p[]){
	static const int MAXN = 1000006;
	static pdd p[MAXN];
	memcpy(p,_p,sizeof(pdd)*n);
	random_shuffle(p,p+n);
	
	double r2=0;
	pdd cen;
	for (int i=0; i<n; i++){
		if ( (cen-p[i]).abs2() <=r2)continue;
		cen = p[i], r2=0;
		for (int j=0; j<i; j++){
			if ( (cen-p[j]).abs2()<=r2 )continue;
			cen = (p[i]+p[j])*0.5;
			r2 = (cen-p[i]).abs2();
			for (int k=0; k<j; k++){
				if ( (cen-p[k]).abs2()<=r2 )continue;
				cen = circumcentre(p[i],p[j],p[k]);
				r2 = (cen-p[k]).abs2();
			}
		}
	}

	return {cen,r2};
}
// auto res = SmallestCircle(,);
