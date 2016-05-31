CC=gcc
CFLAG=-o 
INCDIR=-I/usr/local/include
LIBDIR=-L/usr/local/lib
libDIR=-llua

test: test.o
	$(CC) $(CFLAG) $@ $^ $(INCDIR) $(LIBDIR) $(libDIR) -lm -ldl

clean:
	@rm test.o *.o
