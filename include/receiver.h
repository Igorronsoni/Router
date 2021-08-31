#pragma once

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "global.h"
extern void* receiver(void* args);