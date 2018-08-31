CXX       = g++
CXXFLAGS   = -Wall -std=c++11
LDFLAGS  = 
OBJFILES = block/block.o hash/SHA_256.o tx_generator.o merkle/merkle.o main/main.o
TARGET   = block_demo

all: $(TARGET)

#tx_generator.o: tx_generator.cpp
#	g++ -std=c++11 -c tx_generator.cpp -o tx_generator.o

$(TARGET): $(OBJFILES)
	$(CXX) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJFILES) $(TARGET) *~