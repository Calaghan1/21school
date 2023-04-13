CC = gcc
CFLAG = -std=c11 -Wall -Werror -Wextra
FILES = tests/tests.c smat_calc/calc_core.c smat_calc/stack.c

all: test

test: 
	$(CC) $(CFLAG) -lcheck -g3 --coverage $(FILES) -o run_test
	./run_test
install:
	mkdir build
	cd build && qmake ../smat_calc/smat_calc.pro && make
	cd build && cp -r smat_calc.app ~/Desktop
	rm -drf build
dist: install
	tar -czf calc.tar.gz ~/Desktop/smat_calc.app
	rm -rf ~/Desktop/smat_calc.app
dvi:
	open README.md
uninstall:
	rm -rf ~/Desktop/smat_calc.app
clean:
	rm -rf *.out *.gcda *.gcno run_test test.info
	rm -rf report
	rm -rf .txt *.dSYM
gcov_report: test
	lcov -t "run_test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i smat_calc/*.c
	clang-format -i smat_calc/*.h
	clang-format -i smat_calc/*.cpp

