#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NB 10

typedef struct {
    int variable;
} Donnees;

void* ajoute(void* argument) {
    Donnees* donnees = (Donnees) argument;
    donnees->variable+=4;
    pthread_exit(NULL);
}

void* divise(void* argument) {
    Donnees* donnees = (Donnees) argument;
    donnees->variable/=2;
    printf("%d\n", donnees->variable);
    pthread_exit(NULL);
}

void* multiplie(void* argument) {
    Donnees* donnees = (Donnees) argument;
    donnees->variable*=4;
    printf("%d\n", donnees->variable);
    pthread_exit(NULL);
}

void* retranche(void* argument) {
    Donnees* donnees = (Donnees) argument;
    donnees->variable-=4;
    printf("%d\n", donnees->variable);
    pthread_exit(NULL);
}


int main(int argc, char argv[]) {
    pthread_t monPremierThread;
    pthread_t monDeuxiemeThread;
    pthread_t monTroisiemeThread;
    pthread_t monQuatriemeThread;
    Donnees donnees;
    donnees.variable = 10;
    pthread_create(&monPremierThread, NULL, ajoute, (void*) &donnees);
    pthread_join(monPremierThread, NULL);
    pthread_create(&monDeuxiemeThread, NULL, ajoute, (void*) &donnees);
    pthread_join(monDeuxiemeThread, NULL);
    pthread_create(&monTroisiemeThread, NULL, ajoute, (void*) &donnees);
    pthread_join(monTroisiemeThread, NULL);
    pthread_create(&monQuatriemeThread, NULL, ajoute, (void*) &donnees);
    pthread_join(monQuatriemeThread, NULL);
}
