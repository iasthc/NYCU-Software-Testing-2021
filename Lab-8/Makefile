CC ?= gcc
C_FILES = $(wildcard *.c)
OBJS += $(C_FILES:.c=.o)
CFLAGS = -Wall -g
all: bmpgrayscale

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
bmpgrayscale: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)

check: bmpgrayscale
	$(RM) out.bmp
	./bmpgrayscale test.bmp out.bmp
clean:
	$(RM) bmpgrayscale *.o *.gch out.bmp >/dev/null 2>/dev/null || true
