#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "stdlib.h"

void *func(void *arg){
    //detect current the pthread
    pthread_t tid = pthread_self();
    printf("Thread %d, Inside the threads , TID: %lu\n",*(int*)arg,tid);

    //exit the current thread
    pthread_exit(NULL);
}

void fun(){
    pthread_t thread[3];
    int thread_args[3];
    printf("Process ID:%d\n",getpid());
    for(int i=0;i<3;i++){
        thread_args[i] = i+1;
        pthread_create(&thread[i],NULL,&func,&thread_args[i]);
        //create the new thread total : 3 threads in the system
        printf("Thread %d TID: %lu\n",thread_args[i],thread[i]);
    }

    for(int j = 0;j<3;j++){
        pthread_join(thread[j],NULL);
    }
    printf("This line will be print after the thread is created and initialize\n");

}
int main(void){
    fun();

    return 0;
}