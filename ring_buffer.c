#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define RING_BUF_SIZE 256

typedef struct {
    char buffer[RING_BUF_SIZE];
    size_t write_ptr;
    size_t read_ptr;
    size_t count;
} RingBuffer;

void init_ring_buffer(RingBuffer *buf) {
    buf->write_ptr = 0;
    buf->read_ptr = 0;
    buf->count = 0;
    memset(buf->buffer, 0, RING_BUF_SIZE);
}

bool add_to_ring_buffer(RingBuffer *buf, char c) {
    if (buf->count == RING_BUF_SIZE) {
        return false; // Buffer full
    }
    buf->buffer[buf->write_ptr] = c;
    buf->write_ptr = (buf->write_ptr + 1) % RING_BUF_SIZE;
    buf->count++;
    return true;
}

bool get_from_ring_buffer(RingBuffer *buf, char *c) {
    if (buf->count == 0) {
        return false; // buffer empty
    }
    *c = buf->buffer[buf->read_ptr];
    buf->read_ptr = (buf->read_ptr + 1) % RING_BUF_SIZE;
    buf->count--;
    return true;
}

void print_ring_buffer(RingBuffer *buf) {
    printf("Ring buffer contents: ");
    for (size_t i = 0; i < buf->count; i++) {
        size_t index = (buf->read_ptr + i) % RING_BUF_SIZE;
        printf("%c", buf->buffer[index]);
    }
    printf("\n");
}

int main() {
    RingBuffer buf;
    init_ring_buffer(&buf);

    const char *input = "hello, world!";
    for (size_t i = 0; i < strlen(input); i++) {
        if (!add_to_ring_buffer(&buf, input[i])) {
            printf("ring buffer overflow\n");
        }
    }

    print_ring_buffer(&buf);

    char output;
    printf("reading from ring buffer: ");
    while (get_from_ring_buffer(&buf, &output)) {
        printf("%c", output);
    }
    printf("\n");

    return 0;
}
