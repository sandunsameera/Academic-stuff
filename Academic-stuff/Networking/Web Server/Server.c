#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>

#define PORT 4800
char *init_mg = "Hello Server";
char buffer[30000] = {0};
char *Mimi_Type;

 int Server, new_socket; long Read_Value;
 struct sockaddr_in sock_address;
 int addrlen = sizeof(sock_address);

void make_socket(){
    if ((Server = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error in socket");      //Making the socket
        exit(EXIT_FAILURE); 
    }
}

void bind_socket(){
    if (bind(Server, (struct sockaddr *)&sock_address, sizeof(sock_address)) == -1)
    {
        perror("Error In bind");
        exit(EXIT_FAILURE);
    }
}

void listner(){
    if (listen(Server, 10) <  0)       
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
}

void SendResponse(int fd, char *header, void *body,int contentLength){
  char response[contentLength+100]; 
  int response_length = sprintf(response,  //sprintf similar to prontf but return the string
                "%s\n"
                "Connection: close\n"
                "Content-Length: %d\n"
                "Content-Type: %s\n"
                "\n",
                header,
                contentLength, 
                Mimi_Type);
  memcpy(response + response_length, body, contentLength); //copy block of memory from a location to another
  send(fd, response, response_length + contentLength, 0); //transmit message to another socket
}

void SendFile(int fd, char *FileName){
    char *entry;
    FILE *file = fopen(FileName, "r");  //fopen - open file
    size_t bufsize;
    if (file != NULL) {
        if (fseek(file, 0L, SEEK_END) == 0) {  //fseek - sets the file position of the sream to given offset
            bufsize = ftell(file);  //return current position of file
            entry = malloc(sizeof(char) * (bufsize + 1));
            fseek(file, 0L, SEEK_SET);    
            fread(entry, sizeof(char), bufsize, file);
            SendResponse(fd,"HTTP/1.1 200 OK", entry, bufsize);   
        }
    }else{
        char *error = "file not found";
        Mimi_Type = "text/html";
        SendResponse(fd, "HTTP/1.1 404 NOT FOUND", error, strlen(error));
    }
}


int main(int argc, char const *argv[])
{
    char requestType[4];       
    char requestpath[1024];

    make_socket();
    sock_address.sin_family = AF_INET;  
    sock_address.sin_addr.s_addr = INADDR_ANY;        
    sock_address.sin_port = htons( PORT );
    
    memset(sock_address.sin_zero, '\0', sizeof sock_address.sin_zero); //memset() is used to fill a block of memory with a particular value.

    bind_socket();
    listner();

    
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(Server, (struct sockaddr *)&sock_address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        read(new_socket,buffer,1024); //reads data previously written to a file
        sscanf(buffer, "%s %s", requestType, requestpath);
        
        char *mime = strrchr(requestpath, '.')+1;  //return last occurence in string
        char *name = strtok(requestpath, "/"); // split string to token

        if(mime)
            Mimi_Type = mime;
        else
            Mimi_Type = NULL;

        if (!strcmp(requestType, "GET") && !strcmp(requestpath, "/")) {  // compare two string character by character
            char *data = "You made a GET request";
            Mimi_Type = "text/html";
            SendResponse(new_socket, "HTTP/1.1 200 OK", data, strlen(data));
        }else{
            SendFile(new_socket,name);
        } 
        printf("------------------Response sent from server-------------------");
    }
    return 0;   
}