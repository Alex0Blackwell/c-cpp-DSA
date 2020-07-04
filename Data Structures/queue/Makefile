output: testDriver.o q.o
	g++ q.o testDriver.o -o output -Wall

testDriver.o: testDriver.cpp
	g++ -c testDriver.cpp -Wall

q.o: q.cpp q.hpp
	g++ -c q.cpp -Wall

clean:
	rm *.o output *.gch
