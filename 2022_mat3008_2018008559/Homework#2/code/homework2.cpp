#include <cmath>
#include "nr.h"
using namespace std;

DP NR::bessj0(const DP x)
{
	DP ax,z,xx,y,ans,ans1,ans2;

	if ((ax=fabs(x)) < 8.0) {
		y=x*x;
		ans1=57568490574.0+y*(-13362590354.0+y*(651619640.7
			+y*(-11214424.18+y*(77392.33017+y*(-184.9052456)))));
		ans2=57568490411.0+y*(1029532985.0+y*(9494680.718
			+y*(59272.64853+y*(267.8532712+y*1.0))));
		ans=ans1/ans2;
	} else {
		z=8.0/ax;
		y=z*z;
		xx=ax-0.785398164;
		ans1=1.0+y*(-0.1098628627e-2+y*(0.2734510407e-4
			+y*(-0.2073370639e-5+y*0.2093887211e-6)));
		ans2 = -0.1562499995e-1+y*(0.1430488765e-3
			+y*(-0.6911147651e-5+y*(0.7621095161e-6
			-y*0.934945152e-7)));
		ans=sqrt(0.636619772/ax)*(cos(xx)*ans1-z*sin(xx)*ans2);
	}
	return ans;
}
DP NR::rtbis(DP func(const DP), const DP x1, const DP x2, const DP xacc)
{
	const int JMAX=40;
	int j;
	DP dx,f,fmid,xmid,rtb;

	f=func(x1);
	fmid=func(x2);
	if (f*fmid >= 0.0) nrerror("Root must be bracketed for bisection in rtbis");
	rtb = f < 0.0 ? (dx=x2-x1,x1) : (dx=x1-x2,x2);
	for (j=0;j<JMAX;j++) {
		fmid=func(xmid=rtb+(dx *= 0.5));
		if (fmid <= 0.0) rtb=xmid;
		if (fabs(dx) < xacc || fmid == 0.0){
            cout << "iterate "<< j << " times  ";
            return rtb;
		}
	}
	nrerror("Too many bisections in rtbis");
	return 0.0;
}
void NR::zbrak(DP fx(const DP), const DP x1, const DP x2, const int n,
	Vec_O_DP &xb1, Vec_O_DP &xb2, int &nroot)
{
	int i;
	DP x,fp,fc,dx;

	int nb=xb1.size();
	nroot=0;
	dx=(x2-x1)/n;
	fp=fx(x=x1);
	for (i=0;i<n;i++) {
		fc=fx(x += dx);
		if (fc*fp <= 0.0) {
			xb1[nroot]=x-dx;
			xb2[nroot++]=x;
			if(nroot == nb) return;
		}
		fp=fc;
	}
}
DP NR::rtflsp(DP func(const DP), const DP x1, const DP x2, const DP xacc)
{
	const int MAXIT=30;
	int j;
	DP fl,fh,xl,xh,dx,del,f,rtf;

	fl=func(x1);
	fh=func(x2);
	if (fl*fh > 0.0) nrerror("Root must be bracketed in rtflsp");
	if (fl < 0.0) {
		xl=x1;
		xh=x2;
	} else {
		xl=x2;
		xh=x1;
		SWAP(fl,fh);
	}
	dx=xh-xl;
	for (j=0;j<MAXIT;j++) {
		rtf=xl+dx*fl/(fl-fh);
		f=func(rtf);
		if (f < 0.0) {
			del=xl-rtf;
			xl=rtf;
			fl=f;
		} else {
			del=xh-rtf;
			xh=rtf;
			fh=f;
		}
		dx=xh-xl;
		if (fabs(del) < xacc || f == 0.0){
                cout << "iterate "<< j << "  times  ";
                return rtf;
		}
	}
	nrerror("Maximum number of iterations exceeded in rtflsp");
	return 0.0;
}

