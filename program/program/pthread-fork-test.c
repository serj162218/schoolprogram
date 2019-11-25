#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
void *createfork(void *data){
    printf("I'm %lu !",pthread_self());
    pthread_exit(NULL);
}
int main(int argc,char **argv){
    if(fork()==0){
        pthread_t thread1,thread2; 
        pthread_create(&thread1,NULL,createfork,NULL);
        pthread_create(&thread2,NULL,createfork,NULL);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }else{
        pthread_t thread1,thread3;
        pthread_create(&thread1,NULL,createfork,NULL);
        pthread_create(&thread3,NULL,createfork,NULL);
        pthread_join(thread1, NULL);
        pthread_join(thread3, NULL);
    }
}