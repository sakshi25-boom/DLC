#include <stdio.h>
#include <limits.h>

#define MAX 20

int n;
int dist[MAX][MAX];
int visited[MAX];


// ===== FIND NEAREST CITY =====
int findNearest(int current)
{
    int i;
    int min = INT_MAX;
    int index = -1;

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && dist[current][i] < min)
        {
            min = dist[current][i];
            index = i;
        }
    }

    return index;
}


// ===== TSP USING NEAREST NEIGHBOR =====
void tsp()
{
    int i;
    int current = 0;
    int next;
    int totalCost = 0;

    
    // ===== INITIALIZE VISITED ARRAY =====
    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[current] = 1;

    printf("Path: %d ", current);


    // ===== FIND TOUR =====
    for(i = 1; i < n; i++)
    {
        next = findNearest(current);

        if(next == -1)
            break;

        visited[next] = 1;

        printf("-> %d ", next);

        totalCost += dist[current][next];

        current = next;
    }


    // ===== RETURN TO START CITY =====
    totalCost += dist[current][0];

    printf("-> %d", 0);


    // ===== DISPLAY TOTAL COST =====
    printf("\nTotal Cost = %d\n", totalCost);
}


// ===== MAIN FUNCTION =====
int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    tsp();

    return 0;
}