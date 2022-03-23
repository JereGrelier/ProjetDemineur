LDFLAGS = -Lmine 
CFLAGS = -I./include

.PHONY: clean doc


all: game


game: bin/main.o bin/grid.o bin/manual.o
	gcc -o $@ $^  $(LDFLAGS) -ggdb -O0

bin/%.o : src/%.c include/grid.h include/manual.h
	gcc $(CFLAGS) -c $< -o $@ -fpic

clean:
	rm -rf grid && cd bin && rm -rf *;


libmine: lib/libmat.a bin/matrix.o bin/vector.o
	ar crs  $^

dynlibmine: bin/grid.o 
	gcc -shared $^ -o lib/libmine.so

doc:
	cd doc && doxygen && cd latex && make;