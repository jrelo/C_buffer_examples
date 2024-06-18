#include <stdio.h>
#include <string.h>

#define LINEAR_BUF_SIZE 256

typedef struct {
    char buffer[LINEAR_BUF_SIZE];
    size_t length;
} LinearBuffer;

void init_linear_buffer(LinearBuffer *buf) {
    buf->length = 0;
    memset(buf->buffer, 0, LINEAR_BUF_SIZE);
}

void add_to_linear_buffer(LinearBuffer *buf, char c) {
    if (buf->length < LINEAR_BUF_SIZE - 1) {
        buf->buffer[buf->length++] = c;
    } else {
        printf("linear buffer overflow\n");
    }
}

void print_linear_buffer(LinearBuffer *buf) {
    printf("linear buffer contents: %s\n", buf->buffer);
}

int main() {
    LinearBuffer buf;
    init_linear_buffer(&buf);

    const char *input = "hello, world!";
    for (size_t i = 0; i < strlen(input); i++) {
        add_to_linear_buffer(&buf, input[i]);
    }

    print_linear_buffer(&buf);

    return 0;
}
