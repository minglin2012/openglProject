OpenGLTutorial : main.cpp Display.cpp 
	g++ $^ -o $@ -lSDL2 -lGLEW

clean : 
	rm OpenGLTutorial
