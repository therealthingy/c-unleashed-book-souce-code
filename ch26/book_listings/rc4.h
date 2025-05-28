#pragma once

#include "byteorder.h"

typedef struct RC4_key {
    byte_t table[256];
    byte_t index[2];
} RC4_key_t;

void RC4_setup_key(byte_t const key_text[], size_t len, RC4_key_t *key);
void RC4_encrypt(byte_t const plaintext[], byte_t ciphertext[], size_t len, RC4_key_t *key);
