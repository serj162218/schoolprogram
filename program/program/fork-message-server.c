
//--------------------Server---------------------
// ./server portnumber &
#define _XOPEN_SOURCE
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

void clean_up_child_process(int signal_number){
        //Clean up the child process.
        int status;
        waitpid(-1, &status, WNOHANG);
        // Store its exit status in a global variable.
        child_exit_status = status;
}

int main(int argc, char **argv){
        int sock1, condf,pid;
        socklen_t len;
        char str[30];
        struct sockaddr_in server_addr, client_addr;
        if(argc != 2){
        printf("Usage: ./server portno \n");
        return 1;
        }
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
    /* Handle SIGCHLD by calling clean_up_child_process. */
     struct sigaction sigchld_action;
     memset (&sigchld_action, 0, sizeof (sigchld_action));
     sigchld_action.sa_handler = &clean_up_child_process;
     sigaction (SIGCHLD, &sigchld_action, NULL);
    /* Now do things, including forking a child process. */
        listen(sock1,100);
        while(1){
        memset(str,'\0',strlen(str));
        len = sizeof(struct sockaddr);
        condf = accept(sock1, (struct sockaddr *) &client_addr, &len);
        if(condf == -1){
                if(errno == EINTR) continue;
                else perror("accept");
                exit(errno);
        }
        if((pid=fork())==0){
                close(sock1);
                while(1){
                        if(read(condf , str , BUFFER_SIZE)==0){
                        puts("Client has left the message room.\n");
                        exit(0);
                        }else{
                        printf("\nClient:%s\n",str);
                        }
                }
        }else{
                while(1){
                        gets(str);
                        write(condf,str ,BUFFER_SIZE);
                }
                }
        }
        close(sock1);
}