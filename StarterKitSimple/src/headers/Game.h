#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <SDL.h>
#include <Tile.h>
#include <vector>
#include "Player.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include"playerObject.h"
class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();

	Tile m_maptiles[30][30];

private:
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
	PlayerObject* m_player = nullptr;
	std::vector<Tile*> m_tiles;
};
#endif

