CC=gcc
CFLAG=-o 
INCDIR=-I/usr/local/include
LIBDIR=-L/usr/local/lib
libDIR=-llua

foo.so: 
	$(CC) $(CFLAG) $@ $^ $(INCDIR) $(LIBDIR) $(libDIR) -lm -ldl

clean:
	@rm test.o *.o
