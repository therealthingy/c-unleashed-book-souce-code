#pragma once

#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BARR_ELTYPE;

#define BARR_ELBITS              (CHAR_BIT * sizeof(BARR_ELTYPE))
#define BARR_ARRAYSIZE(N)        (((N) + BARR_ELBITS - 1) / BARR_ELBITS)

#define BARR_MALLOC(N)           ((BARR_ELTYPE *)malloc(BARR_ARRAYSIZE(N) * sizeof(BARR_ELTYPE)))
#define BARR_REALLOC(barr, N)    ((BARR_ELTYPE *)realloc(barr, BARR_ARRAYSIZE(N) * sizeof(BARR_ELTYPE)))
#define BARR_FREE(barr)          free(barr)
#define BARR_CLEARARRAY(barr, N) memset(barr, 0, BARR_ARRAYSIZE(N) * sizeof(BARR_ELTYPE))

#define BARR_ELNUM(N)            ((N) / BARR_ELBITS)
#define BARR_BITNUM(N)           ((N) % BARR_ELBITS)

#define BARR_SET(barr, N)        ((barr)[BARR_ELNUM(N)] |= (BARR_ELTYPE)1 << BARR_BITNUM(N))
#define BARR_CLEAR(barr, N)      ((barr)[BARR_ELNUM(N)] &= ~((BARR_ELTYPE)1 << BARR_BITNUM(N)))
#define BARR_FLIP(barr, N)       ((barr)[BARR_ELNUM(N)] ^= (BARR_ELTYPE)1 << BARR_BITNUM(N))
#define BARR_TEST(barr, N)       ((barr)[BARR_ELNUM(N)] & ((BARR_ELTYPE)1 << BARR_BITNUM(N)))
