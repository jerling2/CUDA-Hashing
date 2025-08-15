# CUDA-Hashing

CUDA-Hashing is a project focused on providing cryptographic hash functionality, leveraging both CPU (with OpenSSL) and eventually GPU (CUDA) acceleration for efficient hashing operations.

## Features

- **SHA-256 Hash Generation (CPU)**: Utilizes OpenSSL to compute SHA-256 hashes.
- **Modular Design**: Code is organized into clear submodules for crypto and (upcoming) CUDA functionality.
- **Comprehensive Makefile**: Automatically builds the project, handling dependencies and directory structure.

## Building

The project uses a Makefile for building. To compile:

```sh
make
```

This will produce the binary `parahash`.

## Usage

Currently, the main application computes the SHA-256 hash of a sample string. Example usage:

```sh
./parahash
```

You should see output similar to:

```
SHA-256 Hash: <hash_output>
```

## File Structure

- `src/crypto/inc/iterSHA256.h` - Header for SHA-256 hashing functions.
- `src/crypto/src/iterSHA256.c` - SHA-256 hash implementation using OpenSSL.
- `src/main.c` - Main application demonstrating hashing.
- `Makefile` - Build system.
- `README.md` - Project overview and instructions.

## License

MIT License. See [LICENSE](LICENSE) for details.

## Author

Joseph Erlinger (jerling2@uoregon.edu)
