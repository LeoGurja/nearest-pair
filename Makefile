exec = points
sources = $(wildcard src/*.c)
objects = $(patsubst src/%,target/%,$(sources:.c=.o))
flags = -g -Wall -lm -ldl -fPIC -rdynamic -O3
incl = -Iinclude

$(exec): $(objects)
	gcc $(objects) $(flags) -o target/$(exec)

target/%.o: src/%.c
	gcc -c $(flags) $< $(incl) -o $@

clean:
	-rm target/points
	-rm **/*.o

lint:
	clang-tidy src/*.c src/include/*.h