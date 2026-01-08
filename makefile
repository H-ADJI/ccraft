project = shell
run: build
	@./build/$(project)
build: $(project)/main.c
	@gcc $(project)/main.c $(project)/lib/* -I lib -o build/$(project)
