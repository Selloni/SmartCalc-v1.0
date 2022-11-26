CC = gcc -std=c11
SOURSE = s21_calc.c s21_steck.c s21_validation.c
LINUX= -lsubunit -lrt -lpthread -lm
# LFLAGS= -fprofile-arcs -ftest-coverage
LIBS= -lcheck -lm -lpthread
GCC = $(CC) -Wall -Wextra -Werror
OS= $(shell uname -s)



all: clean test

test: clean s21_smartcalc.a
ifeq ($(OS),Darwin)
	$(GCC) test.c s21_smartcalc.a -o test $(LIBS)
else
	$(GCC) test.c s21_smartcalc.a -o test $(LIBS) $(LINUX)
endif
	./test

gcov_report: clean_test
	ifeq ($(OS), Darwin)
		$(GCC) --coverage test.c s21_*.c -o test $(LIBS)

	else
		$(GCC) --coverage test.c s21_*.c -o test $(LIBS) $(LINUX)

	endif
		./test
		lcov -t "test" -o test.info --no-external -c -d .
		genhtml -o report test.info
		open report/index.html
		rm -rf test.* s21_*.* test s21_*

s21_smartcalc.a: build_calc

dvi:
	 open dvi.html

install:
	mv Makefile cloneMake && qmake && make && make clean && rm Makefile && mv cloneMake Makefile

open:
	ifeq ($(OS),Darwin)
		open smartcalk

uninstall:
		rm -rf smartcalk.app


build_calc:
	gcc -c s21_*.c
	ar rcs s21_smartcalc.a s21_*.o
	ranlib s21_smartcalc.a 

debug:
	$(CC) $(SOURSE) -g


clean:
	rm -rf a.out
	rm -rf a.out*
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.a
	rm -rf *.cfg

dist:

tests: OBJECT
	$(CC) -I include  $(SOURSE) unit_test.c -o test -lcheck
	./test

git:
	git add .
	git commit -m "пока рабоатет, но нужно проект в порядокпривести"
	git push

cpp:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py *.h *.c
	cppcheck *.c

OBJECT:
	$(GCC) $(SOURSE) -c

valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test
