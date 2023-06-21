

all: clean test dvi install

install:
	cmake -S 3dmainwindow/ -B build
	make -C build/


uninstall:
	rm -rf ~/Desktop/3dmainwindow.app

dist: install
	tar -czf 3dmainwindow.tar.gz ~/Desktop/3dmainwindow.app
	rm -rf ~/Desktop/3dmainwindow.app

dvi:
	open html/index.html

hello_test:
	cmake -S 3dmainwindow/ -B build -DMYLIB_TEST=1
	make -C build/


.PHONY: test tests
test: hello_test
	./build/hello_test

tests: hello_test
	./build/hello_test

clean:
	rm -rf *.o *.a *.out *.info report test.out.dSYM *.gcno

lint:
	-cp ../materials/linters/.clang-format .
	-find . -type f -name "*.cc" | xargs clang-format --style=Google -n
	-find . -type f -name "*.h"  | xargs clang-format --style=Google -n

flint: lint
	-find . -type f -name "*.cc" | xargs clang-format --style=Google -i
	-find . -type f -name "*.h"  | xargs clang-format --style=Google -i
