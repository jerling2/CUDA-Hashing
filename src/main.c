#include <stdio.h>
#include "iterSHA256.h"

int main() {
    /* NOTE: Temporary sample code provided by ChatGPT */
    const char *data = "Hello, OpenSSL!";
    unsigned char hash[EVP_MAX_MD_SIZE]; // This holds the hash result

    sha256_hash(data, hash);

    printf("SHA-256 Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}