all:
	gcc -pthread -o server server.c

clean:
	rm -f server
