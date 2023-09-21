#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structurs pour declaration les variables

typedef struct
{
    int ID;
    char titre[20];
    char description[100];
    char deadline[30];
    char statut[30];

} nouv_tache;

nouv_tache Tache[100];

// ajoutee nouvelle tache

void AjouteUneTache(int nbr_tache)
{
    printf("ID de la tache : ");
    scanf("%d",&Tache[nbr_tache].ID);
    printf("Titre de la tache :\n ");
    scanf("%s",Tache[nbr_tache].titre);
    printf("Description de la tache \n: ");
    scanf("%s",Tache[nbr_tache].description);
    printf("Deadline de la tache : \n");
    scanf("%s",Tache[nbr_tache].deadline);
    printf("Statut de la tache : \n");
    scanf("%s",Tache[nbr_tache].statut);
   nbr_tache++;
}
// affichage

void AfficherLesTaches(int nbr_tache)
{
  for (int i = 0; i < nbr_tache ; i++)
{
    printf("ID: %d\n", Tache[i].ID);
    printf("Titre: %s\n", Tache[i].titre);
    printf("Description: %s\n", Tache[i].description);
    printf("Deadline: %s\n", Tache[i].deadline);
    printf("Statut: %s\n", Tache[i].statut);
    printf("\n");
}
}



//modification













int main()
{
    int choix;
    int nbr_tache = 0;

    do
    {
        printf("**************menu principale**************\n" );
        printf("1- ajoutee nouvelle tache \n" );
        printf("2- modifier une tache \n" );
        printf("3- supprimer une tache \n" );
        printf("4- recherche une tache \n" );
        printf("5- statistique \n" );
        printf("0- Quitter\n");
        printf("*******************************************\n" );
        printf("votre choix est : \n" );
        scanf("%d",&choix);

        switch (choix)
        {
        case 1 :
        {
            printf("ajoutee nouvelle tache \n" );
            int i, N;
            printf("nombre de tache a ajoute : \n" );
            scanf("%d",&N);

            for (i = 0 ; i < N ; i++)

                AjouteUneTache(&nbr_tache); //la fonction pour ajouter une tâche
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
    while (choix != 0);



    return 0;

}
