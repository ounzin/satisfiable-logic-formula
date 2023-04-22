a.out:
	@lex logic.l
	@yacc -d logic.y
	@cc lex.yy.c y.tab.c node.c -ll
	@./a.out < file.txt
	@rm lex.yy.c y.tab.c y.tab.h a.out