CC = gcc -std=c11
SOURSE = main.c s21_calc.c s21_steck.c s21_validation.c
LINUX= -lsubunit -lrt -lpthread -lm
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

gcov_report:
ifeq ($(OS), Darwin)
	$(GCC) --coverage test.c s21_*.c -o test $(LIBS)

else
	$(GCC) --coverage test.c s21_*.c -o test $(LIBS) $(LINUX)

endif
	chmod +x *
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

dvi:
	 open dvi.html

install:
	mv Makefile cloneMake && qmake && make && make clean && rm Makefile && mv cloneMake Makefile


uninstall:
		rm -rf smartcalk.app
		


s21_smartcalc.a:
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
	rm -rf build

dist:
	mkdir build
	tar -cf build/dist.tar smartcalk.app

push:
	git add .
	git commit -m "done"
	git push

# cpp:
# 	cp ../materials/linters/CPPLINT.cfg ./
# 	python3 ../materials/linters/cpplint.py s21_*.h s21_*.c
# 	cppcheck *.c


valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test

clang:
	mv ../materials/linters/.clang-format .clang-format
	clang-format -i s21_*.c s21_*.h
	clang-format -n s21_*.c s21_*.h
	mv .clang-format ../materials/linters/.clang-format