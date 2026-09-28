#include <stdio.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <pico/stdlib.h>
#include "threads_functions.h"

void countThread(int* _count, SemaphoreHandle_t* _semaphore){
    if (xSemaphoreTake(semaphore, (TickType_t) 10) == pdTRUE) 
        {
            incrementCount(&_count);
            char* name = "thread";
		    printCount(name, &_count);
            xSemaphoreGive(_semaphore);
        }
}

void blinkThread(int* _count, SemaphoreHandle_t* _semaphore){
    if (xSemaphoreTake(semaphore, (TickType_t) 10) == pdTRUE) 
        {
            char* name = "main";
		    printCount(name, _count);
            incrementCount(_count);
            xSemaphoreGive(semaphore);
        }
}

int incrementCount(int* _count){
    (*_count)++;
}

int printCount(char* threadName, int* _count){
    printf("hello world from %s! Count %d\n", threadName, counter);
}

int toggleOn(int* on){
    (*on) = !(*on);
}