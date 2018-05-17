all:
	g++ -std=c++17 main.cpp Engine.cpp Arena.cpp Menu.cpp -Lsfml -lsfml-graphics -lsfml-window -lsfml-system
