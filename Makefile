compile: src/*.cpp
	g++ src/*.cpp -IC:\mingw_dev_lib\SDL2_main\include -LC:\mingw_dev_lib\SDL2_main\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o test