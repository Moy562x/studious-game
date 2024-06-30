#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int NUM_LINES = 100;

int main(int argc, char* argv[])
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	// create window
	// returns pointer to window if successful or nullptr if failed
	SDL_Window* window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	while (true)
	{
		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		// draw line
		/*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderDrawLine(renderer, 400, 100, 300, 400);
		SDL_RenderDrawLine(renderer, 300, 400, 500, 400);
		SDL_RenderDrawLine(renderer, 500, 400, 400, 100);*/

		// Draw random lines
		for (int i = 0; i < NUM_LINES; ++i) {
			SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
			int x1 = rand() % SCREEN_WIDTH;
			int y1 = rand() % SCREEN_HEIGHT;
			int x2 = rand() % SCREEN_WIDTH;
			int y2 = rand() % SCREEN_HEIGHT;
			SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		}



		// show screen
		SDL_RenderPresent(renderer);
	}

	return 0;
}