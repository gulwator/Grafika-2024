all:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/utils.c -lmingw32 -lSDL2main -lSDL2 -lobj -lopengl32 -lm -o picking.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/utils.c -lobj -lSDL2 -lGL -lm -o picking -Wall -Wextra -Wpedantic
