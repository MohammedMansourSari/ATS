CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = ats

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
