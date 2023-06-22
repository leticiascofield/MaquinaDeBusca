main.exe: ./build/MaquinadeBusca.o ./build/main.o
	g++ -std=c++17 ./build/*.o -o main.exe

./build/MaquinadeBusca.o: ./include/MaquinadeBusca.hpp ./src/MaquinadeBusca.cpp
	g++ -std=c++17 -I ./include/ -c ./src/MaquinadeBusca.cpp -o ./build/MaquinadeBusca.o

./build/main.o: ./include/MaquinadeBusca.hpp ./src/main.cpp
	g++ -std=c++17 -I ./include/ -c ./src/main.cpp -o ./build/main.o

run:
	./main.exe

clean:
	rm -f ./build/*