CC = gcc
LDFLAGS = 
TARGET = main
HEADERS = binary_tree.h 
SOURCES = main.c binary_tree.c 
DEPENDENCIES = $(HEADERS) $(SOURCES)

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
