#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a task*****************************************************************************************************
struct Task
{
    int id;
    char title[50];
    char description[100];
    char deadline[12]; // Format "jj/mm/aaaa"
    char status[20];
    char creation_date[12]; // Format "jj/mm/aaaa"
};
// Maximum number of tasks**************************************************************************************************
#define MAX_TASKS 100

// Tableau pour stocker les tâches******************************************************************************************
struct Task tasks[MAX_TASKS];

// Fonction pour ajouter une nouvelle tâche*********************************************************************************
int numTasks = 0;
void addTask()
{
    if (numTasks < MAX_TASKS)
    {
        struct Task newTask;
        printf("Entrez le titre de la tache :");
        scanf("%s", newTask.title);
        printf("\nEntrez la description de la tache :");
        scanf("%s", newTask.description);
        printf("\nEntrez la date limite de la tache (jj/mm/aaaa) : ");
        scanf("%s", newTask.deadline);

        printf("\nEntrez le statut de la tache :");
        scanf("%s", newTask.status);

        printf("\nEntrez la date de creation de la tache (jj/mm/aaaa) :");
        scanf("%s", newTask.creation_date);

        newTask.id = numTasks + 1; // ID unique pour la tâche

        tasks[numTasks] = newTask;
        numTasks++;

        printf("Tache ajoutee avec succes.\n");
    }
    else
    {
        printf("Nombre maximum de taches atteint.\n");
    }
}
// ajoutee plusieur tache*****************************************************************************************************
void addTasks()
{
    int N;
    printf("entree le nombre de tache a ajoutee: \n");
    scanf("%d",&N);

    for(int i = numTasks ; i< N ; i++)
        addTask();
}
// Fonction pour afficher toutes les tâches********************************************************************************
void displayAllTasks()
{
    if (numTasks == 0)
    {
        printf("Aucune tache a afficher.\n");
        return;
    }
    printf("Liste de toutes les taches :\n");
    printf("ID\tTitle\tDescription\tDeadline\tStatus\tCreation Date\n");

    for (int i = 0; i < numTasks; i++)
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
    }
//**********************************************************************************************************************
    int Choix;
    do
    {
        printf("***********************************************************************\n");
        printf("1. les taches par ordre alphabetique.\n");
        printf("2. les taches par deadline.\n");

        printf("0. Quitter\n");

        printf("Choix: ");
        scanf("%d", &Choix);
        printf("***********************************************************************");
        switch (Choix)
        {
        case 1:
            order_alpha();
            break;
        case 2:
            sortByDeadline();
            break;
        }
    }
    while (Choix != 0);
}
// Fonction pour modifier une tâche*****************************************************************************************
void modifyTask()
{
    int taskId;
    printf("Saisissez l'ID de la tache a modifier: ");
    scanf("%d", &taskId);

    int found = 0;
    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            printf("Tache trouvee. Veuillez mettre a jour les informations :\n");
            printf("Entrez le nouveau titre de la tache :");
            scanf("%s", tasks[i].title);
            printf("Entrez la nouvelle description de la tache :");
            scanf("%s", tasks[i].description);
            printf("Entrez la date limite de la nouvelle tache(jj/mm/aaaa) : ");
            scanf("%s", tasks[i].deadline);
            printf("Entrez le nouveau statut de la tache :");
            scanf("%s", tasks[i].status);
            printf("Tache mise a jour avec succes.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Tache avec l'ID %d introuvable.\n", taskId);
    }
}
// Fonction pour rechercher une tâche par ID********************************************************************************
void searchTaskById()
{
    int taskId;
    printf("Entrez l'ID de la tache a rechercher :");
    scanf("%d", &taskId);

    int found = 0;
    printf("Resultats de la recherche :\n");
    printf("ID\tTitle\tDescription\tDeadline\tStatus\tCreation Date\n");
    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Tache avec l'ID %d introuvable.\n", taskId);
    }
}
// Fonction pour rechercher une tâche par titre*****************************************************************************
void searchTaskByTitle()
{
    char searchTitle[50];
    printf("Entrez le titre de la tache a rechercher :");
    scanf("%s", searchTitle);

    int found = 0;
    printf("Resultats de la recherche :\n");
    printf("ID\tTitle\tDescription\tDeadline\tStatus\tCreation Date\n");
    for (int i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].title, searchTitle) == 0)
        {
            printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Aucune tache avec le titre \"%s\" found.\n", searchTitle);
    }
}
// Fonction pour supprimer une tâche par ID*********************************************************************************
void deleteTaskById()
{
    int taskId,found = 0;
    printf("entree ID que vous vouler le supprimer: ");
    scanf("%d", &taskId);

    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            found = 1;
        }
        if (!found)
        {
            printf("Tache avec l'ID %d introuvable.\n", taskId);
        }
    }
    if(found==1)
    {
        for (int i = taskId ; i < numTasks; i++)
        {
            tasks[i] =  tasks[i + 1];
        }
        numTasks = numTasks - 1;
    }
}
// Fonction pour afficher les statistiques**********************************************************************************
void displayStatistics()
{
    int completedTask=0;
    int incompletedTask=0;

    for (int i = 0 ; i < numTasks ; i++)
    {
        if (strcasecmp(tasks[i].status, "done") == 0)
        {
            completedTask++;
        }
        else
        {
            incompletedTask++;
        }
    }
    printf("le nombre total des taches : %d \n", numTasks);
    printf("le nombre de taches completes : %d \n", completedTask);
    printf("le nombre de taches incompletes : %d \n", incompletedTask);
}
//**************************************************************************************************************************
int main()
{
    int Choix;
    do
    {
        printf("***********************************************************");
        printf("\nMenu\n\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Rechercher une tache par ID\n");
        printf("5. Rechercher une tache par titre\n");
        printf("6. Supprimer une tache par ID\n");
        printf("7. ajoutee plusieur tache\n");
        printf("8. Afficher les statistiques\n");
        printf("0. Quitter\n");

        printf("***********************************************************\n");
        printf("\nChoix: ");
        scanf("%d", &Choix);

        switch (Choix)
        {
        case 1:
            addTask();
            break;
        case 2:
            displayAllTasks();
            break;
        case 3:
            modifyTask();
            break;
        case 4:
            searchTaskById();
            break;
        case 5:
            searchTaskByTitle();
            break;
        case 6:
            deleteTaskById();
            break;
        case 7:
            addTasks();
            break;
        case 8:
            displayStatistics();
            break;
        case 9:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
    while (Choix != 0);

    return 0;
}
//**************************************************************************************************************************
//affichage par ordere alphabétique
void order_alpha()
{
    struct Task tmp;
    for(int i=0; i<numTasks; i++)
    {
        for(int j=i+1; j<numTasks ; j++)
        {
            if(strcmp(tasks[i].title,tasks[j].title)>0)
            {
                tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
        // affichage par ordre
        printf("Liste de toutes les taches :\n");
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
    }
}
//deadline
void sortByDeadline()
{
    for (int i = 0; i < numTasks - 1; i++)
    {
        for (int j = i + 1; j < numTasks ; j++)
        {
            if (strcmp(tasks[i].deadline, tasks[j].deadline) > 0)
            {
                // Swap tasks
                struct Task temp = tasks[j];
                tasks[j] = tasks[i];
                tasks[i] = temp;
            }
        }
        // affichage par ordre
        printf("Taches triees par date limite.\n");
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
    }
}
// Fonction pour afficher les tâches avec des délais sous 3 jours







