//message-server by using thread, please use gcc -o message-server -pthread message-server.c
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
int condf;
void *theListen(void *data){
    for(;;){
            char buf[BUFFER_SIZE];
            if(read(condf,buf,BUFFER_SIZE)==0){
                exit(0);
            }else{
                printf("對方:%s\n", buf);
                memset(buf,'\0',strlen(buf));
       }
    }
}
int main(int argc,char **argv){
        int err ;
        void *status;
        pthread_t thread1;
        socklen_t len;
        struct sockaddr_in server_addr, client_addr;
        char str[BUFFER_SIZE];
        int sock;
        //Open socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0){
                printf("Socket Error...\n");
                return 1;
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[1]));

        if(bind(sock,(struct sockaddr *) &server_addr, sizeof(struct sockaddr))== -1){
                printf("bind error\n");
                return 1;
        }
        listen(sock,100);
        while(1){
        len = sizeof(struct sockaddr);
        condf = accept(sock, (struct sockaddr *) &client_addr, &len);
        printf("client connected with ip address: %s\n",
        inet_ntoa(client_addr.sin_addr));
        pthread_create(&thread1,NULL,&theListen,NULL);
            while(1){
                memset(str,'\0',BUFFER_SIZE);
                gets(str);
                send(condf,str,BUFFER_SIZE,0);
            }
        }
    close(sock);
}