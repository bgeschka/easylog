all:
	$(CC) easylog.c example.c -o example
clean:
	rm example
	rm -rf logs
test:
	make clean
	make
	./example
	cat logs/*
