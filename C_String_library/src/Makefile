CC = gcc
FLAGS = -Wall -Werror -Wextra -O0 -g
SRC = s21_string.c s21_sscanf.c s21_sprintf.c 
SRC_TEST = s21_string.c main_test.c string_test.c s21_sscanf.c s21_sprintf.c

OBJ = $(SRC:.c=.o)

all: style s21_string.a test gcov_report

s21_string.a: $(OBJ)
	ar rc s21_string.a $(OBJ)
	ranlib s21_string.a
	rm -rf *.o
	
test : s21_string.a
	$(CC) $(FLAGS) -g3 --coverage $(SRC_TEST) $^ -lcheck -lm -o test
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	
clean:
	rm -rf *.o *.a *.gcno *.gcda test test.info *.out
	rm -rf report
	rm -rf .txt test.dSYM
style:
	clang-format -style=google -i *.c
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
