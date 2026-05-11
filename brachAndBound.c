#include <stdio.h>

#define N 3

int cost[N][N] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int assigned[N] = {0};
int minCost = 99999;


// ===== BRANCH AND BOUND FUNCTION =====
void assignJob(int worker, int currentCost)
{
    if(worker == N)
    {
        if(currentCost < minCost)
            minCost = currentCost;

        return;
    }

    for(int job = 0; job < N; job++)
    {
        if(!assigned[job])
        {
            assigned[job] = 1;

            int newCost = currentCost + cost[worker][job];

            
            // ===== PRUNING CONDITION =====
            if(newCost < minCost)
            {
                assignJob(worker + 1, newCost);
            }

            
            // ===== BACKTRACK =====
            assigned[job] = 0;
        }
    }
}


// ===== MAIN FUNCTION =====
int main()
{
    assignJob(0, 0);

    printf("Minimum Assignment Cost = %d\n", minCost);

    return 0;
}