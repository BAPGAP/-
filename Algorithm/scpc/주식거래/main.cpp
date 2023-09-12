#include <cstdio>

int Answer;
int a[200001];
int status; // 1 올라가는 중 / -1 내려가는 중
int pre_status;

int main(int argc, char** argv)
{
	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n;
	    scanf("%d",&n);
	    for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
	    }
	    status = -1; //일단 내려가는 중이라 치자
	    Answer = 0;

	    for(int i=1; i<n; i++){
            pre_status = status;
            if(a[i-1] < a[i]){
                status = 1;
                if(status != pre_status) Answer += 2;
            }
            else if(a[i-1] > a[i]) status = -1;
	    }

	    printf("Case #%d\n%d\n",test_case+1,Answer);
	}

	return 0;
}
