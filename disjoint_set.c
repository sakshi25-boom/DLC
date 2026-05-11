#include <stdio.h>

#define MAX 100

int parent[MAX];
int rankArr[MAX];
int sizeArr[MAX];


// ===== MAKE SET =====
void makeSet(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
        sizeArr[i] = 1;
    }
}


// ===== FIND WITHOUT PATH COMPRESSION =====
int findNoCompression(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}


// ===== FIND WITH PATH COMPRESSION =====
int findPathCompression(int x)
{
    if(parent[x] != x)
        parent[x] = findPathCompression(parent[x]);

    return parent[x];
}


// ===== UNION NAIVE =====
void unionNaive(int x, int y)
{
    int rx = findNoCompression(x);
    int ry = findNoCompression(y);

    if(rx != ry)
        parent[ry] = rx;
}


// ===== UNION BY RANK =====
void unionByRank(int x, int y)
{
    int rx = findPathCompression(x);
    int ry = findPathCompression(y);

    if(rx == ry)
        return;

    if(rankArr[rx] < rankArr[ry])
        parent[rx] = ry;

    else if(rankArr[rx] > rankArr[ry])
        parent[ry] = rx;

    else
    {
        parent[ry] = rx;
        rankArr[rx]++;
    }
}


// ===== UNION BY SIZE =====
void unionBySize(int x, int y)
{
    int rx = findPathCompression(x);
    int ry = findPathCompression(y);

    if(rx == ry)
        return;

    if(sizeArr[rx] < sizeArr[ry])
    {
        parent[rx] = ry;
        sizeArr[ry] += sizeArr[rx];
    }
    else
    {
        parent[ry] = rx;
        sizeArr[rx] += sizeArr[ry];
    }
}


// ===== DISPLAY PARENT ARRAY =====
void display(int n)
{
    printf("\nElement : Parent\n");

    for(int i = 1; i <= n; i++)
        printf("%d : %d\n", i, parent[i]);
}


// ===== MAIN FUNCTION =====
int main()
{
    int n = 7;

    makeSet(n);

    printf("=== Naive Union ===\n");

    unionNaive(1, 2);
    unionNaive(2, 3);
    unionNaive(4, 5);
    unionNaive(6, 7);
    unionNaive(5, 6);

    display(n);

    printf("\nFind(7) without Path Compression = %d\n",
           findNoCompression(7));

    
    // ===== RESET SETS =====
    makeSet(n);

    printf("\n=== Union by Rank + Path Compression ===\n");

    unionByRank(1, 2);
    unionByRank(2, 3);
    unionByRank(4, 5);
    unionByRank(6, 7);
    unionByRank(5, 6);

    display(n);

    printf("\nFind(7) with Path Compression = %d\n",
           findPathCompression(7));

    display(n);

    return 0;
}