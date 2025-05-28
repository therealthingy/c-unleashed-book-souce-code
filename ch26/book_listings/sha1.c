// "The SHA-1 Padding Function", p. 1183

#include "sha1.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

void SHA_1_pad_msg(uint32_t *padded, uint64_t num_blocks, byte_t const *unpadded, uint64_t len) {
    uint64_t zeros;
    uint64_t extra_len;
    uint64_t p_len;
    uint64_t i;
    byte_t *b_ptr;

    b_ptr = (byte_t *)padded;

    p_len = num_blocks * 64;

    extra_len = p_len - len;

    memset(b_ptr + len, 0, extra_len);

    memcpy(padded, unpadded, len);

    zeros = extra_len - 8;
    if (zeros > 0) {
        --zeros;
        for (i = 0; i < zeros; i++) {
            b_ptr[p_len - i - 9] = 0;
        }
        b_ptr[p_len - i - 9] = 0x80;
    }

    /* big endian to native byte order */
    native_byte_order32(padded, len / 4 + 1);

    /* End with message length */
    padded[num_blocks * 16 - 2] = len >> 29;
    padded[num_blocks * 16 - 1] = len << 3;
}

// "An Implementation of the SHA-1 Algorithm", p. 1184
/*
 * Declare type SHA_1_F as a pointer to a function
 * operating on three 32-bit words.
 */
typedef uint32_t (*SHA_1_F)(uint32_t a, uint32_t b, uint32_t c);

uint32_t SHA_1_F0(uint32_t a, uint32_t b, uint32_t c) {
    return c ^ a & (b ^ c);
}

/* Same function for F1() and F3() */
uint32_t SHA_1_F1F3(uint32_t a, uint32_t b, uint32_t c) {
    return a ^ b ^ c;
}

uint32_t SHA_1_F2(uint32_t a, uint32_t b, uint32_t c) {
    return a & b | c & (a | b);
}

uint32_t SHA_1_rot(uint32_t x, int n) {
    return x << n | x >> 32 - n;
}

void SHA_1_main(uint32_t const msg[16], uint32_t digest[5]) {
    uint32_t const K[4] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};

    /* The 4 SHA-1 F functions */
    SHA_1_F const F[4] = {&SHA_1_F0, &SHA_1_F1F3, &SHA_1_F2, &SHA_1_F1F3};

    uint32_t table[80];
    uint32_t offset[5];
    uint32_t temp;
    int i, j;

    /* Initialize offset */
    for (i = 0; i < 5; i++) {
        offset[i] = digest[i];
    }

    /* Initialize table */
    for (i = 0; i < 16; i++) {
        table[i] = msg[i];
    }
    for (; i < 80; i++) {
        table[i] = SHA_1_rot(table[i - 3] ^ table[i - 8] ^ table[i - 14] ^ table[i - 16], 1);
    }

    /* Calculate digest offset */
    for (j = 0, i = 0; j < 4; j++) {
        for (; i < j * 20 + 20; i++) {
            temp = SHA_1_rot(offset[0], 5) + (*F[j])(offset[1], offset[2], offset[3]) + offset[4] + table[i] + K[j];
            offset[4] = offset[3];
            offset[3] = offset[2];
            offset[2] = SHA_1_rot(offset[1], 30);
            offset[1] = offset[0];
            offset[0] = temp;
        }
    }

    /* Update digest */
    for (i = 0; i < 5; i++) {
        digest[i] += offset[i];
    }
}

/* Returns 0 on error */
int SHA_1_full(byte_t const *msg, uint64_t len, uint32_t digest[5]) {
    uint32_t const origin[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    uint32_t *padded;
    uint64_t num_blocks;
    uint64_t i;

    /* Pad msg out to 512-bit blocks */
    num_blocks = (len + 8) * 8 / 512 + 1;
    padded = (uint32_t *)malloc(num_blocks * 64);
    if (padded == NULL) {
        errno = ENOMEM;
        return 0;
    }
    SHA_1_pad_msg(padded, num_blocks, msg, len);

    /* Initialize digest */
    for (i = 0; i < 5; i++) {
        digest[i] = origin[i];
    }

    /* Hash digest with each block */
    for (i = 0; i < num_blocks; i++) {
        SHA_1_main(padded + i * 16, digest);
    }

    free(padded);

    return 1;
}
