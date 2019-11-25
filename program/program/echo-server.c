
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
sig_atomic_t child_exit_status;
#define BUFFER_SIZE 1024
#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }
int main(int argc,char **argv){
        int sock1, condf,err;
        socklen_t len;
        struct sockaddr_in server_addr, client_addr;
        char buf[BUFFER_SIZE],str[BUFFER_SIZE];
        //Open socket
        sock1 = socket(AF_INET, SOCK_STREAM, 0);
        if (sock1 < 0){
                printf("Socket Error...\n");
                return 1;
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[1]));

        if(bind(sock1,(struct sockaddr *) &server_addr, sizeof(struct sockaddr))== -1){
                printf("bind error\n");
                return 1;
        }
        listen(sock1,100);
        while(1){
        len = sizeof(struct sockaddr);
        condf = accept(sock1, (struct sockaddr *) &client_addr, &len);
        printf("client connected with ip address: %s\n",
        inet_ntoa(client_addr.sin_addr));
        while(1){
            if(read(condf,buf,20)==0){
                break;
            }else{
                printf("The message is :%s\n",buf);
                strcpy(str,buf);
                write(condf,str,strlen(str));
                memset(buf,'\0',strlen(buf));
            }
        }
    }
    close(sock1);
}