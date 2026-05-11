#include <stdio.h>
#include <string.h>

#define V 6


// ===== BFS FUNCTION =====
int bfs(int residual[V][V], int source, int sink, int parent[])
{
    int visited[V] = {0};
    int queue[V];

    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while(front < rear)
    {
        int u = queue[front++];

        for(int v = 0; v < V; v++)
        {
            if(visited[v] == 0 && residual[u][v] > 0)
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }

    return visited[sink];
}


// ===== DFS FOR MIN CUT =====
void dfs(int residual[V][V], int s, int visited[])
{
    visited[s] = 1;

    for(int v = 0; v < V; v++)
    {
        if(residual[s][v] > 0 && !visited[v])
            dfs(residual, v, visited);
    }
}


// ===== FORD FULKERSON ALGORITHM =====
void fordFulkerson(int graph[V][V], int source, int sink)
{
    int u, v;

    int residual[V][V];

    for(u = 0; u < V; u++)
    {
        for(v = 0; v < V; v++)
        {
            residual[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int maxFlow = 0;

    printf("Augmenting Paths:\n");

    
    // ===== FIND AUGMENTING PATHS =====
    while(bfs(residual, source, sink, parent))
    {
        int pathFlow = 99999;

        for(v = sink; v != source; v = parent[v])
        {
            u = parent[v];

            if(residual[u][v] < pathFlow)
                pathFlow = residual[u][v];
        }

        
        // ===== PRINT PATH =====
        printf("Path: ");

        int path[V];
        int count = 0;

        for(v = sink; v != -1; v = parent[v])
            path[count++] = v;

        for(int i = count - 1; i >= 0; i--)
        {
            printf("%d", path[i]);

            if(i != 0)
                printf(" -> ");
        }

        printf(" | Bottleneck Capacity = %d\n", pathFlow);


        // ===== UPDATE RESIDUAL GRAPH =====
        for(v = sink; v != source; v = parent[v])
        {
            u = parent[v];

            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }


    // ===== DISPLAY MAX FLOW =====
    printf("\nMaximum Flow = %d\n", maxFlow);


    // ===== FIND MIN CUT =====
    int visited[V] = {0};

    dfs(residual, source, visited);

    printf("\nSet S (Reachable Nodes): ");
    for(int i = 0; i < V; i++)
    {
        if(visited[i])
            printf("%d ", i);
    }

    printf("\nSet T (Non-Reachable Nodes): ");
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            printf("%d ", i);
    }


    // ===== DISPLAY MIN CUT EDGES =====
    printf("\n\nMin-Cut Edges:\n");

    for(u = 0; u < V; u++)
    {
        for(v = 0; v < V; v++)
        {
            if(visited[u] && !visited[v] && graph[u][v] > 0)
            {
                printf("(%d , %d)\n", u, v);
            }
        }
    }
}


// ===== MAIN FUNCTION =====
int main()
{
    int graph[V][V] = {

        {0,16,13,0,0,0},
        {0,0,10,12,0,0},
        {0,4,0,0,14,0},
        {0,0,9,0,0,20},
        {0,0,0,7,0,4},
        {0,0,0,0,0,0}

    };

    fordFulkerson(graph, 0, 5);

    return 0;
}