#include <stdio.h>
#include <stdlib.h>
// structurs pour declaration les variables

typedef struct
{
    int ID;
    char titre[20];
    char description[100];
    char deadlline[30];
    char statut[30];

} nouv_tache;

nouv_tache tache[100];

// ajoutee nouvelle tache

void AjouteUneTache()
{
    printf("ID de la tache : ");
    scanf("%d", &tache.ID);
    getchar();
    printf("Titre de la tache : ");
    gets(tache.titre);
    printf("Description de la tache : ");
    gets(tache.description);
    printf("Deadline de la tache : ");
    gets(tache.deadlline);
    printf("Statut de la tache : ");
    gets(tache.statut);
}
// affichage

for (int i = 0; i < nbr_tache ; i++)
    {
        printf("ID: %d\n", tache.ID);
        printf("Titre: %s\n", tache.titre);
        printf("Description: %s\n", tache.description);
        printf("Deadline: %s\n", tache.deadlline);
        printf("Statut: %s\n", tache.statut);
        printf("\n");
    }


//modification













int main()
{
    int choie;
    nouv_tache;
    int nbr_tache = 0;
    do
    {
        printf("     menu principale : \n" );
        printf("1- ajoutee nouvelle tache \n" );
        printf("2- modifier une tache \n" );
        printf("3- supprimer une tache \n" );
        printf("4- recherche une tache \n" );
        printf("5- statistique \n" );


        printf("votre choix est : \n" );
        scanf("%d",&choie);

        switch (choie)
        {
        case 1 :
        {
            printf("ajoutee nouvelle tache \n" );
            int i, N;
            printf("nombre de tache a ajoute : \n" );
            scanf("%d",&N);

            for (i = 0 ; i < N ; i++){
                tache.ID = nbr_tache + 1;
                identifiant_tache(tache);// fonction d'ajout //ajoute un tache ou plusieur taches // trieage par titre ASCII
                nbr_tache ++;
            }

        }

        break;
        case 2 :
            printf("modifier une tache \n" );// fonction de modification
            break;
        case 3 :
            printf("supprimer une tache \n" );// fonction de supprimer
            break;
        case 4 :
            printf("recherche une tache \n" );// fonction de recherche
            break;
        case 5 :
            printf("statistique \n" );// statistique
            break;
        default:
            printf("quitter \n" );
            break;
        }

    }
    while (choie != 0);



    return 0;

}
