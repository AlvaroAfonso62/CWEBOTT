/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2020 10:25:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */



#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]){
  struct sockaddr_in cs_addr = {
    .sin_family = AF_INET,
    .sin_addr   = htonl(atoi(argv[1])),
    .sin_port   = htons(atoi(argv[2]))
  };
  int c_socket;

  c_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  if(connect(c_socket, (struct sockaddr *) &cs_addr, sizeof(cs_addr)) != -1){
    
    printf("Connected !\n");

    while(1){
    
    }
  
  }

  return 0;

}
