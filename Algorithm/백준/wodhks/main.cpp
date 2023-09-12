#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define thread_num 1000000
int value = 0;

void *add(){
	value++;
	pthread_exit(0);
}

void *sub(){
	value--;
	pthread_exit(0);
}

int main()
{
	int i;
	int thr_id;
	pthread_t id[thread_num];
	pthread_t id2[thread_num];
	for(i=0;i<thread_num;i++){
		thr_id=pthread_create(&id[i],NULL,add,NULL);
		if(thr_id !=0){
			printf("ERROR: in thread creation\n");
			return(0);
		}

		thr_id=pthread_create(&id2[i],NULL,sub,NULL);
		if(thr_id != 0){
			printf("ERROR: in thread creation2\n");
			return(0);
		}
	}

	for(i=0;i<thread_num;i++){
		if(pthread_join(id[i],NULL)){
			printf("ERROR: in thread join\n");
			return(0);
		}
		if(pthread_join(id2[i],NULL)){
			printf("ERROR: in thread join\n");
			return(0);
		}
	}
	printf("end value :: %d\n",value);
	return(0);

}
