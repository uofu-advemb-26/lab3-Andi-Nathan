#ifndef THREADS_FUNCTIONS_H
#define THREADS_FUNCTIONS_H

#include <FreeRTOS.h>
#include <semphr.h>

void countThread(int* _count, SemaphoreHandle_t* _semaphore);

void blinkThread(int* _count, SemaphoreHandle_t* _semaphore);

int incrementCount(int* _count);

int printCount(char* threadName, int* _count);
int toggleOn(int* on);

#endif