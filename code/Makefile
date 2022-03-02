LDFLAGS = -L./lib 
CFLAGS = -I./include

.PHONY: clean doc


all: game


game: bin/main.o bin/grid.o
	gcc -o $@ $^  $(LDFLAGS) -ggdb -O0

bin/%.o : src/%.c include/grid.h
	gcc $(CFLAGS) -c $< -o $@ -fpic

clean:
	rm -rf game && cd bin && rm -rf *;


libmat: lib/libmat.a bin/matrix.o bin/vector.o
	ar crs  $^

dynlibmat: bin/matrix.o bin/vector.o 
	gcc -shared $^ -o lib/libmat.so

doc:
	cd doc && doxygen && cd latex && make;