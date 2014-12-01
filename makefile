calculator: calculator.o main.o
	g++ calculator.o main.o -o calc

calculator.o: calculator.cpp
	g++ -g calculator.cpp -c

main.o: main.cpp
	g++ -g main.cpp -c

clean:
	rm -f calculator
	rm -f calc
	rm -f *~
	rm -f *.o
