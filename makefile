students: main.o date.o address.o
	g++ -g main.o date.o address.o -o students

main.o: main.cpp  date.h address.h
	g++ -g -c main.cpp

date.o: date.cpp date.h
	g++ -g -c date.cpp
address.o: address.cpp address.h
	g++ -g -c address.cpp

run: students
	./students

clean:
	rm students
	rm *.o

debug: students
	gbd students

valgrind: students
	valgrind --leak-check=full ./students


