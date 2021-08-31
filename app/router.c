#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "../include/terminal.h"
#include "../include/global.h"
#include "../include/read_file.h"
#include "../include/receiver.h"
#include "../include/sender.h"

pthread_t sender_thread, receiver_thread;
sem_t sender_sema;

Roteador main_router;
Roteador router_vizinho[MAX_VIZINHOS];
int vizinhos_contador = 0, vizinhos[MAX_VIZINHOS];
int router_vizinho_contador = 0;

int socket_descriptor;

// Mensagens
Queue_message received_messages;
Queue_message sender_messages;
bool queue_receiver_message_full = false;
pthread_mutex_t receiver_queue_mutex = PTHREAD_MUTEX_INITIALIZER, send_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
  // Alexsandro Code
  if (argc < 2)
  { //it is necessary to run the Router with an id
    fprintf(stderr, "Please use \"./Router <id>\"\n");
    exit(1);
  }
  //

  main_router.id = atoi(argv[1]);

  read_enlaces(); // Verifica os vizinhos
  if (!read_routers())
  { // Verifica os dados dos vizinhos
    printf("Não existe um roteador com id %d. Por favor digite um ID valido\n", main_router.id);
    exit(1);
  }

  //create the UDP socket
  if ((socket_descriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
  {
    perror("Socket creation error");
    exit(1);
  }

  //bind the socket
  struct sockaddr_in si_me;
  memset((char *)&si_me, 0, sizeof(si_me));
  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(main_router.port);
  si_me.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(socket_descriptor, (struct sockaddr *)&si_me, sizeof(si_me)) == -1)
  {
    perror("Socket bind error");
    exit(1);
  }

  // Inicializa os semaphores
  sem_init(&sender_sema, 0, 0);

  // Threads
  pthread_create(&receiver_thread, NULL, receiver, NULL);
  pthread_create(&sender_thread, NULL, sender, NULL);
  
  terminal();

  //terminate threads
  pthread_cancel(receiver_thread);

  pthread_join(receiver_thread, NULL);

  //close the socket
  int true_v = 1;
  setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &true_v, sizeof(int));
  close(socket_descriptor);
  return 0;
}