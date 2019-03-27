all:
	flex compiler.l
	gcc lex.yy.c -ll -o lexic_analyzer
	gcc syntax-calc.c -o syntax-calc

clean:
	rm -rf *.c
	rm -rf lexic_analyzer
	rm -rf syntax-calc