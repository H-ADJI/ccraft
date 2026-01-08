project = shell

SRC := $(project)/main.c $(wildcard $(project)/lib/*.c)
HDR := $(wildcard $(project)/lib/*.h)

run: build
	@./bin/$(project)

build: $(SRC) $(HDR) | bin
	@gcc $(SRC) -o bin/$(project)

bin:
	@mkdir -p bin
