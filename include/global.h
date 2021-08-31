#pragma once

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#include "configs.h"
#include "structures.h"

// Router
extern Roteador main_router;

// Socket
int socket_descriptor;

// Mensagens
extern Queue_message sender_messages;
extern Queue_message receiver_message;
extern bool queue_receiver_message_full;

// Vizinhos
extern int vizinhos_contador, vizinhos[];
extern Roteador router_vizinho[];
extern int router_vizinho_contador;

// Sender
extern sem_t sender_sema;
extern pthread_mutex_t send_mutex;

// Receiver
extern pthread_mutex_t receiver_queue_mutex;

// Threads
extern pthread_t receiver_thread, sender_thread;
