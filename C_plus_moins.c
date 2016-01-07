#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int nombreMystere = 0, nombreEntre = 0,nombreCoup=0,Rejouer=1,Level=0,Max=0;
    printf("Bienvenue au Plus ou Moins !\n");

    while (Rejouer==1)
    {
        printf("Selectionnez un niveau de difficulte !\n");
        printf("Niveau 1 - nombre mystere entre 1 et 100\n");
        printf("Niveau 2 - nombre mystere entre 1 et 1000\n");
        printf("Niveau 3 - nombre mystere entre 1 et 10000\n");
        printf("Je choisi le niveau: ");
        scanf("%d",&Level);
        printf("\n");
        if (Level==1)
            Max=100;
        else if (Level==2)
            Max=1000;
        else if (Level==3)
            Max=1000;

        const int MAX = Max, MIN = 1;

        srand(time(NULL));
        nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

            do
            {
                printf("Quel est le nombre ? ");
                scanf("%d", &nombreEntre);
                nombreCoup++;
                if (nombreMystere > nombreEntre)
                    printf("C'est plus !\n\n");
                else if (nombreMystere < nombreEntre)
                    printf("C'est moins !\n\n");
                else
                {
                    printf ("Bravo, vous avez trouve le nombre mystere en %d coups !\n\n",nombreCoup);
                    nombreCoup=0;
                }
            } while (nombreEntre != nombreMystere);
        printf("Voulez-vous rejouer ? Tapez 1 pour rejouer et 0 pour arreter : ");
        scanf("%d",&Rejouer);
        printf("\n");
    }
    return 0;
}
