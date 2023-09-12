#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define DEVIDE 1000000007

using namespace std;

long long Answer;
long long a[1000001], b[1000001];

long long _cycle(long long n, long long k){
    if(n==3) return (((k*(k-1))%DEVIDE)*(k-2))%DEVIDE;
    long long tmp = (n-2)/2;
    a[1] = k-1;
    a[2] = ((k-1)*(k-2))%DEVIDE;
    b[1] = k-2;
    b[2] = ((k-2)*(k-2))%DEVIDE+(k-1);

    for(long long i=3; i<=n-2-tmp; i++){
        long long tmp1 = (i-1)/2;
        a[i] = (a[tmp1]*a[i-1-tmp1])%DEVIDE+((((k-1)*b[tmp1])%DEVIDE)*b[i-1-tmp1])%DEVIDE;
        b[i] = (a[tmp1]*b[i-1-tmp1])%DEVIDE+(b[tmp1]*a[i-1-tmp1])%DEVIDE+((((k-2)*b[tmp1])%DEVIDE)*b[i-1-tmp1])%DEVIDE;
    }

    return (((k*a[tmp])%DEVIDE)*a[n-2-tmp])%DEVIDE+(((((k*(k-1))%DEVIDE)*b[tmp])%DEVIDE)*b[n-2-tmp])%DEVIDE;
}

int main(int argc, char** argv)
{
   long long T, test_case;
   long long N, K, tmp;

   long long N_line, N_cycle;

   freopen("sample_input.txt", "r", stdin);

   cin >> T;
   for(test_case = 0; test_case  < T; test_case++)
   {
      cin >> N >> K;
      N_line = 0; N_cycle = 0;

      vector<long long> _line_send(N+1);
      vector<bool> _visited(N+1);
      _visited[0] = true;
      Answer = 1;

      for(long long i=1; i<=N; i++){
            cin >> tmp;
         if(i != _line_send[tmp] && i != tmp && tmp > 0 && tmp <= N ){
                _line_send[i]=tmp;
                N_line++;
         }
      }

        vector<long long> _a;

      for(long long i=1; i<=N; i++){
            if(_visited[i]) continue;
            tmp = i;
            while(!_visited[tmp]){
                _visited[tmp] = true;
                _a.push_back(tmp);
                tmp = _line_send[tmp];
            }
            long long n = static_cast<long long>(_a.end() - find(_a.begin(),_a.end(),tmp));
            if (n != 0) {
                N_cycle += n;
                Answer = (Answer*_cycle(n,K))%DEVIDE;
            }
            _a.clear();
        }

        N_line -= N_cycle;

        for(long long i=0; i<N-N_line-N_cycle; i++){
            Answer = (Answer * K) % DEVIDE;
        }

        for(long long i=0; i<N_line; i++){
            Answer = (Answer * (K-1)) % DEVIDE;
        }

      cout << "Case #" << test_case+1 << endl;
      cout << Answer << endl;

   }

   return 0;
}
