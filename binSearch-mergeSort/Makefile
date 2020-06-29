output: testDriver.o
	g++ testDriver.o -o output -Wall

testDriver.o: binarySearch.hpp mergeSort.hpp testDriver.cpp
	g++ -c testDriver.cpp -Wall

clean:
	rm *.o *.gch output
