#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NB 10

typedef struct {
    int variable;
} Donnees;


void* maFonction(void* argument) {
    Donnees* donnees = (Donnees*) argument
    printf("je suis un thread, variable = %d \n", donnees->variable);
    pthread_exit(NULL);
}
int main(int argc, char* argv[]) {
    pthread_t monThread;
    Donnees donnees;
    donnees.variable = 10;
    pthread_create(&monThread, NULL, maFonction, (void*) &donnees);
    pthread_joint(monThread, NULL);
}