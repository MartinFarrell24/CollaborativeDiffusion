#include"Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::init(SDL_Renderer* renderer, const char* path, Vector2 pos, bool isObstacle)
{
	SDL_Surface* surface = SDL_LoadBMP(path);

	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	m_pos = pos;
	m_dstRect->x = pos.x; m_dstRect->y = pos.y; m_dstRect->w = 32; m_dstRect->h = 32;
	m_isObstacle = isObstacle;
	m_center = Vector2(pos.x + 16, pos.y + 16);
	m_cost = 0;
	m_isObstacle = isObstacle;
}

void Tile::render(SDL_Renderer*& renderer)
{
	SDL_RenderCopy(renderer, m_texture, NULL, m_dstRect);

	if (!m_isObstacle && m_end.x != 0)
	{
		SDL_RenderDrawLine(renderer, m_center.x, m_center.y, m_end.x, m_end.y);
	}
}

void Tile::setStart(bool start)
{
	m_start = start;
}

void Tile::setGoal(bool goal)
{
	m_goal = goal;
}

void Tile::setPath(bool path)
{
	m_path = path;
}

void Tile::setVisited(bool visited)
{
	m_visited = visited;
}

void Tile::setEnd(Vector2 end)
{
	m_end = end;
}

void Tile::addAdjacent(Tile& mapTile)
{
	m_adjacents.push_back(&mapTile);
}

void Tile::setPrevious(Tile& mapTile)
{
	m_previous = &mapTile;
}

bool Tile::getIsObstacle()
{
	return m_isObstacle;
}

bool Tile::getStart()
{
	return m_start;
}

bool Tile::getGoal()
{
	return m_goal;
}

bool Tile::getPath()
{
	return m_path;
}

bool Tile::getVisited()
{
	return m_visited;
}

Vector2 Tile::getEnd()
{
	return m_end;
}

Vector2 Tile::getCenter()
{
	return m_center;
}

Vector2 Tile::getPosition()
{
	return m_pos;
}

int Tile::getCost()
{
	return m_cost;
}

std::list<Tile*>& Tile::getAdjacents()
{
	return m_adjacents;
}

Tile* Tile::getPrevious()
{
	return m_previous;
}
