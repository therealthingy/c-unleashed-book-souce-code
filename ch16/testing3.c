#include <limits.h>
#include <stdio.h>

#define INF INT_MAX

int main(void) {

    int i, j, k;
    int R[4][4] = {
        {  0,  -1, INF,   2},
        {INF,   0,   2, INF},
        {  4, INF,   0,   3},
        {INF,   1, INF,   0}
    };

    for (k = 0; k < 4; k++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (R[i][k] == INF || R[k][j] == INF)
                    continue;
                R[i][j] = (R[i][j] > R[i][k] + R[k][j]) ? R[i][k] + R[k][j] : R[i][j];
            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (R[i][j] != INF)
                    printf("%d -> %d = %d\n", i, j, R[i][j]);
                else
                    printf("%d -> %d = !\n", i, j);
            }
        }
    }

    return 0;
}
