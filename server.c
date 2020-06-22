/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/29/2020 08:35:48 PM
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
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 128
#define CLI_CONN 10

int s_clients[CLI_CONN];

void *t_accept(void *s_s){ 
  int *s_socket = (int *) s_s;
  int stemp_client, sc_size;
  struct sockaddr_in sc_addr;
  
  sc_size = sizeof(sc_addr);

  int id = 0;
  
  while(1){
    
    stemp_client = accept(*s_socket, (struct sockaddr *) &sc_addr, &sc_size);
    
    if(stemp_client != -1){
      s_clients[id] = stemp_client;
      
      printf("[!] %s\n[!] Cliente Conectado !\n", inet_ntoa(sc_addr.sin_addr));

      id++;
    }

  } 

}


int main(int argc, char *argv[]){
  pthread_t thread[1];
  struct sockaddr_in ss_addr = {
    .sin_family       = AF_INET,
    .sin_addr.s_addr  = htonl(INADDR_ANY),
    .sin_port         = htons(atoi(argv[1]))
  };

  int s_socket = socket(AF_INET, SOCK_STREAM, 0);  
  bind(s_socket, (struct sockaddr *) &ss_addr, sizeof(ss_addr));
  
  listen(s_socket, CLI_CONN);
  
  pthread_create(&(thread[1]), NULL, t_accept, &s_socket);
  pthread_join(thread[1], NULL);

 



  return 0;

}
