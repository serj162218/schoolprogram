//--------------------Client------------------------
// ./client IP portnumber
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
        int sock, serverport, n, count,pid;
        char buf[BUFFER_SIZE],str[BUFFER_SIZE];
        struct sockaddr_in server_addr;
        serverport = atoi(argv[2]);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock<0)
        {
                printf("Socket Error...\n");
                return 1;
        }
        server_addr.sin_family = AF_INET;
        inet_pton(AF_INET, argv[1], &server_addr.sin_addr.s_addr);
        server_addr.sin_port = htons(serverport);
        /* Handle SIGCHLD by calling clean_up_child_process. */
        struct sigaction sigchld_action;
        memset (&sigchld_action, 0, sizeof (sigchld_action));
        sigchld_action.sa_handler = &clean_up_child_process;
        sigaction (SIGCHLD, &sigchld_action, NULL);
        /* Now do things, including forking a child process. */
        if(connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr))==-1){puts("Connect error!");exit(1);} 
        while(1){
            if((pid=fork())==0){
                while(1){
                    if(read(sock , buf , BUFFER_SIZE)==0){
                        puts("Server has left the message room.\n");
                        exit(0);
                    }else{
                        printf("\nServer:%s\n",buf);
                    }
                }
            }else{
                while(1){
                    gets(str);
                    write(sock,str,BUFFER_SIZE);
                }
            }
        }

        close(sock);
}