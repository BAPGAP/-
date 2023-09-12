#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int a[200001];

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        long long k,n;
        cin >> n >> k;

        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a,a+n);

        int pos1 = 0, pos2 = 0;
        for(int i=1; i<n; i++){
            if(a[i] - a[pos1] > k){
                pos2 = i;
                break;
            }
        }
        if(pos2 == 0){
            cout << "Case #" << test_case+1 << "\n" << n << endl;
            continue;
        }

        Answer = pos2 - pos1;

        for(int i=1; i<n; i++){
            pos1 = i;
            while(pos2 < n){
                if(a[pos2] - a[pos1] > k) break;
                pos2++;
            }
            Answer = max(Answer,pos2 - pos1);
        }

		cout << "Case #" << test_case+1 << "\n" << Answer << endl;
	}

	return 0;
}
