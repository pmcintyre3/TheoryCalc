
calculator: state.o pushdown.o calculator.o main.o
	g++ state.o pushdown.o calculator.o main.o -o calc

main.o: main.cpp
	g++ -g main.cpp -c

calculator.o: calculator.cpp
	g++ -g calculator.cpp -c

pushdown.o: pushdown.cpp
	g++ -g pushdown.cpp -c

state.o: state.cpp
	g++ -g state.cpp -c

clean:
	rm -f calc
	rm -f *~
	rm -f *.o
