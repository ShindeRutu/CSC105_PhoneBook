run: phoneBookApp.o phoneBook.o queue.o stack.o
	gcc -o run phoneBookApp.o phoneBook.o queue.o stack.o
phoneBookApp.o: phoneBookApp.c phoneBook.h queue.c queue.h stack.c stack.h
	gcc -c phoneBookApp.c
phoneBook.o: phoneBook.c phoneBook.h queue.c queue.h stack.c stack.h
	gcc -c phoneBook.c queue.c stack.c
