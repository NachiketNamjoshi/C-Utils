INC_DIR = ../utils
CFLAGS = -I$(INC_DIR)

whosyodaddy:
	gcc main.c -o whosyodaddy.o $(CFLAGS)

install: whosyodaddy
	sudo cp whosyodaddy.o /usr/bin/c_utils/whosyodaddy

clean:
	rm -rf *.o