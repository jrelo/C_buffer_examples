#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 64
#define NUM_BLOCKS 4

typedef struct {
    char blocks[NUM_BLOCKS][BLOCK_SIZE];
    size_t current_block;
} BlockBuffer;

void init_block_buffer(BlockBuffer *buf) {
    buf->current_block = 0;
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        memset(buf->blocks[i], 0, BLOCK_SIZE);
    }
}

void add_to_block_buffer(BlockBuffer *buf, const char *data, size_t len) {
    if (len > BLOCK_SIZE) {
        len = BLOCK_SIZE; // truncate to block size
    }
    memcpy(buf->blocks[buf->current_block], data, len);
    buf->current_block = (buf->current_block + 1) % NUM_BLOCKS;
}

void print_block_buffer(BlockBuffer *buf) {
    printf("block buffer contents:\n");
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        printf("block %zu: %s\n", i, buf->blocks[i]);
    }
}

int main() {
    BlockBuffer buf;
    init_block_buffer(&buf);

    const char *input1 = "hello,";
    add_to_block_buffer(&buf, input1, strlen(input1));

    const char *input2 = "world!";
    add_to_block_buffer(&buf, input2, strlen(input2));

    print_block_buffer(&buf);

    return 0;
}
