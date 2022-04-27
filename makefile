ALL: tf03 serv
	@echo "make finished"
serv:
	make -C '$(shell pwd)/iniget/'
tf03:tf03.c ./iniget/iniget.h
	gcc -o tf03 tf03.c -I./iniget/ -I/home/tian/cprogram/include
clean:
	-rm tf03
	make -C '$(shell pwd)/iniget/' clean
