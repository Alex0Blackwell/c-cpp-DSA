output: testDriver.o stack.o
	g++ stack.o testDriver.o -o output -Wall

testDriver.o: testDriver.cpp
	g++ -c testDriver.cpp -Wall

stack.o: stack.cpp stack.hpp
	g++ -c stack.cpp -Wall

clean:
	rm *.o output *.gch
