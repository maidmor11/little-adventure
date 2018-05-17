all:
	g++ main.cpp Room.cpp Engine.cpp -Lsfml -lsfml-graphics -lsfml-window -lsfml-system
