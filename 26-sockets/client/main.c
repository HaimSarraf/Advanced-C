#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


short socketCreate(void);
int socketConnect(int);
int socketSend(int , char *,short);
int socketReceive(int , char *,short);

int main(int argc, char *argv[])
{
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char serverReply[200] = {0};

    //? Create socket
    hSocket = socketCreate();

    if(hSocket == -1){
        printf("Could not create socket\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message : ");
    fgets(sendToServer, 100, stdin);

    //? Send data to the server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //? Receive the data from the server
    read_size = socketReceive(hSocket, serverReply, 200);
    printf("Server Response : %s\n",serverReply);

    close(hSocket);

    return 0;

}

short socketCreate(void){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM,0);
    return hSocket;
}


int socketConnect(int hSocket)
{
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};

    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}


//? Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char * Rqst,short lenRqst)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; // 20 Secs Timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//? Receive the data from the server
int socketReceive(int hSocket, char * Rsp,short RvcSize)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; // 20 Secs Timeout
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    
    printf("Response %s\n", Rsp);

    return shortRetval;
}