all:
	gcc TEAtool.c -o TEAtool 
install:
	install ./TEAtool /usr/bin
uninstall:
	rm -f /usr/bin/TEAtool

rus:
	gcc TEAtool.c -o TEAtool -D RUS
