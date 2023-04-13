CC = gcc 
CFLAGS =  -Wall -Wextra -Werror -g3
all: s21_grep
s21_grep: 
	$(CC) $(CFLAGS) s21_grep.c s21_grepfun.c -o s21_grep
clean:
	rm -rf *.out 0_diff.res 0_grep.res 0_s21_grep.res
	rm -rf *.o log.txt
rebuild:
	rm s21_grep
	$(CC) $(CFLAGS) s21_grep.c s21_grepfun.c -o s21_grep
c-lang:
	clang-format -n *.c -style=google
	clang-format -n *.h -style=google
mem-leaks:
	leaks -atExit -- ./s21_grep for *.c -f pattern.txt -f s21_grep.c
