#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"
#include "mstree.h"

int main(void) {
    struct Graph *G;
    struct Graph *T;
    int i;
    int Index;
    struct EdgeScan E;

    /* make a graph */
    G = MakeGraph(Matrix);
    if (!G) {
        puts("failed to make graph");
        exit(0);
    }

    puts("Graph made");

    /* add some nodes */
    for (i = 0; i < 7; i++) {
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

    ConnectVertex(G, 0, 1, 8);
    ConnectVertex(G, 0, 2, 6);
    ConnectVertex(G, 0, 5, 7);

    ConnectVertex(G, 1, 0, 8);
    ConnectVertex(G, 1, 2, 3);
    ConnectVertex(G, 1, 3, 2);

    ConnectVertex(G, 2, 0, 6);
    ConnectVertex(G, 2, 1, 3);
    ConnectVertex(G, 2, 4, 5);

    ConnectVertex(G, 3, 1, 2);
    ConnectVertex(G, 3, 4, 6);

    ConnectVertex(G, 4, 2, 5);
    ConnectVertex(G, 4, 3, 6);
    ConnectVertex(G, 4, 5, 1);
    ConnectVertex(G, 4, 6, 2);

    ConnectVertex(G, 5, 0, 7);
    ConnectVertex(G, 5, 4, 1);
    ConnectVertex(G, 5, 6, 4);

    ConnectVertex(G, 6, 4, 2);
    ConnectVertex(G, 6, 5, 4);

    for (i = 0; i < 7; i++) {
        EdgeScanStart(G, i, &E);
        while (!EdgeScanNext(&E))
            printf("%d ", E.Dest);
        EdgeScanEnd(&E);
        printf("\n");
    }

    printf("About to prim...\n");

    i = Prim_Undirected(G, &T);
    printf("prim done... \n");
    if (i) {
        printf("error %d\n", i);
        exit(0);
    }

    for (i = 0; i < 7; i++) {
        EdgeScanStart(T, i, &E);
        while (!EdgeScanNext(&E))
            printf("%d ", E.Dest);
        EdgeScanEnd(&E);
        printf("\n");
    }

    FreeGraph(G);

    return 0;
}
