#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
//#define DEBUG

using namespace std;

int Answer; //string
vector<int> arr(1001);
#ifdef DEBUG
int MAX, MIN;
#endif // DEBUG

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
      //arr.assign(1001,0);

      for(int i=0; i<N; i++){
            scanf("%d",&tmp);
            if(_max<tmp) _max = tmp;
            if(_min>tmp) _min = tmp;
            arr[tmp]++;
      }
        #ifdef DEBUG
      for(int i=_min; i<=_max; i++){
            if(arr[i])
                printf("<%d,%d>\n",i,arr[i]);
      }
      #endif

      while(_min<=_max){
            #ifdef DEBUG
            printf("<%d,%d> : %d\n",_min,_max,_min*_max);
            #endif
            if(_min==_max){
                if(arr[_min]>1)
                    if(abs(_min*_min-K)<=abs(Answer-K) && _min*_min > Answer){
                        Answer = _min*_min;
                        #ifdef DEBUG
                        MAX=MIN=_min;
                        #endif // DEBUG
                    }
                break;
            }
            if(_min*_max==K){
                Answer = K;
                #ifdef DEBUG
                MAX=_max; MIN=_min;
                #endif // DEBUG
                break;
            }
            else if(_min*_max>K){
                if(_min*_max-K<=abs(Answer-K)) {
                    Answer=_min*_max;
                    #ifdef DEBUG
                    MAX=_max; MIN=_min;
                    #endif // DEBUG
                }
                _max--;
                while(arr[_max]==0){
                    _max--;
                }
            }
            else {
                if(K-_min*_max<abs(Answer-K)) {
                    #ifdef DEBUG
                    MAX=_max; MIN=_min;
                    #endif // DEBUG
                    Answer=_min*_max;
                }
                _min++;
                while(arr[_min]==0){
                    _min++;
                }
            }
      }


      printf("Case #%d\n",test_case+1);
      #ifdef DEBUG
        printf("<%d,%d> : ",MIN,MAX);
        #endif // DEBUG
      printf("%d\n",Answer);
      #ifdef DEBUG
      printf("\n");
      #endif // DEBUG
   }

   return 0;
}
