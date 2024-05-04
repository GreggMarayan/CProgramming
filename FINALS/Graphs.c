#include <stdio.h>
#include <limits.h>

#define MAX 6
#define Z INT_MAX

enum { A, B, C, D, E, F };

typedef int MATRIX[MAX][MAX];

typedef struct {
    MATRIX M;
    int TotalCost;
} GRAPH;

typedef int SET[MAX];

int prims(MATRIX);
int kruskal(MATRIX);

int main(void) {
    MATRIX MAIN = { {Z, 1,  5,  4,  6,  5},
                    {1, Z,  5,  Z,  Z,  6},
                    {5, 5,  Z,  2,  Z,  Z},
                    {4, Z,  2,  Z,  1,  Z},
                    {6, Z,  Z,  1,  Z,  3},
                    {5, 6,  Z,  Z,  3,  Z} };

    prims(MAIN);

    printf("%d",prims(MAIN));

    return 0;
}

int prims(MATRIX graph) {
    int totalCost = 0;
    SET visited = { 0 }; // Initialize visited array

    // Start from vertex 0
    visited[A] = 1;

    // Number of edges to be added to the MST
    int edgeCount = 0;

    // Repeat until all vertices are visited
    while (edgeCount < MAX - 1) {
        int minWeight = Z;
        int minVertex = -1;

        // Find the minimum weight edge from a vertex in the MST to a vertex outside the MST
        for (int i = 0; i < MAX; ++i) {
            if (visited[i]) {
                for (int j = 0; j < MAX; ++j) {
                    if (!visited[j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        minVertex = j;
                    }
                }
            }
        }

        // Add the minimum weight edge to the MST
        totalCost += minWeight;
        visited[minVertex] = 1;
        edgeCount++;
    }

    return totalCost;
}


int kruskal(MATRIX graph){
    int retval = 0;
    int ndx,ind, min_w, min_x, min_y;
    int edgeCTR = 0;
    MATRIX MST;
    for(ndx = 0; ndx < MAX; ndx++){
        for(ind = 0; ind < MAX; ind++){
            MST[ndx][ind] = Z;
        }
    }

    SET parent;
    for(ndx = 0; ndx < MAX; ndx++){
        parent[ndx] = ndx;
    }

    while (edgeCTR < MAX - 1)   
    {

        //searching for the smallest weighted edge.
        min_w = Z;
        for(ndx = 0; ndx < MAX; ndx++){
            for(ind = ndx + 1; ind < MAX; ind++){
                if(graph[ndx][ind] < min_w){
                    min_w = graph[ndx][ind];
                    min_x = ndx;
                    min_y = ind;
                }
            }
        }

        //checking if the found smallest edge would create a cycle
        int x,y;
        for(x = min_x, y = min_y; (parent[x] != x) || (parent[y] != y); x = parent[x], y = parent[y]){}


        //if it doesnt create a cycle then add the two segments together
        if(x != y){
            retval += min_w;
            MST[x][y] = min_w;
            edgeCTR++;
            // Union operation in disjoint set
            parent[y] = x;
        }

        // Mark this edge as visited
        graph[min_x][min_y] = graph[min_y][min_x] = Z;
    }

    return retval;
}