calculator: calculator.o main.o
	g++ calculator.o main.o -o calculator

calculator.o: calculator.cpp
	g++ -g calculator.cpp -c

main.o: main.cpp
	g++ -g main.cpp -c

clean:
	rm -f calculator
	rm -f *~
	rm -f main.o
	rm -f calculator.o