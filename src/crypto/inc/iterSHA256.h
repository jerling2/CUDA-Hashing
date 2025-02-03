#ifndef ITER_SHA_256_H
#define ITER_SHA_256_H

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void handleErrors(void);
void sha256_hash(const char *input, unsigned char *output);

#endif