CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11
SRC = main.c input.c meta_command.c statement.c row.c table.c 
OUT = db

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -rf $(OUT)
