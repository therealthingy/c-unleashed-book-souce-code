// SEE p. 1179

#include "rc4.h"

/* called before encryption/decryption */
void RC4_setup_key(byte_t const key_text[], size_t len, RC4_key_t *key) {
    int i;
    byte_t temp, e;

    /* Initialize key table */
    for (i = 0; i < 256; i++)
        key->table[i] = i;

    /* Initialize indices */
    key->index[0] = 0;
    key->index[1] = 0;

    /* Prepare key table */
    for (i = 0, e = 0; i < 256; i++) {
        /* Find e index */
        e += key_text[i % len] + key->table[i];

        /* Exchange values */
        temp = key->table[i];
        key->table[i] = key->table[e];
        key->table[e] = temp;
    }
}
/* You can encrypt and decrypt with this function */
void RC4_encrypt(byte_t const plaintext[], byte_t ciphertext[], size_t len, RC4_key_t *key) {
    int i;
    byte_t temp;

    for (i = 0; i < len; i++) {
        /* Update indices */
        key->index[1] += key->table[++key->index[0]];

        /* Swap table entries */
        temp = key->table[key->index[0]];
        key->table[key->index[0]] = key->table[key->index[1]];
        key->table[key->index[1]] = temp;

        /* Create ciphertext (Output Feedback Mode) */
        ciphertext[i] = plaintext[i] ^ key->table[key->table[key->index[0]] + key->table[key->index[1]]];
    }
}
