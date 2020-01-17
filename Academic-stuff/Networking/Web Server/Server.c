#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>

#define PORT 4800
char *mime_type;

 int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[30000] = {0};
    char *fuck = "Hello fuck";

void make_socket(){
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error in socket");      //Making the socket
        exit(EXIT_FAILURE); 
    }
}

void bind_socket(){
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("Error In bind");
        exit(EXIT_FAILURE);
    }
}

void listner(){
    if (listen(server_fd, 10) <  0)       
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
}

void send_responce(int fd, char *header, void *body,int contentLength) {
  
  char response[contentLength+100]; 
  int response_length = sprintf(response,
                "%s\n"
                "Connection: close\n"
                "Content-Length: %d\n"
                "Content-Type: %s\n"
                "\n",
                header,
                contentLength, 
                mime_type);

  memcpy(response + response_length, body, contentLength); 
  send(fd, response, response_length + contentLength, 0); 

}

void send_file(int fd, char *file_name){
    
    
    char *source;
    FILE *file = fopen(file_name, "r");
    size_t bufsize;
    if (file != NULL) {
        if (fseek(file, 0L, SEEK_END) == 0) {
            bufsize = ftell(file);  
            source = malloc(sizeof(char) * (bufsize + 1));
            fseek(file, 0L, SEEK_SET);    
            fread(source, sizeof(char), bufsize, file);
            send_responce(fd,"HTTP/1.1 200 OK", source, bufsize);   
        }
    }else{
        char *error = "file not found";
        mime_type = "text/html";
        send_responce(fd, "HTTP/1.1 404 NOT FOUND", error, strlen(error));
    }
  
}


int main(int argc, char const *argv[])
{
    char requestType[4];       
    char requestpath[1024];

    make_socket();
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;        
    address.sin_port = htons( PORT );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    bind_socket();
    listner();

    
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        read(new_socket,buffer,1024);
        sscanf(buffer, "%s %s", requestType, requestpath);
        
        char *mime = strrchr(requestpath, '.')+1;
        char *name = strtok(requestpath, "/");

        if(mime)
            mime_type = mime;
        else
            mime_type = NULL;

        if (!strcmp(requestType, "GET") && !strcmp(requestpath, "/")) {
            char *data = "You made a GET request";
            mime_type = "text/html";
            send_responce(new_socket, "HTTP/1.1 200 OK", data, strlen(data));
        }else{
            send_file(new_socket,name);
        } 
        printf("------------------Response sent from server-------------------");
    }
    return 0;   
}