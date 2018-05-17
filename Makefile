all:
	g++ -std=c++17 main.cpp Engine.cpp Arena.cpp -Lsfml -lsfml-graphics -lsfml-window -lsfml-system
