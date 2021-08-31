#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "configs.h"

// Estrutura de mensagem entre roteadores
typedef struct _message
{
  // 0: data; 1: controle
  char type;
  bool ativo;
  int origem;
  int destino;
  char mensagem[MAX_SIZE_MESSAGE];
} Message;

// Estrutura de saida de mensagens
typedef struct _queue_message
{
  int index_write;
  int index_read;
  Message queue[MAX_QUEUE_MESSAGES];
} Queue_message;

// Estrutura de um roteador
typedef struct _roteador
{
  int id;
  char ip[16];
  unsigned short port;
} Roteador;
