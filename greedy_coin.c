#include <stdio.h>

int main()
{
    int amount, i, count = 0;

    // Available denominations
    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = 10;

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Minimum notes/coins required:\n");

    // Greedy Approach
    for(i = 0; i < n; i++)
    {
        if(amount >= notes[i])
        {
            int num = amount / notes[i];

            printf("%d x %d\n", notes[i], num);

            amount = amount % notes[i];
            count += num;
        }
    }

    printf("Total notes/coins = %d\n", count);

    return 0;
}