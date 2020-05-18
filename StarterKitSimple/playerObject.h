#pragma once
#include"Vector2.h"
#include"SDL.h"
class PlayerObject
{
public:
	PlayerObject(SDL_Renderer* window);
	~PlayerObject();

	void up();
	void Down();
	void left();
	void right();
	void update();
	void render(SDL_Renderer* window);
	void initPos(Vector2 newPos);
	void loadTexture(SDL_Renderer *window, SDL_Texture *newTexture);


private:
	Vector2 pos;
	SDL_Texture *texture;
	SDL_Rect *m_body = new SDL_Rect;
	int speed = 32;
	SDL_Surface* surface;
};

