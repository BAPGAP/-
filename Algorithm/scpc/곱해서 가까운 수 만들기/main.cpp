#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
//#define DEBUG

using namespace std;

int Answer; //string
vector<int> arr(1001);

int main(int argc, char** argv)
{
   int T, test_case;

   scanf("%d",&T);
   for(test_case = 0; test_case  < T; test_case++)
   {
       int N, K, tmp;
       int _max=0, _min=10000;

      Answer = -1000000;
      scanf("%d %d",&N, &K);

      for(int i=1; i<=N; i++){
            if(i == 19 ||i == 38|| i== 57|| i== 83) tmp = i+1;
            else tmp = i;
            //scanf("%d",&tmp);
            if(_max<tmp) _max = tmp;
            if(_min>tmp) _min = tmp;
            arr[tmp]++;
      }

      while(_min<=_max){
            if(_min==_max){
                if(arr[_min]>1)
                    if(abs(_min*_min-K)<=abs(Answer-K) && _min*_min > Answer){
                        Answer = _min*_min;
                    }
                break;
            }
            if(_min*_max==K){
                Answer = K;
                break;
            }
            else if(_min*_max>K){
                if(_min*_max-K<=abs(Answer-K)) {
                    Answer=_min*_max;
                }
                _max--;
                while(arr[_max]==0){
                    _max--;
                }
            }
            else {
                if(K-_min*_max<abs(Answer-K)) {
                    Answer=_min*_max;
                }
                _min++;
                while(arr[_min]==0){
                    _min++;
                }
            }
      }


      printf("Case #%d\n",test_case+1);
      printf("%d\n",Answer);
   }

   return 0;
}
