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
