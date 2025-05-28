#pragma once

#include "byteorder.h"
#include <stddef.h>

void SHA_1_pad_msg(uint32_t *padded, uint64_t num_blocks, byte_t const *unpadded, uint64_t len);
int SHA_1_full(byte_t const *msg, uint64_t len, uint32_t digest[5]);
