
CC = gcc
CFLAGS = -Wall -g

clean:
	rm -f run_output *.o *.out

run:
	$(CC) $(CFLAGS) $(FILE) -o run_output && ./run_output
