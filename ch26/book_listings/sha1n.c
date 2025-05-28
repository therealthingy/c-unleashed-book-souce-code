// SHA-1 demo;   NOT part of the book !
#include <sha1.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"string\"\n", argv[0]);
        goto err;
    }

    uint32_t digest[5];
    if (0 != SHA_1_full((const byte_t *)argv[1], (uint64_t)strlen(argv[1]), digest)) {
        printf("%08x%08x%08x%08x%08x\n", digest[0], digest[1], digest[2], digest[3], digest[4]);
        return 0;
    }

err:
    return 1;
}
