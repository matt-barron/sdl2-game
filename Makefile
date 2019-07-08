main: main.cpp
	g++ main.cpp  game.cpp TextureManager.cpp GameObject.cpp  map.cpp -o main -I/Users/mattbarron/Library/Frameworks/SDL2.framework/Headers/ -I/Users/mattbarron/Library/Frameworks/SDL2_image.framework/Headers/  -lSDL2 -lSDL2_image
