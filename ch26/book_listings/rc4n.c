// RC4 demo;   NOT part of the book !
// TODO:
//   - Accept "binary data" input (cipher-, plain text, key) via stdin  (i.e., no CLI)
//   - Add option 2 choose: Encrypt / Decrypt
//   - ENCRYPTION seems 2 be non-deterministic ?!?!111

#include "byteorder.h"
#include <limits.h>
#include <rc4.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DERIVED FROM: https://gist.github.com/ccbrown/9722406
void fprint_data_hex_ascii(FILE *const stream,    //
                           const void *const data, size_t data_bytes) {
    const size_t NHEXCOLS_PER_ROW = 16;
    char buf_col_ascii_repr[NHEXCOLS_PER_ROW + 1];
    buf_col_ascii_repr[NHEXCOLS_PER_ROW] = '\0';
    for (size_t data_idx = 0; data_idx < data_bytes; ++data_idx) {
        // Print byte as 2 hex 'digits'
        fprintf(stream, "%02X ", ((unsigned char *)data)[data_idx]);
        // Printable char ?
        buf_col_ascii_repr[data_idx % NHEXCOLS_PER_ROW] =
            (((char *)data)[data_idx] >= ' ' && ((char *)data)[data_idx] <= '~') ? ((char *)data)[data_idx] : '.';

        // Reached middle/last 'hex col'  OR  end of `data` ?
        if ((data_idx + 1) % (NHEXCOLS_PER_ROW / 2) == 0 || data_idx + 1 == data_bytes) {
            fprintf(stream, " ");

            // Last 'hex col'? -> Print ASCII representation
            if ((data_idx + 1) % NHEXCOLS_PER_ROW == 0)
                fprintf(stream, "|  %s \n", buf_col_ascii_repr);

            // Reached end of `data`?
            else if (data_idx + 1 == data_bytes) {
                // Center 'double' space
                if ((data_idx + 1) % NHEXCOLS_PER_ROW <= 8)
                    fprintf(stream, " ");

                // "Fill out" missing 'hex cols' in current row
                for (size_t j = (data_idx + 1) % NHEXCOLS_PER_ROW; j < NHEXCOLS_PER_ROW; ++j)
                    fprintf(stream, "   ");

                buf_col_ascii_repr[(data_idx + 1) % NHEXCOLS_PER_ROW] = '\0';
                // Print ASCII representation
                fprintf(stream, "|  %s \n", buf_col_ascii_repr);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s string [key]\n", argv[0]);
        return 1;
    }

    {
        // setup key
        RC4_key_t key;
        {
            const byte_t *const key_bytes = (const byte_t *)(argc == 3 ? argv[2] : "enjoy the silence");
            const size_t key_len_bytes =
                strlen((const char *)key_bytes);    // gets treated as binary data (i.e., NUL byte is irrelevant)
            if (!(key_len_bytes * CHAR_BIT >= 40 && key_len_bytes * CHAR_BIT <= 2048)) {
                fprintf(stderr, "Key sizes b/w 40-2048 bits are allowed\n");
                return 1;
            }

            printf("Key (%zu bits):\n", key_len_bytes * CHAR_BIT);
            fprint_data_hex_ascii(stdout, key_bytes, key_len_bytes);
            puts("");

            RC4_setup_key(key_bytes, key_len_bytes, &key);
        }

        // encrypt
        const byte_t *const plaintext =
            (const byte_t *)argv[1];    // gets treated as binary data (i.e., NUL byte is irrelevant)
        const size_t length = strlen(argv[1]);

        byte_t *ciphertext = calloc(length, sizeof(*ciphertext));
        RC4_encrypt(plaintext, ciphertext, length, &key);

        // print results
        puts("Plain text:");
        fprint_data_hex_ascii(stdout, plaintext, length);
        puts("\nCipher text:");
        fprint_data_hex_ascii(stdout, ciphertext, length);
        free(ciphertext);
    }

    return 0;
}
