#include <GL/glew.h>
#include "Display.h"

int main(int argc, char** argv)
{
	Display display(800,600,"www.xoxo.work");
	while (!display.IsClosed())
	{
		display.Clear(0.0f,0.15f,0.3f,1.0f);
		display.Update();
	}

}
