#pragma once

#include <string>
#include <SDL2/SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	void SwapBuffers();
	void Update();
	bool IsClosed(){ return m_isClosed;}
	void Clear(float r, float g, float b, float a); 
	~Display();
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};
