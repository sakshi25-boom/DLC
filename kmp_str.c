#include <stdio.h>
#include <string.h>


// ===== COMPUTE LPS ARRAY =====
void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;

    lps[0] = 0;

    int i = 1;

    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;

            lps[i] = len;

            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


// ===== KMP STRING MATCHING =====
void KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;

    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            printf("Pattern found at index %d\n", i - j);

            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}


// ===== MAIN FUNCTION =====
int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMP(text, pattern);

    return 0;
}