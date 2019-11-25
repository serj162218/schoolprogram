//message-client by using thread, please use gcc -o message-client -pthread message-client.c
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
#define BUFFER_SIZE 1024
int sock;
void *theListen(void *data){
    for(;;){
            char buf[BUFFER_SIZE];
            if(read(sock,buf,BUFFER_SIZE)==0){
                exit(0);
            }else{
                printf("對方:%s\n",buf);
                memset(buf,'\0',strlen(buf));
       }
    }
    pthread_exit(NULL);
}
int main(int argc,char **argv){
        pthread_t thread1, thread2;
        int serverport, n, count , *toSock;
        char str[BUFFER_SIZE];
        struct sockaddr_in server_addr;
        serverport = atoi(argv[1]);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock<0)
        {
                printf("Socket Error...\n");
                return 1;
        }
        server_addr.sin_family = AF_INET;
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);
        server_addr.sin_port = htons(serverport);
        if(connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr))!=0) {printf("Couldn't connect to Server!");exit(1);}
        pthread_create(&thread1,NULL,&theListen,NULL);
        while(1){
            memset(str,'\0',BUFFER_SIZE);
            gets(str);
            send(sock,str,BUFFER_SIZE,0);
        }
        close(sock);
}