OpenGLTutorial : main.cpp Display.cpp  Mesh.cpp Shader.cpp
	g++ $^ -o $@ -lSDL2 -lGLEW

clean : 
	rm OpenGLTutorial
