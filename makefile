DIR='/usr/bin'
all:
	gcc teatool.c -o teatool 
install:
	install ./teatool $(DIR)
uninstall:
	rm -f /usr/bin/teatool

rus:
	gcc teatool.c -o teatool -D RUS
