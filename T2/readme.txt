Instruções de compilacao/execucao

1: task_w_deadline (Escrito em C++):
	Necessario Clang
	Com Makefile: usar "make all" para compilar e "make run" para rodar
		Se não possuir a Clang instalada: "make clang"
	Caso prefira compilar manualmente no g++, então:
	- Para compilar, deve-se utlizar um terminal de sua preferência, com Clang instalada. Utilizamos:
		g++ -o TASKS tasks.cpp
	- Para executar, ainda no bash, utilizamos:
		./TASKS -> Para Linux/Mac
		TASKS.exe -> Para Windows

2: super_string (Escrito em Lua):
	Primeiramente é necessário ter o intepretador Lua instalado.
	SE USAR O MAKEFILE(o comando "make lua" só funcionará em Linux derivados do Debian):
	Basta usar: "make lua" -> instala o binario de Lua usando o apt

	Caso não queira usar Makefile, o interpretador de Lua também pode ser obtido através do link:
		https://sourceforge.net/projects/luabinaries/files/5.3.5/
	Ou ainda, se nos derivados de Debian: apt install lua5.2;		No Mac: brew install lua5.2
	Pesa em torno de 400Kb.
	
	Para executar, basta entrar no diretorio super_string e executar o comando "lua Supertring.lua 'STRINGS SEPARADAS POR ESPACOS' "
	
