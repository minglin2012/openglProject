OpenGLTutorial : main.cpp Display.cpp  Mesh.cpp Shader.cpp Texture.cpp stb_image.c
	gcc $^ -o $@ -lSDL2 -lGLEW -lstdc++

clean : 
	rm OpenGLTutorial
