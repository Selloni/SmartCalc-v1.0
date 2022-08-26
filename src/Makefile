CC = gcc -std=c11
GCC = $(CC) -Wall -Wextra -Werror
SOURSE = main.c calc.c
OBJECT =

debug:
	$(CC) $(SOURSE)

all: 

install:

uninstall:

clean:
	rm -rf a.out

dvi:

dist:

tests: OBJECT
	$(CC) -I include  $(SOURSE) unit_test.c -o test -lcheck

gcov_report:

git:
	git add .
	git commit -m "$(date)"
	git push

OBJECT:
	$(GCC) $(SOURSE) -c