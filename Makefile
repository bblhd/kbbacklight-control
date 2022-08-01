CC:=gcc
CFLAGS:=
LDFLAGS:=

suppress:=-Wno-parentheses

basedir:=$(shell pwd)
outfile:=$(shell basename "$(basedir)")
cfiles:=$(wildcard *.c)
objects:=$(cfiles:.c=.o)

compile: $(outfile)

install: $(outfile)
	chown root $(outfile)
	chmod u+s $(outfile)
	mv $(outfile) /usr/local/bin

$(outfile): $(objects)
	$(CC) -o $@ $^ $(LDFLAGS) -no-pie

$(objects): %.o: %.c
	$(CC) -c $(suppress) $(CFLAGS) $< -o $@

