name:=kbbacklightctl

compile:
	gcc main.c -no-pie -o $(name)

install: $(outfile)
	chown root $(name)
	chmod u+s $(name)
	mv $(name) /usr/local/bin
