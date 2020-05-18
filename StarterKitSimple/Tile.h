#pragma once
#include"SDL.h"
#include"Vector2.h"
#include<list>
class Tile
{
public:
	Tile();
	~Tile();


	void init(SDL_Renderer* renderer, const char* path, Vector2 pos, bool isObstacle);
	void render(SDL_Renderer*& renderer);


	void setStart(bool start);
	void setGoal(bool goal);
	void setPath(bool path);
	void setVisited(bool visited);
	void setEnd(Vector2 end);
	void addAdjacent(Tile& mapTile);
	void setPrevious(Tile& mapTile);

	bool getIsObstacle();
	bool getStart();
	bool getGoal();
	bool getPath();
	bool getVisited();
	Vector2 getEnd();
	Vector2 getCenter();
	Vector2 getPosition();
	int getCost();
	std::list<Tile*>& getAdjacents();
	Tile* getPrevious();

private:
	bool m_isObstacle, m_start, m_goal, m_path, m_visited;
	Vector2 m_pos;
	Vector2 m_center;
	Vector2 m_end;
	SDL_Texture* m_texture;
	SDL_Rect* m_dstRect = new SDL_Rect;
	int m_cost;
	Tile* m_previous;
	std::list<Tile*> m_adjacents;

};
