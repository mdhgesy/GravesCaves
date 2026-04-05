CC = clang
CFLAGS = -Wall -I./include

LDFLAGS = -L./lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

SRC = $(wildcard src/*.c)
OUT = game

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)