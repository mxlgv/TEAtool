all:
	gcc src/TEAtool.c -o linux/TEAtool 
install:
	install ./linux/TEAtool /usr/bin
uninstall:
	rm -f /usr/bin/TEAtool
