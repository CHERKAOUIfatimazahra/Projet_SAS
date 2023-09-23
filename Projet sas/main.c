#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a task
struct Task
{
    int id;
    char title[50];
    char description[100];
    char deadline[12]; // Format "jj/mm/aaaa"
    char status[20];
    char creation_date[12]; // Format "jj/mm/aaaa"
};
// Maximum number of tasks
#define MAX_TASKS 100

// Tableau pour stocker les tâches
struct Task tasks[MAX_TASKS];

// Fonction pour ajouter une nouvelle tâche
int numTasks = 0;


void addTask()
{
    if (numTasks < MAX_TASKS)
    {
        struct Task newTask;
        printf("Entrez le titre de la tâche :");
        scanf("%s", newTask.title);
        printf("\n Entrez la description de la tâche :");
        scanf("%s", newTask.description);
        printf("\n Entrez la date limite de la tâche (jj/mm/aaaa) : ");
        scanf("%s", newTask.deadline);

        printf("\n Entrez le statut de la tâche :");
        scanf("%s", newTask.status);

        printf("\n Entrez la date de création de la tâche (jj/mm/aaaa) :");
        scanf("%s", newTask.creation_date);

        newTask.id = numTasks + 1; // ID unique pour la tâche

        tasks[numTasks] = newTask;
        numTasks++;

        printf("Tâche ajoutée avec succès.\n");
    }
    else
    {
        printf("Nombre maximum de tâches atteint.\n");
    }
}
// ajoutee plusieur tach
void addTasks()
{
    int N;
    printf("entree le nombre de tache a ajoutee: \n");
    scanf("%d",&N);

    for(int i = numTasks ; i< N ; i++)
        addTask();
}
// Fonction pour afficher toutes les tâches
void displayAllTasks()
{
    if (numTasks == 0)
    {
        printf("Aucune tâche à afficher.\n");
        return;
    }

    printf("Liste de toutes les tâches :\n");
    printf("ID\tTitle\tDescription\tDeadline\tStatus\tCreation Date\n");

    for (int i = 0; i < numTasks; i++)
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].deadline, tasks[i].status, tasks[i].creation_date);
    }
}
// Fonction pour modifier une tâche
void modifyTask()
{
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    int found = 0;
    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            printf("Tâche trouvée. Veuillez mettre à jour les informations :\n");
            printf("Entrez le nouveau titre de la tâche :");
            scanf("%s", tasks[i].title);
            printf("Entrez la nouvelle description de la tâche :");
            scanf("%s", tasks[i].description);
            printf("Entrez la date limite de la nouvelle tâche(jj/mm/aaaa) : ");
            scanf("%s", tasks[i].deadline);
            printf("Entrez le nouveau statut de la tâche :");
            scanf("%s", tasks[i].status);
            printf("Tâche mise à jour avec succès.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Task with ID %d not found.\n", taskId);
    }
}
// Fonction pour rechercher une tâche par ID
void searchTaskById()
{
    int taskId;
    printf("Entrez l'ID de la tâche à rechercher :");
    scanf("%d", &taskId);

    int found = 0;
    printf("Résultats de la recherche :\n");
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
        printf("Tâche avec l'ID %d introuvable.\n", taskId);
    }
}
// Fonction pour rechercher une tâche par titre
void searchTaskByTitle()
{
    char searchTitle[50];
    printf("Entrez le titre de la tâche à rechercher :");
    scanf("%s", searchTitle);

    int found = 0;
    printf("Résultats de la recherche :\n");
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
        printf("Aucune tâche avec le titre \"%s\" found.\n", searchTitle);
    }
}
// Fonction pour supprimer une tâche par ID
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
            printf("Tâche avec l'ID %d introuvable.\n", taskId);
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
// Fonction pour afficher les statistiques
void displayStatistics(){

int completedTask=0;
int incompletedTask=0;

for (int i = 0 ; i < numTasks ; i++){
    if (strcasecmp(tasks[i].status, "done") == 0)
    {
       completedTask++;
    }
    else{
        incompletedTask++;
    }

}
        printf("le nombre total des tâches : %d \n", numTasks);
        printf("le nombre de tâches complètes : %d \n", completedTask);
        printf("le nombre de tâches incomplètes : %d \n", incompletedTask);
}

int main()
{
    int Choix;

    do
    {
        printf("***********************************************************");
        printf("\nMain Menu:\n");
        printf("1. Ajouter une nouvelle tâche\n");
        printf("2. Afficher toutes les tâches\n");
        printf("3. Modifier une tâche\n");
        printf("4. Rechercher une tâche par ID\n");
        printf("5. Rechercher une tâche par titre\n");
        printf("6. Supprimer une tâche par ID\n");
        printf("7. ajoutee plusieur tache\n");
        printf("8. Afficher les statistiques\n");
        printf("0. Quitter\n");

        printf("***********************************************************\n");
        printf("Choix: ");
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
        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    }
    while (Choix != 0);

    return 0;
}























