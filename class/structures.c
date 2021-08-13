#include <stdlib.h>

// Estrutura de mensagem entre roteadores
typedef struct
    _message
{
  // 0: data; 1: controle
  char type;
  int origem;
  int destino;
  char mensagem[100];
} message;

// Estrutura de fila de entrada e saida de pacotes
typedef struct _queue
{
  // 0: input messages; 1: output messages
  char type;
  message queue[10]
} queue;