DP NR::rtsec(DP func(const DP), const DP x1, const DP x2, const DP xacc)
{
	const int MAXIT=30;
	int j;
	DP fl,f,dx,xl,rts;

	fl=func(x1);
	f=func(x2);
	if (fabs(fl) < fabs(f)) {
		rts=x1;
		xl=x2;
		SWAP(fl,f);
	} else {
		xl=x1;
		rts=x2;
	}
	for (j=0;j<MAXIT;j++) {
		dx=(xl-rts)*f/(f-fl);
		xl=rts;
		fl=f;
		rts += dx;
		f=func(rts);
		if (fabs(dx) < xacc || f == 0.0){
            cout << "iterate "<< j << "  times  ";
            return rts;
		}
	}
	nrerror("Maximum number of iterations exceeded in rtsec");
	return 0.0;
}
DP NR::rtnewt(void funcd(const DP, DP &, DP &), const DP x1, const DP x2,
	const DP xacc)
{
	const int JMAX=20;
	int j;
	DP df,dx,f,rtn;

	rtn=0.5*(x1+x2);
	for (j=0;j<JMAX;j++) {
		funcd(rtn,f,df);
		dx=f/df;
		rtn -= dx;
		if ((x1-rtn)*(rtn-x2) < 0.0)
			nrerror("Jumped out of brackets in rtnewt");
		if (fabs(dx) < xacc){
            cout << "iterate "<< j << "  times  ";
            return rtn;
		}
	}
	nrerror("Maximum number of iterations exceeded in rtnewt");
	return 0.0;
}
DP NR::bessj1(const DP x)
{
	DP ax,z,xx,y,ans,ans1,ans2;

	if ((ax=fabs(x)) < 8.0) {
		y=x*x;
		ans1=x*(72362614232.0+y*(-7895059235.0+y*(242396853.1
			+y*(-2972611.439+y*(15704.48260+y*(-30.16036606))))));
		ans2=144725228442.0+y*(2300535178.0+y*(18583304.74
			+y*(99447.43394+y*(376.9991397+y*1.0))));
		ans=ans1/ans2;
	} else {
		z=8.0/ax;
		y=z*z;
		xx=ax-2.356194491;
		ans1=1.0+y*(0.183105e-2+y*(-0.3516396496e-4
			+y*(0.2457520174e-5+y*(-0.240337019e-6))));
		ans2=0.04687499995+y*(-0.2002690873e-3
			+y*(0.8449199096e-5+y*(-0.88228987e-6
			+y*0.105787412e-6)));
		ans=sqrt(0.636619772/ax)*(cos(xx)*ans1-z*sin(xx)*ans2);
		if (x < 0.0) ans = -ans;
	}
	return ans;
}
DP NR::rtsafe(void funcd(const DP, DP &, DP &), const DP x1, const DP x2,
	const DP xacc)
{
	const int MAXIT=100;
	int j;
	DP df,dx,dxold,f,fh,fl,temp,xh,xl,rts;

	funcd(x1,fl,df);
	funcd(x2,fh,df);
	if ((fl > 0.0 && fh > 0.0) || (fl < 0.0 && fh < 0.0))
		nrerror("Root must be bracketed in rtsafe");
	if (fl == 0.0) return x1;
	if (fh == 0.0) return x2;
	if (fl < 0.0) {
		xl=x1;
		xh=x2;
	} else {
		xh=x1;
		xl=x2;
	}
	rts=0.5*(x1+x2);
	dxold=fabs(x2-x1);
	dx=dxold;
	funcd(rts,f,df);
	for (j=0;j<MAXIT;j++) {
		if ((((rts-xh)*df-f)*((rts-xl)*df-f) > 0.0)
			|| (fabs(2.0*f) > fabs(dxold*df))) {
			dxold=dx;
			dx=0.5*(xh-xl);
			rts=xl+dx;
			if (xl == rts){
                cout << "iterate "<< j << "  times  ";
                return rts;
			}
		} else {
			dxold=dx;
			dx=f/df;
			temp=rts;
			rts -= dx;
			if (temp == rts){
                cout << "iterate "<< j << "  times  ";
                return rts;
			}
		}
		if (fabs(dx) < xacc){
            cout << "iterate "<< j << "  times  ";
            return rts;
		}
		funcd(rts,f,df);
		if (f < 0.0)
			xl=rts;
		else
			xh=rts;
	}
	nrerror("Maximum number of iterations exceeded in rtsafe");
	return 0.0;
}
void myfunction(const DP x, DP &f, DP &df){
    f = NR::bessj0(x);
    df = -NR::bessj1(x);
}

double muller(DP f(const DP),double p0,double p2,double TOL){
    double tmp = 999;
    double p3,a,b,c;
    double p1 = (p0+p2)/2;
    int cnt = 0;
    while(true){
        c = f(p2);
        b = ((p0-p2)*(p0-p2)*(f(p1)-f(p2))-(p1-p2)*(p1-p2)*(f(p0)-f(p2)))/((p0-p2)*(p1-p2)*(p0-p1));
        a = ((p1-p2)*(f(p0)-f(p2))-(p0-p2)*(f(p1)-f(p2)))/((p0-p2)*(p1-p2)*(p0-p1));
        int sig = b > 0 ? 1 : -1;
        p3 = p2 - 2*c/(b+sig*sqrt(b*b-4*a*c));
        if(abs(f(p3) - tmp) < TOL){
            cout << "iterate "<< cnt << "  times  ";
            break;
        }
        tmp = f(p3);
        p0 = p1;
        p1 = p2;
        p2 = p3;
        cnt++;
    }
    return p3;
}
void check_at(double n,double m,double TOR){
    cout << "by bisection method       " << NR::rtbis(NR::bessj0,n,m,TOR) << "\n";
    cout << "by Linear interpolation   " << NR::rtflsp(NR::bessj0,n,m,TOR) << "\n";
    cout << "by Secant                 " << NR::rtsec(NR::bessj0,n,m,TOR) << "\n";
    cout << "by Newton-Raphson         " << NR::rtnewt(myfunction,n,m,TOR) << "\n";
    cout << "by Newton with bracketing " << NR::rtsafe(myfunction,n,m,TOR) << "\n";
    cout << "by Muller's method        " << muller(NR::bessj0,n,m,TOR) << "\n\n";
}

void my_interest(const DP x, DP &f, DP &df){
    f = sin(x) - exp(-x);
    df = cos(x) + exp(-x);
}
DP my_interest_func(const DP x){
    return sin(x) - exp(-x);
}

int main(){
    Vec_O_DP a(10),b(10);
    int n;
    NR::zbrak(NR::bessj0,1,10,100,a,b,n);
    for(int i=0; i<n; i++){
        cout << "solution at [" << a[i] << " , " << b[i] << "]\n";
        check_at(a[i],b[i],1e-6);
    }

    cout << "find a solution of sin x = e^-x for [0, 7] by Newton with bracketing\n";
    NR::zbrak(my_interest_func,0,7,100,a,b,n);
    for(int i=0; i<n; i++){
        cout << "solution at [" << a[i] << " , " << b[i] << "]\n";
        cout << "by Newton with bracketing " << NR::rtsafe(my_interest,a[i],b[i],1e-6) << "\n";
    }
}
