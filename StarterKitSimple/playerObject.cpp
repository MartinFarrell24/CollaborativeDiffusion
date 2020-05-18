#include "playerObject.h"

PlayerObject::PlayerObject(SDL_Renderer* window)
{
	
	pos.x = 3 * 32;
	pos.y = 25 * 32;
	m_body->x = pos.x;
	m_body->y = pos.y;
	initPos(Vector2(96, 800));

}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::up()
{
	pos.y -= speed;
	m_body->y = pos.y;
}

void PlayerObject::Down()
{
	pos.y += speed;
	m_body->y = pos.y;
}

void PlayerObject::left()
{
	pos.x -= speed;
	m_body->x = pos.x;
}

void PlayerObject::right()
{
	pos.x += speed/60;
	m_body->x = pos.x;
	m_body->y = pos.y;
}

void PlayerObject::update()
{
}

void PlayerObject::render(SDL_Renderer* window)
{
	SDL_RenderCopy(window, texture, NULL, m_body);
}

void PlayerObject::initPos(Vector2 newPos)
{
	pos = pos;
	m_body->w = 32;
	m_body->h = 32;
}

void PlayerObject::loadTexture(SDL_Renderer *window, SDL_Texture *newTexture)
{
	surface = SDL_LoadBMP("Assets/player.bmp");
	texture = SDL_CreateTextureFromSurface(window, surface);
	SDL_FreeSurface(surface);
}
