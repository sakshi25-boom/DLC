#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5


// ===== EDGE STRUCTURE =====
struct Edge
{
    int u, v, w;
};

int parent[V];


// ===== FIND FUNCTION =====
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}


// ===== UNION FUNCTION =====
void unionSet(int x, int y)
{
    parent[find(y)] = find(x);
}


// ===== COMPARE EDGES =====
int compare(const void *a, const void *b)
{
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}


// ===== KRUSKAL'S ALGORITHM =====
void kruskal(struct Edge edges[])
{
    qsort(edges, E, sizeof(edges[0]), compare);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0;

    printf("Edges in MST:\n");

    for(int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find(u) != find(v))
        {
            printf("%d - %d  Weight = %d\n", u, v, w);

            total += w;

            unionSet(u, v);
        }
    }

    printf("Total Minimum Cost = %d\n", total);
}


// ===== MAIN FUNCTION =====
int main()
{
    struct Edge edges[E] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    kruskal(edges);

    return 0;
}