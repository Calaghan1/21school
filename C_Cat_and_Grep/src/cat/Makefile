CC = gcc
CFLAGS =  -Wall -Wextra -Werror
all: s21_cat
s21_cat: 
	$(CC) $(CFLAGS) s21_cat.c cat_funk.c -o s21_cat
rebuild:
	rm s21_cat
	$(CC) $(CFLAGS) s21_cat.c cat_funk.c -o s21_cat
c-lang:
	clang-format -n *.c -style=google
	clang-format -n *.h -style=google
mem-leaks:
	leaks -atExit -- ./s21_cat -b *.c
