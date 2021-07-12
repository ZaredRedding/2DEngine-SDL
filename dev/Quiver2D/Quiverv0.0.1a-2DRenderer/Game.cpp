#include "Game.h"

Game::Game()
{
	mainWindow = nullptr;
	mainIsRunning = true;
}

bool Game::Initialize()
{
	bool sdlInitResult = (SDL_Init(SDL_INIT_VIDEO) != 0) ? false : true;

	if (!sdlInitResult)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}

	mainWindow = SDL_CreateWindow( "Quiver v0.0.1a | 2D Rendering", 100, 100, 1024, 768, 0);

	if (!mainWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!mainRenderer)
	{
		SDL_Log("Failed to initialize renderer: %s", SDL_GetError());
		return false;
	}

	return sdlInitResult;
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

void Game::RunLoop()
{
	while (mainIsRunning)
	{
		ProcessInput();

		UpdateGame();

		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	//Register and execute all events
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				mainIsRunning = false;
				break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_ESCAPE])
	{
		mainIsRunning = false;
	}
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mainRenderer, 128, 64, 255, 255);

	SDL_RenderClear(mainRenderer);

	SDL_RenderPresent(mainRenderer);
}