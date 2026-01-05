project = shell
run: build
	@./$(project)/build/$(project)
build: $(project)/main.c
	@gcc $(project)/main.c -o $(project)/build/$(project)
