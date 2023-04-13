CC = gcc
FLAGS = -Wall -Werror -Wextra -O0 -g 
SRC = s21_decimal.c
SRC_TEST = s21_decimal.c new_tests.c main_test.c decimal_test.c
OBJ = $(SRC:.c=.o)

all: s21_decimal.a test

s21_decimal.a: $(OBJ)
	ar rc s21_decimal.a $(OBJ)
	ranlib s21_decimal.a
	rm -rf *.o
	
test : s21_decimal.a
	$(CC) $(FLAGS) -g3 --coverage $(SRC_TEST) $^ -lcheck -lm -o test
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
clean:
	rm -rf *.o *.a *.gcno *.gcda test test.info *.out
	rm -rf report
	rm -rf .txt *.dSYM
style:
	clang-format -style=google -i *.c *.h
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
