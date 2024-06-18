#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    char *read_buffer;
    char *write_buffer;
} DoubleBuffer;

void init_double_buffer(DoubleBuffer *buf) {
    buf->read_buffer = buf->buffer1;
    buf->write_buffer = buf->buffer2;
    memset(buf->buffer1, 0, BUFFER_SIZE);
    memset(buf->buffer2, 0, BUFFER_SIZE);
}

void swap_buffers(DoubleBuffer *buf) {
    char *temp = buf->read_buffer;
    buf->read_buffer = buf->write_buffer;
    buf->write_buffer = temp;
}

void write_to_double_buffer(DoubleBuffer *buf, const char *data) {
    strncpy(buf->write_buffer, data, BUFFER_SIZE - 1);
}

void print_double_buffer(DoubleBuffer *buf) {
    printf("double buffer read contents: %s\n", buf->read_buffer);
}

int main() {
    DoubleBuffer buf;
    init_double_buffer(&buf);

    write_to_double_buffer(&buf, "hello, world!");
    swap_buffers(&buf);
    print_double_buffer(&buf);

    write_to_double_buffer(&buf, "LaTaZ.");
    swap_buffers(&buf);
    print_double_buffer(&buf);

    return 0;
}
