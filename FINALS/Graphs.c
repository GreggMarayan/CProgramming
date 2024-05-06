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




GRAPH prims(MATRIX);
GRAPH kruskal(MATRIX);

int main(void) {
    MATRIX MAIN = { {Z, 1,  5,  4,  6,  5},
                    {1, Z,  5,  Z,  Z,  6},
                    {5, 5,  Z,  2,  Z,  Z},
                    {4, Z,  2,  Z,  1,  Z},
                    {6, Z,  Z,  1,  Z,  3},
                    {5, 6,  Z,  Z,  3,  Z} };

    GRAPH ror = kruskal(MAIN);
    GRAPH rar = prims(MAIN);
    printf("%d = %d", ror.TotalCost,rar.TotalCost);

    // printf("%d",prims(MAIN));

    return 0;
}

// int prims(MATRIX graph) {
//     int totalCost = 0;
//     SET visited = { 0 }; // Initialize visited array

//     // Start from vertex 0
//     visited[A] = 1;

//     // Number of edges to be added to the MST
//     int edgeCount = 0;

//     // Repeat until all vertices are visited
//     while (edgeCount < MAX - 1) {
//         int minWeight = Z;
//         int minVertex = -1;

//         // Find the minimum weight edge from a vertex in the MST to a vertex outside the MST
//         for (int i = 0; i < MAX; ++i) {
//             if (visited[i]) {
//                 for (int j = 0; j < MAX; ++j) {
//                     if (!visited[j] && graph[i][j] < minWeight) {
//                         minWeight = graph[i][j];
//                         minVertex = j;
//                     }
//                 }
//             }
//         }

//         // Add the minimum weight edge to the MST
//         totalCost += minWeight;
//         visited[minVertex] = 1;
//         edgeCount++;
//     }

//     return totalCost;
// }

GRAPH prims(MATRIX main){
    GRAPH retval = {.TotalCost = 0};
    int SET[MAX] = {1,0,0,0,0,0};
    int edgeCTR = 0, head, end;

    while(edgeCTR < MAX-1){
        int small = Z, u  = 0, v = 0;
        for(head = 0; head < MAX; head++){
            if(SET[head]){
                for(end = 0; end < MAX; ++end){
                    if(SET[end] != 1 && main[head][end] < small){
                        small = main[head][end];
                        u = head;
                        v = end;
                    }
                }
            }
        }
        SET[v] = 1;

        if(small != Z){
            retval.M[u][v] = small;
            retval.TotalCost += small;
        }
     edgeCTR++;
    }
    return retval;
}











GRAPH kruskal(MATRIX main){

    int small, smallndy, smallndx, edgeCTR = 0;
    GRAPH retval = {.TotalCost = 0};

    int SET[MAX];
    for(int ndx = 0; ndx < MAX; ndx++){
        SET[ndx] = -1;
    }

    while(edgeCTR < MAX-1){
        small = Z;

        //finds smallest edge amoang the graph
        for(int ndx = 0; ndx < MAX; ndx++){
            for(int ndy = ndx; ndy < MAX; ndy++){
                if(retval.M[ndx][ndy] != main[ndx][ndy] && main[ndx][ndy] < small){
                    small = main[ndx][ndy];
                    smallndx = ndx;
                    smallndy = ndy;
                }
            }
        }

        //checks if the 2 vertexes are different components
        int tempx = smallndx, tempy = smallndy;
        for(;SET[tempx] > 0;tempx = SET[tempx]){}
        for(;SET[tempy] > 0;tempy = SET[tempy]){}


        //Adds the info to the graph if it is not in the same component
        if(tempx != tempy){
            retval.TotalCost += small;
            retval.M[smallndx][smallndy] = retval.M[smallndy][smallndx] = small;
            edgeCTR++;

        //removes the vertex from main graph;
            // main[smallndx][smallndy] = Z;

        //Updates the Disjoint Set SET[]
            SET[smallndx] += SET[smallndy];
            SET[smallndy] = smallndx;
        }
    }
    return retval;
}


