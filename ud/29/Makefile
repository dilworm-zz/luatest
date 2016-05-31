CC=gcc
CFLAG=-o 
INCDIR=-I/usr/local/include
LIBDIR=-L/usr/local/lib
libDIR=-llua

bitarray.so: bitarray.c
	$(CC) -Wall -shared -fPIC -o $@  -I/usr/local/include -llua $<

clean:
	@rm bitarray.so *.o
