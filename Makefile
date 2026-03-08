ifeq ($(OS),Windows_NT)
    COMPILE = main.exe
    RUN = .\main.exe
else
    COMPILE = main
    RUN = ./main
endif

main: main.c hash.c
	gcc main.c hash.c -o $(COMPILE)
	$(RUN)
    