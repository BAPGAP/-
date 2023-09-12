#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <cmath>
#include "nr.h"

using namespace std;

void NR::svbksb(Mat_I_DP &u, Vec_I_DP &w, Mat_I_DP &v, Vec_I_DP &b, Vec_O_DP &x)
{
	int jj,j,i;
	DP s;

	int m=u.nrows();
	int n=u.ncols();
	Vec_DP tmp(n);
	for (j=0;j<n;j++) {
		s=0.0;
		if (w[j] != 0.0) {
			for (i=0;i<m;i++) s += u[i][j]*b[i];
			s /= w[j];
		}
		tmp[j]=s;
	}
	for (j=0;j<n;j++) {
		s=0.0;
		for (jj=0;jj<n;jj++) s += v[j][jj]*tmp[jj];
		x[j]=s;
	}
}
DP NR::pythag(const DP a, const DP b)
{
	DP absa,absb;

	absa=fabs(a);
	absb=fabs(b);
	if (absa > absb) return absa*sqrt(1.0+SQR(absb/absa));
	else return (absb == 0.0 ? 0.0 : absb*sqrt(1.0+SQR(absa/absb)));
}
void NR::gaussj(Mat_IO_DP &a, Mat_IO_DP &b)
{
	int i,icol,irow,j,k,l,ll;
	DP big,dum,pivinv;

	int n=a.nrows();
	int m=b.ncols();
	Vec_INT indxc(n),indxr(n),ipiv(n);
	for (j=0;j<n;j++) ipiv[j]=0;
	for (i=0;i<n;i++) {
		big=0.0;
		for (j=0;j<n;j++)
			if (ipiv[j] != 1)
				for (k=0;k<n;k++) {
					if (ipiv[k] == 0) {
						if (fabs(a[j][k]) >= big) {
							big=fabs(a[j][k]);
							irow=j;
							icol=k;
						}
					}
				}
		++(ipiv[icol]);
		if (irow != icol) {
			for (l=0;l<n;l++) SWAP(a[irow][l],a[icol][l]);
			for (l=0;l<m;l++) SWAP(b[irow][l],b[icol][l]);
		}
		indxr[i]=irow;
		indxc[i]=icol;
		if (a[icol][icol] == 0.0) nrerror("gaussj: Singular Matrix");
		pivinv=1.0/a[icol][icol];
		a[icol][icol]=1.0;
		for (l=0;l<n;l++) a[icol][l] *= pivinv;
		for (l=0;l<m;l++) b[icol][l] *= pivinv;
		for (ll=0;ll<n;ll++)
			if (ll != icol) {
				dum=a[ll][icol];
				a[ll][icol]=0.0;
				for (l=0;l<n;l++) a[ll][l] -= a[icol][l]*dum;
				for (l=0;l<m;l++) b[ll][l] -= b[icol][l]*dum;
			}
	}
	for (l=n-1;l>=0;l--) {
		if (indxr[l] != indxc[l])
			for (k=0;k<n;k++)
				SWAP(a[k][indxr[l]],a[k][indxc[l]]);
	}
}
void NR::ludcmp(Mat_IO_DP &a, Vec_O_INT &indx, DP &d)
{
	const DP TINY=1.0e-20;
	int i,imax,j,k;
	DP big,dum,sum,temp;

	int n=a.nrows();
	Vec_DP vv(n);
	d=1.0;
	for (i=0;i<n;i++) {
		big=0.0;
		for (j=0;j<n;j++)
			if ((temp=fabs(a[i][j])) > big) big=temp;
		if (big == 0.0) nrerror("Singular matrix in routine ludcmp");
		vv[i]=1.0/big;
	}
	for (j=0;j<n;j++) {
		for (i=0;i<j;i++) {
			sum=a[i][j];
			for (k=0;k<i;k++) sum -= a[i][k]*a[k][j];
			a[i][j]=sum;
		}
		big=0.0;
		for (i=j;i<n;i++) {
			sum=a[i][j];
			for (k=0;k<j;k++) sum -= a[i][k]*a[k][j];
			a[i][j]=sum;
			if ((dum=vv[i]*fabs(sum)) >= big) {
				big=dum;
				imax=i;
			}
		}
		if (j != imax) {
			for (k=0;k<n;k++) {
				dum=a[imax][k];
				a[imax][k]=a[j][k];
				a[j][k]=dum;
			}
			d = -d;
			vv[imax]=vv[j];
		}
		indx[j]=imax;
		if (a[j][j] == 0.0) a[j][j]=TINY;
		if (j != n-1) {
			dum=1.0/(a[j][j]);
			for (i=j+1;i<n;i++) a[i][j] *= dum;
		}
	}
}

