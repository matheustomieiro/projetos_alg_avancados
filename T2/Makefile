all: Main Matriz
	g++ -o bin/Main temp/Matriz.o temp/Main.o

Main:
	g++ -c src/Main.cpp
	@mv Main.o temp/Main.o

Matriz:
	g++ -c src/Matriz.cpp
	@mv Matriz.o temp/Matriz.o

run:
	bin/./Main

clean:
	@rm temp/*
	@echo "Cleaned!"