#pragma once

#include <inttypes.h>
#include <stddef.h>

/*
 * Change these types to match your platform
 */
typedef unsigned char byte_t; /* 8-bit integer */

void native_byte_order16(uint16_t *msg, size_t num_blocks);
void native_byte_order32(uint32_t *msg, size_t num_blocks);
void native_byte_order64(uint64_t *msg, size_t num_blocks);
void big_endian16(uint16_t *msg, size_t num_blocks);
void big_endian32(uint32_t *msg, size_t num_blocks);
void big_endian64(uint64_t *msg, size_t num_blocks);
