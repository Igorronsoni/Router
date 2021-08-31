#include "../include/receiver.h"

//listens to incoming messages
void *receiver(void *args)
{
    Message buff;
    struct sockaddr_in si_other;
    int recv_len, slen = sizeof(si_other);

    for (;;)
    {
        memset(&buff, 0, sizeof(buff));

        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(socket_descriptor, &buff, sizeof(buff), 0, (struct sockaddr *)&si_other, &slen)) == -1)
        {
            perror("Receiving socket");
            exit(1);
        }
        pthread_mutex_lock(&receiver_queue_mutex);

        //add item to packet_handler's queue
        if (!queue_receiver_message_full)
        {
            received_messages.queue[received_messages.index_write] = buff;
            if (received_messages.index_write == MAX_QUEUE_MESSAGES - 1)
                received_messages.index_write = 0;
            else
                received_messages.index_write++;

            if (received_messages.queue[received_messages.index_write].ativo == false)
                queue_receiver_message_full = true;

            pthread_mutex_unlock(&receiver_queue_mutex);
        }
        else
        {
            pthread_mutex_unlock(&receiver_queue_mutex);
            continue;
        }
    }

    pthread_exit(NULL);
}
