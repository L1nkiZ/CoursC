#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct
{
    int taille;
    int* contenu;
}Tableau;


void* nombrespif(void* argument){
    Tableau* tab = (Tableau)argument;
    for (int i = 0; i < tab->taille; i++)
    {
        tab->contenu[i]=rand()%5+1;
        sleep(1);
    }
    pthread_exit(NULL);

}

void affichage(void* argument){
    Tableau* tab = (Tableau)argument;
    for (int j = 0; j < tab->taille/2+1; j++)
    {
        for (int i = 0; i < tab->taille; i++)
        {
            printf("%d\n",tab->contenu[i]);
        };
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(int argc, char constargv[])
{

    pthread_t monThread;
    pthread_t monThread2;
    Tableau tab;
    int tempo;

    printf("taille du tableau?\n");
    scanf("%d", &tempo);

    tab.taille=tempo;
    tab.contenu=(int)malloc(temposizeof(int));

    for (int i = 0; i < tempo; i++)
    {
        tab.contenu[i]=0;
    };


    pthread_create(&monThread, NULL, nombrespif, (void) &tab);
    pthread_create(&monThread2, NULL, affichage, (void) &tab);

    pthread_join(monThread, NULL);
    pthread_join(monThread2, NULL);
/*
    for (int i = 0; i < tempo; i++)
    {
        printf("%d\n",tab.contenu[i]);
    };
*/
    return 0;
}