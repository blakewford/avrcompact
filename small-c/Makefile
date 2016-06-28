SRC = data.c error.c expr.c function.c gen.c io.c lex.c main.c preproc.c \
      primary.c stmt.c sym.c while.c
OBJ = $(addsuffix .o, $(basename $(SRC)))

small-c: $(OBJ)
	ar rcs lib$@.a $(OBJ)

clean:
	rm -f $(OBJ) *.a