void NR::svdcmp(Mat_IO_DP &a, Vec_O_DP &w, Mat_O_DP &v)
{
	bool flag;
	int i,its,j,jj,k,l,nm;
	DP anorm,c,f,g,h,s,scale,x,y,z;

	int m=a.nrows();
	int n=a.ncols();
	Vec_DP rv1(n);
	g=scale=anorm=0.0;
	for (i=0;i<n;i++) {
		l=i+2;
		rv1[i]=scale*g;
		g=s=scale=0.0;
		if (i < m) {
			for (k=i;k<m;k++) scale += fabs(a[k][i]);
			if (scale != 0.0) {
				for (k=i;k<m;k++) {
					a[k][i] /= scale;
					s += a[k][i]*a[k][i];
				}
				f=a[i][i];
				g = -SIGN(sqrt(s),f);
				h=f*g-s;
				a[i][i]=f-g;
				for (j=l-1;j<n;j++) {
					for (s=0.0,k=i;k<m;k++) s += a[k][i]*a[k][j];
					f=s/h;
					for (k=i;k<m;k++) a[k][j] += f*a[k][i];
				}
				for (k=i;k<m;k++) a[k][i] *= scale;
			}
		}
		w[i]=scale *g;
		g=s=scale=0.0;
		if (i+1 <= m && i != n) {
			for (k=l-1;k<n;k++) scale += fabs(a[i][k]);
			if (scale != 0.0) {
				for (k=l-1;k<n;k++) {
					a[i][k] /= scale;
					s += a[i][k]*a[i][k];
				}
				f=a[i][l-1];
				g = -SIGN(sqrt(s),f);
				h=f*g-s;
				a[i][l-1]=f-g;
				for (k=l-1;k<n;k++) rv1[k]=a[i][k]/h;
				for (j=l-1;j<m;j++) {
					for (s=0.0,k=l-1;k<n;k++) s += a[j][k]*a[i][k];
					for (k=l-1;k<n;k++) a[j][k] += s*rv1[k];
				}
				for (k=l-1;k<n;k++) a[i][k] *= scale;
			}
		}
		anorm=MAX(anorm,(fabs(w[i])+fabs(rv1[i])));
	}
	for (i=n-1;i>=0;i--) {
		if (i < n-1) {
			if (g != 0.0) {
				for (j=l;j<n;j++)
					v[j][i]=(a[i][j]/a[i][l])/g;
				for (j=l;j<n;j++) {
					for (s=0.0,k=l;k<n;k++) s += a[i][k]*v[k][j];
					for (k=l;k<n;k++) v[k][j] += s*v[k][i];
				}
			}
			for (j=l;j<n;j++) v[i][j]=v[j][i]=0.0;
		}
		v[i][i]=1.0;
		g=rv1[i];
		l=i;
	}
	for (i=MIN(m,n)-1;i>=0;i--) {
		l=i+1;
		g=w[i];
		for (j=l;j<n;j++) a[i][j]=0.0;
		if (g != 0.0) {
			g=1.0/g;
			for (j=l;j<n;j++) {
				for (s=0.0,k=l;k<m;k++) s += a[k][i]*a[k][j];
				f=(s/a[i][i])*g;
				for (k=i;k<m;k++) a[k][j] += f*a[k][i];
			}
			for (j=i;j<m;j++) a[j][i] *= g;
		} else for (j=i;j<m;j++) a[j][i]=0.0;
		++a[i][i];
	}
	for (k=n-1;k>=0;k--) {
		for (its=0;its<30;its++) {
			flag=true;
			for (l=k;l>=0;l--) {
				nm=l-1;
				if (fabs(rv1[l])+anorm == anorm) {
					flag=false;
					break;
				}
				if (fabs(w[nm])+anorm == anorm) break;
			}
			if (flag) {
				c=0.0;
				s=1.0;
				for (i=l-1;i<k+1;i++) {
					f=s*rv1[i];
					rv1[i]=c*rv1[i];
					if (fabs(f)+anorm == anorm) break;
					g=w[i];
					h=pythag(f,g);
					w[i]=h;
					h=1.0/h;
					c=g*h;
					s = -f*h;
					for (j=0;j<m;j++) {
						y=a[j][nm];
						z=a[j][i];
						a[j][nm]=y*c+z*s;
						a[j][i]=z*c-y*s;
					}
				}
			}
			z=w[k];
			if (l == k) {
				if (z < 0.0) {
					w[k] = -z;
					for (j=0;j<n;j++) v[j][k] = -v[j][k];
				}
				break;
			}
			if (its == 29) nrerror("no convergence in 30 svdcmp iterations");
			x=w[l];
			nm=k-1;
			y=w[nm];
			g=rv1[nm];
			h=rv1[k];
			f=((y-z)*(y+z)+(g-h)*(g+h))/(2.0*h*y);
			g=pythag(f,1.0);
			f=((x-z)*(x+z)+h*((y/(f+SIGN(g,f)))-h))/x;
			c=s=1.0;
			for (j=l;j<=nm;j++) {
				i=j+1;
				g=rv1[i];
				y=w[i];
				h=s*g;
				g=c*g;
				z=pythag(f,h);
				rv1[j]=z;
				c=f/z;
				s=h/z;
				f=x*c+g*s;
				g=g*c-x*s;
				h=y*s;
				y *= c;
				for (jj=0;jj<n;jj++) {
					x=v[jj][j];
					z=v[jj][i];
					v[jj][j]=x*c+z*s;
					v[jj][i]=z*c-x*s;
				}
				z=pythag(f,h);
				w[j]=z;
				if (z) {
					z=1.0/z;
					c=f*z;
					s=h*z;
				}
				f=c*g+s*y;
				x=c*y-s*g;
				for (jj=0;jj<m;jj++) {
					y=a[jj][j];
					z=a[jj][i];
					a[jj][j]=y*c+z*s;
					a[jj][i]=z*c-y*s;
				}
			}
			rv1[l]=0.0;
			rv1[k]=f;
			w[k]=x;
		}
	}
}
void NR::lubksb(Mat_I_DP &a, Vec_I_INT &indx, Vec_IO_DP &b)
{
	int i,ii=0,ip,j;
	DP sum;

	int n=a.nrows();
	for (i=0;i<n;i++) {
		ip=indx[i];
		sum=b[ip];
		b[ip]=b[i];
		if (ii != 0)
			for (j=ii-1;j<i;j++) sum -= a[i][j]*b[j];
		else if (sum != 0.0)
			ii=i+1;
		b[i]=sum;
	}
	for (i=n-1;i>=0;i--) {
		sum=b[i];
		for (j=i+1;j<n;j++) sum -= a[i][j]*b[j];
		b[i]=sum/a[i][i];
	}
}

