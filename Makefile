CFLAGS = -Wall -Werror -Wextra -pedantic $(shell sdl2-config --cflags)
LDFLAGS = -lm $(shell sdl2-config --libs)
TARGET = maze
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
