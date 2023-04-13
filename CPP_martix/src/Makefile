.PHONY: s21_matrix_oop.a test

CC = g++
CFLAGS = -std=c++17 -lstdc++ -pedantic -Wall -Werror -Wextra -g3

all:
	$(MAKE) s21_matrix_oop.a

s21_matrix_oop.a:
	$(MAKE) clean
	$(CC) $(CFLAGS) -c s21_matrix_oop.cc
	ar -rv s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a
	rm *.o

test:
	$(MAKE) s21_matrix_oop.a
	$(CC) $(CFLAGS) test.cc s21_matrix_oop.a -lgtest -o test
	./test

gcov_report: s21_matrix_oop.a
	$(CC) --coverage s21_matrix_oop.cc test.cc -lgtest s21_matrix_oop.a -L. s21_matrix_oop.a -o test.out
	./test.out
	lcov -t "my_test" -c -d ./ --output-file ./test.info
	genhtml -o report test.info
	rm -rf *.gcda *.gch *.gcno *.out *.o *.out
	open report/index.html

clean:
	@rm -rf *.o *.a test

style:
	clang-format -style=Google -n *.cc *.h