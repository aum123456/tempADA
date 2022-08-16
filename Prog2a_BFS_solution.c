// USN: 1DS20CS145
// Name: Aum S. Patil
// ADA lab internal

#include <stdio.h>

void myBFS(int n, int a[10][10], int src, int s[10]) {//iterative algorithm, decrease and conquer, O(v+e)
    int q[10], f=1, r=1; //queue data structure
    int u; //stores the newest element in queue
    s[src]=1;
    q[f]=src;
    printf("%d ", src);
    while (f<=r) {
        u = q[f];
        for (int i=1; i<=n; i++) {
            if (s[i]==0 && a[i][u]==1) {
                printf("%d ", i);
                s[i]=1;
                q[++r]=i;
            }
        }
        f++;
    }
}

int main() {
    int n; //no. of nodes
    int a[10][10]; //adjacency matrix
    int src; //source node
    int s[10]={0}; //visited array to track which nodes have been visited
    int isConnected = 1; //flag integer to track connectivity of graph
    printf("No. of nodes: ");
    scanf("%d", &n);
    printf("Adj matrix: \n");
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Src: "); scanf("%d", &src);
    printf("BFS traversal: ");
    myBFS(n,a,src,s);
    printf("\n");
    for (int i=1; i<=n; i++) {
        if (s[i]==0) {
            isConnected = 0;
            break;
        }
    }
    if (isConnected) printf("Connected graph.\n");
    else printf("DisConnected graph.\n");
    return 0;
}