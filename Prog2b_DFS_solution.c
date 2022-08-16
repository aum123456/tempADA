// USN: 1DS20CS145
// Name: Aum S. Patil
// ADA lab internal

#include <stdio.h>

void myDFS(int n, int a[10][10], int src, int s[10]) {
    s[src] = 1;
    printf("%d ", src);
    for (int i=1; i<=n; i++) {
        if (s[i]==0 && a[src][i]==1) myDFS(n, a, i, s);
    }
}

int main() {
    //----------------declaring variables-----------------

    int n; //no. of nodes
    int a[10][10]; //adjacency matrix
    int src; //source node
    int s[10] = {0}; //visited array
    printf("No. of nodes: ");
    scanf("%d", &n);

    //----------------input adjacency matrix from user-----------------
    printf("Adjacency matrix: \n");
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //-----------------------------------------------------------------
    printf("Src: ");
    scanf("%d", &src);
    printf("DFS traversal order: ");
    myDFS(n,a,src,s);
    printf("\n");

    return 0;
}

// decrease and conquer
// O(v+e)
// recursive
