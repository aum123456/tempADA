#include <stdio.h>

int BellmanFord(int G[20][20], int n, int E, int edge[20][2]) {
    int i, u, v, k, distance[20], parent[20], S, flag = 1;
    for (i = 0; i < n; i++) {
        distance[i] = 1000;
        parent[i] = -1;
    }
    printf("Enter Source\n");
    scanf("%d", & S);
    printf("Shortest Path from Source %d:\n", S);
    distance[S - 1] = 0;
    for (i = 0; i < n - 1; i++) {
        for (k = 0; k < E; k++) {
            u = edge[k][0];
            v = edge[k][1];
            if (distance[u] + G[u][v] < distance[v]) {
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }
    for (k = 0; k < E; k++) {
        u = edge[k][0];
        v = edge[k][1];
        if (distance[u] + G[u][v] < distance[v])
            flag = 0;
    }
    if (flag)
        for (i = 0; i < n; i++)
            printf("Vertex %d -> Cost = %d Parent = %d\n", i + 1, distance[i], parent[i] + 1);
    return flag;
}
int main() {
    int n, edge[20][2], G[20][20], i, j, k = 0;
    printf("Enter no. of Nodes in Graph\n");
    scanf("%d", & n);
    printf("Enter Cost Adjacency Matrix of Graph\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", & G[i][j]);
            if (G[i][j] != 0) {
                edge[k][0] = i;
                edge[k++][1] = j;
            }
        }
    if (BellmanFord(G, n, k, edge))
        printf("No negative weight cycle\n");
    else
        printf("Negative weight cycle exists\n");
    return 0;
}