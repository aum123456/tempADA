#include <stdio.h>

void kruskal(int cost[20][20], int n) {
    int parent[20] = {
        0
    }, min, mincost = 0, ne = 1;
    int a, b, i, j, u, v;
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        if (u != v) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost = mincost + min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The Minimum Wiring Cost = %d\n", mincost);
}
int main() {
    int n, i, j, cost[20][20];
    printf("Enter the no. of Nodes\n");
    scanf("%d", & n);
    printf("Enter the Cost Adjacency Matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", & cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    kruskal(cost, n);
    return 0;
}