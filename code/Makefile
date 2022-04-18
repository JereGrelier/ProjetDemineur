LDFLAGS = -Lmine 
CFLAGS = -I./include -Wall

.PHONY: clean doc


all: game


game: bin/main.o bin/grid.o bin/manual.o bin/end.o bin/menu.o
	c99 -o $@ $^  $(LDFLAGS) -ggdb -O0

bin/%.o : src/%.c include/grid.h include/manual.h
	c99 $(CFLAGS) -c $< -o $@ -fpic

clean:
	rm -rf grid && cd bin && rm -rf *;

dynlibmine: bin/grid.o bin/end.o bin/menu.o bin/manual.o
	gcc -shared $^ -o lib/libmine.so

doc:
	cd doc && doxygen && cd latex && make;