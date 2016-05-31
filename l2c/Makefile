CC=gcc
INCDIR=-I/usr/local/include

power.so:
	$(CC) -Wall -shared -fPIC -o $@  -I/usr/local/include -llua pow.c

msleep.so:
	$(CC) -Wall -shared -fPIC -o $@  -I/usr/local/include -llua msleep.c


all: power.so msleep.so
#%.o:%.c 
#	$(CC) -c -o $@ $< $(INCDIR)		
#%.so:%.o
#	$(CC) -Wall -shared -fPIC -o $@ -llua 
#
clean:
	@rm power.so msleep.so 
