run: phoneBookApp.o phoneBook.o queue.o
	gcc -o run phoneBookApp.o phoneBook.o queue.o
phoneBookApp.o: phoneBookApp.c phoneBook.h queue.c queue.h
	gcc -c phoneBookApp.c
phoneBook.o: phoneBook.c phoneBook.h queue.c queue.h
	gcc -c phoneBook.c queue.c
