CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = s21_math.c
SRC_TEST = main_test.c math_test.c s21_math.c

all : s21_math.a 

s21_math.a:
	$(CC) $(FLAGS) -c s21_math.c -o s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a
	rm -rf *.o
	
test : s21_math.a
	$(CC) $(FLAGS) --coverage $(SRC_TEST) $^ -lcheck -o test
	./test
	
gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf *.gcno *.gcda
	open report/index.html

clean: 
	rm -rf s21_math.a s21_math *.o 
	rm -rf test *.info *.gcno *.gcda report

style:
	clang-format -style=google -n *.c *.h

rebuild:
	make clean
	make test

clang:
	clang-format -i -style=google *.c *.h