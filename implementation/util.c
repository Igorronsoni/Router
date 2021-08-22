#include "../include/util.h"
#include <stdlib.h>

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
  while (op != '\n' && '\n' != getchar());
  return op;
}

// Print opções do menu do roteador
void menu()
{
  clean();
  printf("---------------------- MENU ----------------------\n0: Sair\n1: Enviar Mensagem\n2: Mensagens Recebidas(n)\n\n> ");
}
