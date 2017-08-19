OpenGLTutorial : main.cpp Display.cpp  Mesh.cpp
	g++ $^ -o $@ -lSDL2 -lGLEW

clean : 
	rm OpenGLTutorial
