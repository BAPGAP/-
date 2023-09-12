#include <iostream>

using namespace std;

int Answer;
int a[100001];
int cnt[100001];
int cont[100001];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    Answer = 0;
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            cnt[i] = 0;
            cont[i] = 0;
        }
        for(int i=1; i<=n; i++){
            if(cnt[i] == 0){
                cnt[i] = i;
            }

            if(i + a[i] <= n){
                int tmp = i;
                //제일 마지막 친구 찾자
                while(tmp + a[tmp] <= n){
                    tmp = tmp + a[tmp];
                }
                if(cnt[tmp] == 0){
                    tmp = i;
                    while(tmp + a[tmp] <= n){
                        cnt[tmp + a[tmp]] = cnt[tmp];
                        tmp = tmp + a[tmp];
                    }
                }
                else{
                    int gap = cnt[tmp];
                    tmp = i;
                    while(tmp + a[tmp] <= n){
                        cnt[tmp] = gap;
                        tmp = tmp + a[tmp];
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            cont[cnt[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(cont[i] != 0) Answer++;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
