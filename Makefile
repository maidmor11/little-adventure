all:
	g++ main.cpp Engine.cpp Arena.cpp -Lsfml -lsfml-graphics -lsfml-window -lsfml-system
