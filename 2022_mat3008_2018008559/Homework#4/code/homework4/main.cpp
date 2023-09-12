#include <iostream>
#include <cmath>
#include "nr.h"

using namespace std;

DP NR::ran1(int &idum)
{
	const int IA=16807,IM=2147483647,IQ=127773,IR=2836,NTAB=32;
	const int NDIV=(1+(IM-1)/NTAB);
	const DP EPS=3.0e-16,AM=1.0/IM,RNMX=(1.0-EPS);
	static int iy=0;
	static Vec_INT iv(NTAB);
	int j,k;
	DP temp;

	if (idum <= 0 || !iy) {
		if (-idum < 1) idum=1;
		else idum = -idum;
		for (j=NTAB+7;j>=0;j--) {
			k=idum/IQ;
			idum=IA*(idum-k*IQ)-IR*k;
			if (idum < 0) idum += IM;
			if (j < NTAB) iv[j] = idum;
		}
		iy=iv[0];
	}
	k=idum/IQ;
	idum=IA*(idum-k*IQ)-IR*k;
	if (idum < 0) idum += IM;
	j=iy/NDIV;
	iy=iv[j];
	iv[j] = idum;
	if ((temp=AM*iy) > RNMX) return RNMX;
	else return temp;
}
DP NR::gasdev(int &idum)
{
	static int iset=0;
	static DP gset;
	DP fac,rsq,v1,v2;

	if (idum < 0) iset=0;
	if (iset == 0) {
		do {
			v1=2.0*ran1(idum)-1.0;
			v2=2.0*ran1(idum)-1.0;
			rsq=v1*v1+v2*v2;
		} while (rsq >= 1.0 || rsq == 0.0);
		fac=sqrt(-2.0*log(rsq)/rsq);
		gset=v1*fac;
		iset=1;
		return v2*fac;
	} else {
		iset=0;
		return gset;
	}
}
int main()
{
    int cnt[101] = {0};
    int a = -3, b = 2;
    int x;

    for(int i=0; i<100000; i++){
        double rdv = NR::ran1(x);
        double rdv_u = rdv*(b-a) + a;
        //cout << rdv_u << "\n";
        cnt[(int((rdv_u + 3)*100))/5]++;
    }
    for(int i=0; i<100; i++){
        cout << cnt[i] << "\n";
    }

    int cnt1[101] = {0};
    int L = 0;
    int R = 0;
    double m = 0.5, s = 1.5;
    for(int i=0; i<100000; i++){
        double rdv = NR::gasdev(x);
        double rdv_n = rdv*s + m;
        //cout << rdv_n << "\n";
        int idx = (int((rdv_n+6-m)*100))/12;
        if(idx < 0) L++;
        else if(idx > 99) R++;
        else cnt1[idx]++;
    }
    cout << L << "\n";
    for(int i=0; i<100; i++){
        cout << cnt1[i] << "\n";
    }
    cout << R << "\n";
}
