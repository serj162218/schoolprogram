//未完成
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
#include <sys/types.h>
#define BUFFER_SIZE 1024
#define STDIN 0
int main(int argc,char **argv){
        int sock, serverport, n, count;
        char buf[BUFFER_SIZE],str[BUFFER_SIZE];
        struct sockaddr_in server_addr;
        struct timeval tv;
        tv.tv_sec = 5;
        fd_set testfd;
        serverport = atoi(argv[1]);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        FD_ZERO(&testfd);
        if(sock<0)
        {
                printf("Socket Error...\n");
                return 1;
        }
        server_addr.sin_family = AF_INET;
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);
        server_addr.sin_port = htons(serverport);
        connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
        while(1){
            FD_ZERO(&testfd);
            FD_SET(STDIN,&testfd);
            FD_SET(sock,&testfd);
            select(2,&testfd,NULL,NULL,&tv);
            if(FD_ISSET(STDIN,&testfd)){
            memset(str,'\0',strlen(str));
            gets(str);
            write(sock,str,strlen(str));
            }
            if(FD_ISSET(sock,&testfd)){
            if(read(sock,buf,20)==0){
                exit(0);
            }else{
                printf("Your message is:%s\n",buf);
                memset(buf,'\0',strlen(buf));
            }
            }
        }

        close(sock);
}