run: phoneBookApp.o phoneBook.o
	gcc -o run phoneBookApp.o phoneBook.o
phoneBookApp.o: phoneBookApp.c phoneBook.h
	gcc -c phoneBookApp.c
phoneBook.o: phoneBook.c phoneBook.h
	gcc -c phoneBook.c