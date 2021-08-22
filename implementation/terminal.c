#include "../include/terminal.h"
#include "../include/util.h"
#include <unistd.h>

pthread_mutex_t mutex_terminal = PTHREAD_MUTEX_INITIALIZER;
// -------------------------------- Funcinalidades -------------------------------- //
// Envia mensagens
void sender()
{
  int id;
  clean();
  printf("0: Sair\nID do destino: ");
  scanf("%d", &id);
  if (id == 0)
  {
    printf("Saindo...");
    return;
  }
  char message;
  printf("Message: ");
  scanf("%s",&message);
}
// Mensagens recebidas
void receiver()
{
  printf("teste");
}

// -------------------------------- Main -------------------------------- //
void terminal()
{
  bool run_terminal = true;
  while (run_terminal)
  {
    menu();
    pthread_mutex_unlock(&mutex_terminal);
    char opcao = get_char();
    pthread_mutex_lock(&mutex_terminal);

    switch (opcao)
    {
    case '0':
      run_terminal = false;
      printf("Fechando programa...\n");
      clean();
      break;
    case '1':
      sender();
      break;
    case '2':
      receiver();
      break;
    default:
      break;
    }
  }
}