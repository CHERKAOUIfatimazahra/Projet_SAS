#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int nbr_tache = 0;
// 1-ajoutee nouvelle tache

void AjouteUneTache()
{
    //conteur des tach



    printf("ID de la tache : ");
    scanf("%d",&tache[nbr_tache].ID);
    getchar();
    printf("Titre de la tache : ");
    gets(tache[nbr_tache].titre);
    printf("Description de la tache : ");
    gets(tache[nbr_tache].description);
    printf("Deadline de la tache : ");
    gets(tache[nbr_tache].deadlline);
    printf("Statut de la tache : ");
    gets(tache[nbr_tache].statut);
}

// 6-Fonction pour afficher une tâche
void AfficherTache()
{
    printf("ID de tâche: %d\n", tache[nbr_tache].ID);
    printf("Titre: %s\n", tache[nbr_tache].titre);
    printf("Description: %s\n", tache[nbr_tache].description);

    printf("Statut: %s\n", tache[nbr_tache].statut);

}

// 3-modifier une tache
void ModificationTache ()
{
    //appeler l'id
    int taskId;
    int i;
    printf("Entrez l'ID de la tâche que vous souhaitez modifier : ");
    scanf("%d", &taskId);

    //recherche id

    for (i=0 ; i < nbr_tache ; i++)
        if(tache[i].ID == taskId)
        {
            //choix de modification
            int choix;
            printf("votre choix est : \n" );
            scanf("%d",&choix);

            switch (choix)
            {
            case 1 :
            {
                getchar();
                printf("ajoutee nouvelle Description \n" );
                gets(tache[nbr_tache].description);
                break;
            }
            case 2 :
            {
                getchar();
                printf("Deadline de la tache \n" );
                gets(tache[nbr_tache].deadlline);
                break;
            }
            case 3 :
            {
                getchar();
                printf("Statut de la tache \n" );
                gets(tache[nbr_tache].statut);
                break;
            }
            default:
                printf("Tâche avec l'ID %d introuvable.\n", taskId);
                return;
            }

        }
}


int main()
{
    int choie;

    do
    {
        printf("     menu principale : \n" );
        printf("1- ajoutee nouvelle tache \n" );
        printf("2- modifier une tache \n" );
        printf("3- supprimer une tache \n" );
        printf("4- recherche une tache \n" );
        printf("5- statistique \n" );
        printf("6- afficher les taches\n" );


        printf("votre choix est : \n" );
        scanf("%d",&choie);

        switch (choie)
        {
        case 1 :
        {
            printf("ajoutee nouvelle tache \n" );
            AjouteUneTache();

            break;
        }

        break;
        case 2 :
            printf("modifier une tache \n" );
            ModificationTache ();// fonction de modification
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
        case 6 :
            printf("afficher les taches \n" );// statistique
            AfficherTache();
            break;
        default:
            printf("quitter \n" );
            break;
        }

    }
    while (choie != 0);



    return 0;

}




























