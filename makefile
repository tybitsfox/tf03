tf03:tf03.c ./iniget/iniget.h ./iniget/iniget.c
	gcc -o tf03 tf03.c -I./iniget/ -I/home/tian/cprogram/include
	make -C '$(shell pwd)/iniget/'
clean:
	rm tf03
