all:
	echo "Do 'make proc' or 'make thread' to choose a library."
proc: searchtest.c multitest_proc.o
	gcc searchtest.c -o searchtest -lm multitest_proc.o
multitest_proc.o:
	gcc -c multitest_proc.c
thread: searchtest.c multitest_thread.o
	gcc searchtest.c -pthread -o searchtest -lm multitest_thread.o
multitest_thread.o:
	gcc -c multitest_thread.c
clean:
	rm searchtest; rm multitest_proc.o; rm multitest_thread.o
