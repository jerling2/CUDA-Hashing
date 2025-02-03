#include "iterSHA256.h"


void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

/* NOTE: Temporary sample code provided by ChatGPT */
void sha256_hash(const char *input, unsigned char *output) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (ctx == NULL) {
        handleErrors();
    }

    // Initialize the SHA-256 algorithm
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) {
        handleErrors();
    }

    // Update the context with the input data
    if (EVP_DigestUpdate(ctx, input, strlen(input)) != 1) {
        handleErrors();
    }

    // Finalize the hash and store the result in the output buffer
    if (EVP_DigestFinal_ex(ctx, output, NULL) != 1) {
        handleErrors();
    }

    EVP_MD_CTX_free(ctx);
}

