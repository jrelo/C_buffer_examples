#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t capacity;
    size_t length;
} DynamicBuffer;

void init_dynamic_buffer(DynamicBuffer *buf, size_t initial_capacity) {
    buf->buffer = (char *)malloc(initial_capacity);
    buf->capacity = initial_capacity;
    buf->length = 0;
}

void free_dynamic_buffer(DynamicBuffer *buf) {
    free(buf->buffer);
    buf->buffer = NULL;
    buf->capacity = 0;
    buf->length = 0;
}

void add_to_dynamic_buffer(DynamicBuffer *buf, char c) {
    if (buf->length >= buf->capacity) {
        buf->capacity *= 2;
        buf->buffer = (char *)realloc(buf->buffer, buf->capacity);
    }
    buf->buffer[buf->length++] = c;
}

void print_dynamic_buffer(DynamicBuffer *buf) {
    printf("dynamic buffer contents: %s\n", buf->buffer);
}

int main() {
    DynamicBuffer buf;
    init_dynamic_buffer(&buf, 10);

    const char *input = "hello, world!";
    for (size_t i = 0; i < strlen(input); i++) {
        add_to_dynamic_buffer(&buf, input[i]);
    }

    print_dynamic_buffer(&buf);
    free_dynamic_buffer(&buf);

    return 0;
}
