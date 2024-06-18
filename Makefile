# Makefile for compiling buffer examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGETS = linear_buffer ring_buffer double_buffer circular_buffer sliding_window_buffer dynamic_buffer stream_buffer block_buffer

all: $(TARGETS)

linear_buffer: linear_buffer.c
	$(CC) $(CFLAGS) -o linear_buffer linear_buffer.c

ring_buffer: ring_buffer.c
	$(CC) $(CFLAGS) -o ring_buffer ring_buffer.c

double_buffer: double_buffer.c
	$(CC) $(CFLAGS) -o double_buffer double_buffer.c

circular_buffer: circular_buffer.c
	$(CC) $(CFLAGS) -o circular_buffer circular_buffer.c

sliding_window_buffer: sliding_window_buffer.c
	$(CC) $(CFLAGS) -o sliding_window_buffer sliding_window_buffer.c

dynamic_buffer: dynamic_buffer.c
	$(CC) $(CFLAGS) -o dynamic_buffer dynamic_buffer.c

stream_buffer: stream_buffer.c
	$(CC) $(CFLAGS) -o stream_buffer stream_buffer.c

block_buffer: block_buffer.c
	$(CC) $(CFLAGS) -o block_buffer block_buffer.c

clean:
	rm -f $(TARGETS)

.PHONY: all clean
