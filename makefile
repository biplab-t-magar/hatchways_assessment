main: Course.o Student.o StudentCourse.o Test.o parsing.o main.o
	g++ -std=c++0x Course.o Student.o StudentCourse.o Test.o parsing.o main.o -o main

unitTests: Course.o Student.o StudentCourse.o Test.o parsing.o unitTests.o
	g++ -std=c++0x Course.o Student.o StudentCourse.o Test.o parsing.o unitTests.o -o unitTests

main.o: main.cpp 
	g++ -c -std=c++0x main.cpp
	
Course.o: Course.cpp Course.h
	g++ -c -std=c++0x Course.cpp

Student.o: Student.cpp Student.h
	g++ -c -std=c++0x Student.cpp

StudentCourse.o: StudentCourse.cpp StudentCourse.h
	g++ -c -std=c++0x StudentCourse.cpp

Test.o: Test.cpp Test.h
	g++ -c -std=c++0x Test.cpp

parsing.o: parsing.cpp parsing.h
	g++ -c -std=c++0x parsing.cpp

unitTests.o: unitTests.cpp
	g++ -c -std=c++0x unitTests.cpp

clean:
	rm *.o main unitTests