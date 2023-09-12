#include <iostream>
#include <cmath>

using namespace std;

long double Answer;
long double PI = 3.141592653589793238462643383279;



int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    long double r,H;
        int s,e;
        cin >> r >> s >> e;

        int n;
        cin >> n;

        int L,R;
        Answer = 0;
        int start = s;

        for(int i=0; i<n; i++){
            cin >> L >> R >> H;

            if(H >= r) Answer += R - start + 2 * H - 4 * r + r * PI;
            else{
                long double angle = acos((r - H)/r);
                Answer += 2 * (r - tan(angle) * (r - H)) + 2 * r * angle + R - start - 2 * r;
            }
            start = R;
        }

		Answer += e - start;
        cout.precision(16);
		cout << "Case #" << test_case+1 << "\n" << Answer << "\n";
	}

	return 0;
}
