#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"
#include "shpath.h"

int main(void) {
    struct Graph *G;
    int i;
    int Index;
    struct Dijkstra_Table T;

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

    puts("1");
    i = ConnectVertex(G, 1, 2, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("2");
    i = ConnectVertex(G, 1, 4, 2);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("4");
    i = ConnectVertex(G, 2, 5, -3);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("5");
    i = ConnectVertex(G, 4, 6, 1);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("7");
    i = ConnectVertex(G, 6, 7, 3);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("8");
    i = ConnectVertex(G, 5, 7, 2);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("9");
    i = ConnectVertex(G, 3, 2, 5);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("12");
    i = ConnectVertex(G, 6, 3, 2);
    if (i) {
        puts("FAILED!");
        exit(0);
    }

    puts("14");

    Dijkstra_InitTable(&T);

    if (Bellman(G, 1, &T)) { /* some error handling */
        puts("Error! Failed to perform Dijkstra's algorithm!\n");
        exit(0);
    }
    puts("Beldone");

    for (i = 1; i < 8; i++) {
        printf("%d %d %d\n", i, T.Results[i].Total, T.Results[i].Previous);
    }

    Dijkstra_FreeTable(&T); /* free the results from within the table (does not free T, just T->Results) */

    puts("Freed");

    FreeGraph(G);

    return 0;
}
