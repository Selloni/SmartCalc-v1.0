CC = gcc -std=c11
GCC = $(CC) -Wall -Wextra -Werror
SOURSE = main.c s21_calc.c s21_steck.c s21_validation.c
OBJECT =

debug:
	$(CC) $(SOURSE) -g

all: 

install:

uninstall:

clean:
	rm -rf a.out
	rm -rf a.out*

dvi:

dist:

tests: OBJECT
	$(CC) -I include  $(SOURSE) unit_test.c -o test -lcheck

gcov_report:

git:
	git add .
	git commit -m "рабочее состояние-проверить сложные функции"
	git push

OBJECT:
	$(GCC) $(SOURSE) -c