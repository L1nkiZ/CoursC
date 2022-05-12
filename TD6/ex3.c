#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct

{
    int taille;
    int* contenu;
}Tableau;

int main(int argc, char const argv[])
{
    Tableau tab;
    int tempo;

    printf("taille du tableau?\n");
    scanf("%d", &tempo);

    tab.taille=tempo;
    tab.contenu=(int)malloc(tempo*sizeof(int));

    for (int i = 0; i < tempo; i++)
    {
        tab.contenu[i]=0;
    };


    for (int i = 0; i < tempo; i++)
    {
        printf("%d", tab.contenu[i]);
    };
