#pragma once

#include <stdio.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <semaphore.h>

#include "structures.h"
#include "global.h"

extern void* sender(void* args);