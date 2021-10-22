main: Course.o Student.o StudentCourse.o Test.o Mark.o parsing.o utilities.o serialization.o main.o
	g++ -std=c++0x Course.o Student.o StudentCourse.o Test.o Mark.o parsing.o utilities.o serialization.o main.o -o main

unitTests: Course.o Student.o StudentCourse.o Test.o Mark.o parsing.o utilities.o serialization.o unitTests.o
	g++ -std=c++0x Course.o Student.o StudentCourse.o Test.o Mark.o parsing.o utilities.o serialization.o unitTests.o -o unitTests

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

Mark.o: Mark.cpp Mark.h
	g++ -c -std=c++0x Mark.cpp

parsing.o: parsing.cpp parsing.h
	g++ -c -std=c++0x parsing.cpp

utilities.o: utilities.cpp utilities.h
	g++ -c -std=c++0x utilities.cpp

serialization.o: serialization.cpp serialization.h
	g++ -c -std=c++0x serialization.cpp

unitTests.o: unitTests.cpp
	g++ -c -std=c++0x unitTests.cpp

clean:
	rm *.o main unitTests