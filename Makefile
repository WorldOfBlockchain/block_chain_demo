CC       = g++
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = block/block.o hash/SHA_256.o main/main.o
TARGET   = block_demo

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJFILES) $(TARGET) *~