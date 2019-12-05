all: Main Matriz
	g++ -o bin/Main.x temp/Matriz.o temp/Main.o

Main:
	g++ -c src/Main.cpp
	@mv Main.o temp/Main.o

Matriz:
	g++ -c src/Matriz.cpp
	@mv Matriz.o temp/Matriz.o

run:
	bin/./Main.x

clean:
	@rm temp/*.o
	@rm bin/*.x
	@echo "Cleaned!"
