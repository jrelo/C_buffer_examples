#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char buffer[BUFFER_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} CircularBuffer;

void init_circular_buffer(CircularBuffer *buf) {
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;
    memset(buf->buffer, 0, BUFFER_SIZE);
}

bool add_to_circular_buffer(CircularBuffer *buf, char c) {
    if (buf->count == BUFFER_SIZE) {
        buf->tail = (buf->tail + 1) % BUFFER_SIZE; // overwrite oldest data
    } else {
        buf->count++;
    }
    buf->buffer[buf->head] = c;
    buf->head = (buf->head + 1) % BUFFER_SIZE;
    return true;
}

bool get_from_circular_buffer(CircularBuffer *buf, char *c) {
    if (buf->count == 0) {
        return false; // buffer empty
    }
    *c = buf->buffer[buf->tail];
    buf->tail = (buf->tail + 1) % BUFFER_SIZE;
    buf->count--;
    return true;
}

void print_circular_buffer(CircularBuffer *buf) {
    printf("circular buffer contents: ");
    for (size_t i = 0; i < buf->count; i++) {
        size_t index = (buf->tail + i) % BUFFER_SIZE;
        printf("%c", buf->buffer[index]);
    }
    printf("\n");
}

int main() {
    CircularBuffer buf;
    init_circular_buffer(&buf);

    const char *input = "hello, world!";
    for (size_t i = 0; i < strlen(input); i++) {
        add_to_circular_buffer(&buf, input[i]);
    }

    print_circular_buffer(&buf);

    char output;
    printf("reading from circular buffer: ");
    while (get_from_circular_buffer(&buf, &output)) {
        printf("%c", output);
    }
    printf("\n");

    return 0;
}