void NR::mprove(Mat_I_DP &a, Mat_I_DP &alud, Vec_I_INT &indx, Vec_I_DP &b,Vec_IO_DP &x)
{
	int i,j;

	int n=x.size();
	Vec_DP r(n);
	for (i=0;i<n;i++) {
		long double sdp = -b[i];
		for (j=0;j<n;j++)
			sdp += (long double) a[i][j]*(long double) x[j];
		r[i]=sdp;
	}
	NR::lubksb(alud,indx,r);
	for (i=0;i<n;i++) x[i] -= r[i];
}

int main()
{
    int n = 5;
    const DP A[n*n]={2,-4,-5,5,0,-1,1,2,0,4,-1,6,0,3,2,0,1,3,7,5,5,0,8,7,-2};
    const DP B[n] = {-5,2,0,4,-1};

    Mat_DP matrix_A1(A,n,n),matrix_B1(B,n,1);

    NR::gaussj(matrix_A1,matrix_B1);
    cout << "solution by gauss-jordan elimination\n";
    for(int i=0; i<n; i++){
        cout << matrix_B1[i][0] << " ";
    }
    cout << "\n\n";

    cout << "inverse matrix of A\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix_A1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    Mat_DP matrix_AA2(A,n,n),matrix_A2(n,n);
    Vec_DP matrix_x2(n),matrix_BB2(B,n);
    Vec_INT indx2(n);
    DP d2;
    for(int i=0;i<n; i++){
        matrix_x2[i] = matrix_BB2[i];
        for(int j=0; j<n; j++){
            matrix_A2[i][j] = matrix_AA2[i][j];
        }
    }

    NR::ludcmp(matrix_A2, indx2,d2);
    cout << "after LU decomposition\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix_A2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "d value :  " << d2 << "\n\n";

    NR::lubksb(matrix_A2, indx2,matrix_x2);

    cout << "solution by LU decomposition\n";
    for(int i=0; i<n; i++){
        cout << matrix_x2[i] << " ";
    }
    cout << "\n\n";

    NR::mprove(matrix_AA2,matrix_A2,indx2,matrix_BB2,matrix_x2);
    cout << "after iterative improvement\n";
    for(int i=0; i<n; i++){
        cout << matrix_x2[i] << " ";
    }
    cout << "\n\n";

    Mat_DP matrix_AA3(A,n,n),matrix_A3(n,n),matrix_V(n,n);
    Vec_DP matrix_W(n),matrix_B3(B,n),matrix_x3(n);
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            matrix_A3[i][j] = matrix_AA3[i][j];
        }
    }

    NR::svdcmp(matrix_A3, matrix_W, matrix_V);
    NR::svbksb(matrix_A3, matrix_W, matrix_V, matrix_B3, matrix_x3);

    cout << "solution by SVD\n";
    for(int i=0; i<n; i++){
        cout << matrix_x3[i] << " ";
    }
    cout << "\n\n";
}
