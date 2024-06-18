#include <stdio.h>
#include <string.h>

#define WINDOW_SIZE 4

typedef struct {
    char buffer[WINDOW_SIZE];
    size_t start;
    size_t end;
    size_t size;
} SlidingWindowBuffer;

void init_sliding_window_buffer(SlidingWindowBuffer *buf) {
    buf->start = 0;
    buf->end = 0;
    buf->size = 0;
    memset(buf->buffer, 0, WINDOW_SIZE);
}

void add_to_sliding_window_buffer(SlidingWindowBuffer *buf, char c) {
    buf->buffer[buf->end] = c;
    buf->end = (buf->end + 1) % WINDOW_SIZE;
    if (buf->size < WINDOW_SIZE) {
        buf->size++;
    } else {
        buf->start = (buf->start + 1) % WINDOW_SIZE; // overwrite oldest data
    }
}

void print_sliding_window_buffer(SlidingWindowBuffer *buf) {
    printf("sliding window buffer contents: ");
    if (buf->size == 0) {
        printf("\n");
        return;
    }

    for (size_t i = 0; i < buf->size; i++) {
        printf("%c", buf->buffer[(buf->start + i) % WINDOW_SIZE]);
    }
    printf("\n");
}

int main() {
    SlidingWindowBuffer buf;
    init_sliding_window_buffer(&buf);

    const char *input = "hello, world!";
    for (size_t i = 0; i < strlen(input); i++) {
        add_to_sliding_window_buffer(&buf, input[i]);
    }

    print_sliding_window_buffer(&buf);

    return 0;
}
