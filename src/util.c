#include "../include/util.h"

// Limpa tela
void clean()
{
  system("clear||cls");
}

// Entrada do teclado para menus
char get_char()
{
  fflush(stdin); // Limpa o terminal
  char op = getchar();
  while (op != '\n' && '\n' != getchar())
    ;
  return op;
}

// Print opções do menu do roteador
void menu()
{
  clean();
  printf("Roteador %d\n\n-------------- MENU --------------\n0: Sair\n1: Enviar Mensagem\n2: Mensagens Recebidas(%d)\n3: Vizinhos\n4: Desligar/Ligar roteador\n\nMensagens de controle(%d)\n\n> ", main_router.id, 0, 0);
}

// Lee o vetor de vizinhos para saber se ja existe o vizinho cadastrado
int indexOf(int id)
{
  for (int i = 0; i < MAX_VIZINHOS; i++)
  {
    if (vizinhos[i] == 0)
      return -1;
    if (vizinhos[i] == id)
      return i;
  }
}