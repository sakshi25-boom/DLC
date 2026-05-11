#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,1,0,1},
    {1,0,1,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1},
    {1,0,1,1,0}
};

int color[V];


// ===== CHECK SAFE COLOR =====
int isSafe(int v, int c)
{
    for(int i = 0; i < V; i++)
    {
        if(graph[v][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}


// ===== GRAPH COLORING USING BACKTRACKING =====
int graphColoring(int v, int m)
{
    if(v == V)
        return 1;

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(v, c))
        {
            color[v] = c;

            if(graphColoring(v + 1, m))
                return 1;

            
            // ===== BACKTRACK =====
            color[v] = 0;
        }
    }

    return 0;
}


// ===== MAIN FUNCTION =====
int main()
{
    int m = 3;

    if(graphColoring(0, m))
    {
        printf("Graph can be colored using %d colors\n", m);

        for(int i = 0; i < V; i++)
        {
            printf("Vertex %d ---> Color %d\n",
                   i + 1, color[i]);
        }
    }
    else
    {
        printf("Graph cannot be colored\n");
    }

    return 0;
}