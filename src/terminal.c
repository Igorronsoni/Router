#include "../include/terminal.h"

pthread_mutex_t mutex_terminal = PTHREAD_MUTEX_INITIALIZER;
// -------------------------------- Funcinalidades -------------------------------- //
// Envia mensagens
void sender_message()
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

  Message mensagem;
  mensagem.origem = main_router.id;
  mensagem.mensagem = message;
}
// Mensagens recebidas
void receiver_messages()
{
  int op;
  printf("ID origem | Tipo de mensagem | ------------ Mensagem ------------ |\n");
  printf("0: Voltar\n\n>");
  scanf("%d", &op);
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
      sleep(2);
      clean();
      break;
    case '1':
      sender_message();
      break;
    case '2':
      receiver_messages();
      break;
    default:
      break;
    }
  }
}