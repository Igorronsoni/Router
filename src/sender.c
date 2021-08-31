#include "../include/sender.h"

void *sender(void *args)
{

  struct sockaddr_in si_other;
  int slen = sizeof(si_other);
  for (;;)
  {
    int s;
    // Enquanto estiver sem mensagens para enviar
    while ((s = sem_wait(&sender_sema)) == -1)
      continue;

    pthread_mutex_lock(&send_mutex);
    if (!(sender_messages.index_write == sender_messages.index_read))
    {
      // Pega a proxima mensagem não nula na queue
      Message dado = sender_messages.queue[sender_messages.index_read];
      sender_messages.queue[sender_messages.index_read].ativo = false;
      if (sender_messages.index_read + 1 == MAX_QUEUE_MESSAGES)
        sender_messages.index_read = 0;
      else
        sender_messages.index_read++;

      memset((char *)&si_other, 0, sizeof(si_other));
      si_other.sin_family = AF_INET;
      si_other.sin_port = htons(25002);
      if (inet_aton("127.0.0.1", &si_other.sin_addr) == 0)
      {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
      }

      //send the UDP packet
      if (sendto(socket_descriptor, &dado, sizeof(dado), 0, (struct sockaddr *)&si_other, slen) == -1)
      {
        perror("Sending socket");
        exit(1);
      }
    }
    else
    {
      pthread_mutex_unlock(&send_mutex);
    }
  }
  pthread_exit(NULL);
}
