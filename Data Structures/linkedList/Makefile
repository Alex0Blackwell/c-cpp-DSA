output: testDriver.o ll_node.o ll.o
	g++ testDriver.o ll_node.o ll.o -o output -Wall

driver.o: testDriver.cpp
	g++ -c testDriver.cpp -Wall

ll_node.o: ll_node.cpp ll_node.hpp
	g++ -c ll_node.cpp -Wall

list.o: ll.cpp ll.hpp
	g++ -c ll.cpp -Wall

clean:
	rm *.o output *.gch
