sccavr: codeavr.o small-c/libsmall-c.a
	$(CC) codeavr.o small-c/libsmall-c.a -o sccavr

codeavr.o: ./small-c/libsmall-c.a
	$(CC) -c -g -Ismall-c codeavr.c -o $@

clean:
	rm -f *.o sccavr

