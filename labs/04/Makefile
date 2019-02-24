all:
	flex compiler.l
	gcc lex.yy.c -lfl -o compiler

clean:
	rm -rf *.c
	rm -rf compiler