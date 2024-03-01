OPT = -Wall

a2: main.o Control.o View.o Schedule.o Course.o Time.o School.o CourseArray.o
	g++ $(OPT) -o a2 main.o Control.o View.o Schedule.o Course.o Time.o School.o CourseArray.o

main.o: main.cc defs.h Control.h View.h Schedule.h Time.h School.h CourseArray.h Course.h 
	g++ $(OPT) -c main.cc

Time.o: Time.cc Time.h defs.h
	g++ $(OPT) -c Time.cc

Course.o: Course.cc Course.h defs.h
	g++ $(OPT) -c Course.cc

Schedule.o: Schedule.cc Schedule.h defs.h
	g++ $(OPT) -c Schedule.cc

School.o: School.cc School.h defs.h
	g++ $(OPT) -c School.cc

CourseArray.o: CourseArray.cc CourseArray.h defs.h
	g++ $(OPT) -c CourseArray.cc

Control.o: Control.cc Control.h defs.h
	g++ $(OPT) -c Control.cc

View.o: View.cc View.h defs.h
	g++ $(OPT) -c View.cc

clean:
	rm -f *.o a2