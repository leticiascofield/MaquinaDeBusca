tp_executation: ./build/MaquinadeBusca.o ./build/main.o
	g++ ./build/*.o -o tp_executation

./build/MaquinadeBusca.o: ./include/MaquinadeBusca.hpp ./src/MaquinadeBusca.cpp
	g++ -I ./include/ -c ./src/MaquinadeBusca.cpp -o ./build/MaquinadeBusca.o

./build/main.o: ./include/MaquinadeBusca.hpp ./src/main.cpp
	g++ -I ./include/ -c ./src/main.cpp -o ./build/main.o

run:
	./tp_executation

clean:
	rm -f ./build/*