#include <stdio.h>

#define INF 99999


// ===== MAIN FUNCTION =====
int main()
{
    int n, amount;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];


    // ===== INITIALIZE DP ARRAY =====
    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
        dp[i] = INF;


    // ===== DYNAMIC PROGRAMMING APPROACH =====
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                if(dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }


    // ===== DISPLAY RESULT =====
    if(dp[amount] == INF)
        printf("Not Possible\n");
    else
        printf("Minimum coins required = %d\n", dp[amount]);

    return 0;
}