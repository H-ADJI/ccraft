project = shell
run: build
	@./build/$(project)
build: $(project)/main.c
	@gcc $(project)/main.c -o build/$(project)
