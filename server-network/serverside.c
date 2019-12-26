#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8000
int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Only this line has been changed. Everything is same.
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    char *fuck = "Hello fuck";
    
    // Creating socket file descriptor
    //parameters: 1-IP address family (communication domain in which the socket should be created)
    //2-type(type of service. This is selected according to the properties required by the application)
    //3-protocol
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Error in socket");      //Making the socket
        exit(EXIT_FAILURE); 
    }
    

    address.sin_family = AF_INET;  //indicate a specific protocol to use in supporting the sockets operation
    address.sin_addr.s_addr = INADDR_ANY; //INADDR_any = 0.0.0.0 whrer we dont define any specific IP address          
    address.sin_port = htons( PORT );
    
    // memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0)       
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))>0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        printf("%s\n",buffer );
        // write(new_socket , fuck , strlen(fuck));
        printf("------------------Hello message sent-------------------");
        close(new_socket);
    }
    return 0;
}