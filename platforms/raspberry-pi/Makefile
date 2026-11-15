CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -Wno-unused-parameter -Wno-maybe-uninitialized -Wno-stringop-truncation
LDFLAGS = -lm

SRCS := $(filter-out arduino_stdio_shim.c,$(wildcard *.c))
TARGET = fuzzy_cli

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)


