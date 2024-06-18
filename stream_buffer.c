#include <stdio.h>
#include <string.h>

#define STREAM_BUF_SIZE 256

typedef struct {
    char buffer[STREAM_BUF_SIZE];
    size_t head;
    size_t tail;
} StreamBuffer;

void init_stream_buffer(StreamBuffer *buf) {
    buf->head = 0;
    buf->tail = 0;
    memset(buf->buffer, 0, STREAM_BUF_SIZE);
}

void add_to_stream_buffer(StreamBuffer *buf, const char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        buf->buffer[buf->head] = data[i];
        buf->head = (buf->head + 1) % STREAM_BUF_SIZE;
        if (buf->head == buf->tail) {
            buf->tail = (buf->tail + 1) % STREAM_BUF_SIZE; // overwrite oldest data
        }
    }
}

void read_from_stream_buffer(StreamBuffer *buf, char *dest, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (buf->tail == buf->head) {
            dest[i] = '\0'; // buffer empty
            return;
        }
        dest[i] = buf->buffer[buf->tail];
        buf->tail = (buf->tail + 1) % STREAM_BUF_SIZE;
    }
}

void print_stream_buffer(StreamBuffer *buf) {
    printf("stream buffer contents: ");
    for (size_t i = buf->tail; i != buf->head; i = (i + 1) % STREAM_BUF_SIZE) {
        printf("%c", buf->buffer[i]);
    }
    printf("\n");
}

int main() {
    StreamBuffer buf;
    init_stream_buffer(&buf);

    const char *input1 = "hello, ";
    add_to_stream_buffer(&buf, input1, strlen(input1));

    const char *input2 = "world!";
    add_to_stream_buffer(&buf, input2, strlen(input2));

    print_stream_buffer(&buf);

    char output[20];
    read_from_stream_buffer(&buf, output, sizeof(output) - 1);
    output[sizeof(output) - 1] = '\0';

    printf("read from stream buffer: %s\n", output);

    return 0;
}
