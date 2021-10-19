assessment: Course.o Student.o StudentCourse.o Test.o assessment.o
	g++ -std=c++0x Course.o Student.o StudentCourse.o Test.o assessment.o -o assessment

Course.o: Course.cpp Course.h
	g++ -c -std=c++0x Course.cpp

Student.o: Student.cpp Student.h
	g++ -c -std=c++0x Student.cpp

StudentCourse.o: StudentCourse.cpp StudentCourse.h
	g++ -c -std=c++0x StudentCourse.cpp

Test.o: Test.cpp Test.h
	g++ -c -std=c++0x Test.cpp

assessment.o: assessment.cpp 
	g++ -c -std=c++0x assessment.cpp

clean:
	rm *.o assessment