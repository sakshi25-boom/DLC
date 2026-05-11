#include <stdio.h>
#include <string.h>


// ===== NAIVE STRING MATCHING =====
void naiveMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    for(int i = 0; i <= n - m; i++)
    {
        int j;

        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}


// ===== MAIN FUNCTION =====
int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    naiveMatch(text, pattern);

    return 0;
}