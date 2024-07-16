#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 256

int main()
{
    char buffer[MAX_LENGTH];
    char *filename = "data/baseInstance.txt";
    FILE *file = fopen(filename, "r");
    int index = 0;
    int amountOfNodes = 0;
    int *nodes;
    int *directions;

    if (file == NULL)
    {
        printf("Não foi possível encontrar o arquivo: %s", filename);
        return 1;
    }

    // Lê a primeira lina do arquivo para pegar a quantidade de nodos no grafo
    fgets(buffer, MAX_LENGTH, file);
    amountOfNodes = atoi(buffer);

    // Aloca a quantidade de elementos
    nodes = (int *)malloc(amountOfNodes * sizeof(int));
    directions = (int *)malloc(amountOfNodes * sizeof(int[2]));

    // Popula o array com os nodos
    while (fgets(buffer, MAX_LENGTH, file))
    {
        if (index < amountOfNodes)
        {
            nodes[index] = atoi(buffer);
        }
        index++;
    }

    fclose(file);

    printf("Amount of nodes = %d\n", amountOfNodes);
    printf("Nodes: ");
    for (int i = 0; i < amountOfNodes; i++)
    {
        printf("%d ", nodes[i]);
    }

    return 0;
}