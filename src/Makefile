CC = gcc -std=c11
SOURSE = s21_calc.c s21_steck.c s21_validation.c
LINUX= -lsubunit -lrt -lpthread -lm
LFLAGS= -fprofile-arcs -ftest-coverage
LIBS= -lgtest -lgmock -pthread
GCC = $(CC) -Wall -Wextra -Werror
OS=$(shell uname -s)


all: clean test

test: clean s21_smartcalc.a
	ifeq($(OS), Darwin)
		$(GCC) tets.c s21_smartcalc.a -o test $(LIBS)
	
	else
		$(GCC) tets.c s21_smartcalc.a -o test $(LIBS) $(LINUX)

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
	cd qt && open dvi.html && cd.. 

install:
	cd qt && qmake && make && make clean && rm Makefile && cd ..	

open:
	if($(OS), Darwin)
		open smartcalk

uninstall:
	rm -rf smartcalk


build_calc:

	cd qt && gcc -c s21_*cc
	ar rcs s21_smartcalc.a s21_*.o
	ranlib s21_smartcalc.a && cd ..

debug:
	$(CC) $(SOURSE) -g


clean:
	cd qt && rm -rf a.out
	rm -rf a.out*
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.a && cd ..

dist:

tests: OBJECT
	$(CC) -I include  $(SOURSE) unit_test.c -o test -lcheck

git:
	git add .
	git commit -m "добить ворнинги, тесты, стиль, валгринд"
	git push

OBJECT:
	$(GCC) $(SOURSE) -c
