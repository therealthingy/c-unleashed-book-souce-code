#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"
#include "topsort.h"

int main(void) {
    struct Graph *G;
    int i;
    int Index;
    int *res;

    /* make a graph */
    G = MakeGraph(Matrix);
    if (!G) {
        puts("failed to make graph");
        exit(0);
    }

    puts("Graph made");

    /* add some nodes */
    for (i = 0; i < 8; i++) {
        Index = AddVertex(G);
        if (Index < 0) {
            puts("failed to add vertex");
            exit(0);
        }
        printf("%d added\n", i);
        G->Vertices[Index]->Tag.Num = Index;
        puts("tag set");
    }

    /* make some edges */

    i = ConnectVertex(G, 2, 6, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 2, 0, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 5, 0, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 5, 3, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 6, 4, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 0, 7, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 3, 7, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 4, 1, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    i = ConnectVertex(G, 7, 1, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("Edges done");

    i = TopologicalSort(G, &res);
    printf("i=%d\n\n", i);
    if (i != 0)
        exit(0);

    for (i = 0; i < G->NumVertices; i++) {
        printf("%d", res[i]);
    }

    FreeGraph(G);

    return 0;
}
