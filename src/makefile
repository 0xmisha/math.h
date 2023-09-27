CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

TEST_FLAGS = -lcheck -lpthread -pthread -lm 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

TEST_SRC = $(wildcard ./test/*.c)
TEST_OBJ2 = $(patsubst ./test/%.c, ./test/%.o, $(TEST_SRC))

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lsubunit -lgcov -lrt
endif

all: clean s21_math.a test gcov_report

test.a: $(TEST_OBJ2)
	ar r test.a $^

s21_math.a: $(OBJ)
	ar rc s21_math.a $^
	ranlib s21_math.a
	rm -rf *.o

test: s21_math.a test.a
	$(CC) test.a s21_math.a $(TEST_FLAGS) -o test.out
	./test.out

gcov_report: clean
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST_SRC) $(SRC) -o test.out $(TEST_FLAGS)
	./test.out
	lcov -t "s21_math.a" -o s21_math.a.info -c -d .
	genhtml -o gcov_report s21_math.a.info
	rm -rf *.gcno *.gcda

style_fix:
	clang-format -style=Google -i *.c *.h

style:
	clang-format -style=Google -n $(SRC) *.h

rebuild: clean all

testforleaks: s21_math.a test.a 
	$(CC) $(FLAGS) test.a s21_math.a $(TEST_FLAGS) -o test.out


leaks: testforleaks
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes  ./test.out
else
	leaks --atExit -- ./test.out
endif


clean:
	rm -rf *.o *.a check.c ./test/*.o ./test/*.a test.out *.gcno *.gcda gcov_report *.info
