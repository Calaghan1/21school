CC =gcc -g -Wall -Werror -Wextra -std=c11 -D_GNU_SOURSE
OS = $(shell uname -s)
ifeq ($(OS), Linux)
UBU =  -lm -lpthread -lrt -lsubunit
else
UBU = 
endif

all: clean test gcov_report dvi install

install:
	mkdir build
	cd build && qmake ../3dmainwindow/3dmainwindow.pro && make
	cd build && cp -r 3dmainwindow.app ~/Desktop
	rm -drf build


uninstall:
	rm -rf ~/Desktop/3dmainwindow.app

dist: install
	tar -czf 3dmainwindow.tar.gz ~/Desktop/3dmainwindow.app
	rm -rf ~/Desktop/3dmainwindow.app

dvi:
	open html/index.html

test:
	$(CC) -lcheck $(UBU) tests/test.c 3dmainwindow/parser.c 3dmainwindow/s21_matrix.c -o test.out
	./test.out

gcov_report:
	$(CC) --coverage 3dmainwindow/*.c -lcheck $(UBU) tests/test.c -o test.out
	./test.out
	lcov -t "my_test" -c -d ./ --output-file ./test.info
	genhtml -o report test.info
	rm -rf *.gcda *.gch *.gcno *.out *.o *.out
	open report/index.html

clean:
	rm -rf *.o *.a *.out *.info report test.out.dSYM *.gcno

style:
	clang-format -i --style=Google tests/*.c 3dmainwindow/*.c 3dmainwindow/*.h 3dmainwindow/oglwidget.cpp 3dmainwindow/mainwindow.cpp 3dmainwindow/main.cpp
	clang-format -n --style=Google tests/*.c 3dmainwindow/*.c 3dmainwindow/*.h 3dmainwindow/oglwidget.cpp 3dmainwindow/mainwindow.cpp 3dmainwindow/main.cpp
