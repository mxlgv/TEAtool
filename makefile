DIR='/usr/bin'
all:
	gcc TEAtool.c -o teatool 
install:
	install ./teatool $(DIR)
uninstall:
	rm -f /usr/bin/teatool

rus:
	gcc TEAtool.c -o teatool -D RUS
