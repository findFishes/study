#include <winsock2.h>
#include <stdio.h>
int main(){
   SOCKET client_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   printf("Compile successfully!");
}