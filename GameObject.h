#pragma once
#include "Globals.h"
#include "Point.h"
#include "Collider.h"
#include <vector>

class GameObject
{
public:
	GameObject() {}
	//~GameObject() {}

	fPoint posp;
	fPoint localpos;
	bool visible = true;
	GameObject* parent = NULL;
	item_type type;
	float xoffset = 0;
	float yoffset = 0;
	bool deleteme = false;


	virtual void OnCollisionEnter(Collider* ColWith)
	{

	}

	void SetGameObj(float x, float y, float offsetx, float offsety, bool vis, item_type item, bool del)
	{
		posp.x = x;
		posp.y = y;
		localpos.x = x;
		localpos.y = y;
		visible = vis;
		type = item;
		deleteme = del;
		xoffset = offsetx;
		yoffset = offsety;
	}

	void SetGameObj(float x, float y, float offsetx, float offsety, bool vis, item_type item, bool del, GameObject* dad)
	{
		posp.x = x;
		posp.y = y;
		localpos.x = x;
		localpos.y = y;
		visible = vis;
		type = item;
		deleteme = del;
		parent = dad;
		xoffset = offsetx;
	}


	virtual void Update()
	{
	}
	virtual void LateUpdate()
	{
	}
	virtual void RenderGameObj()
	{
	}

	ColDir CollisionDir(Collider* ColWith, Collider* mycol)
	{
		ColDir from;
		if (ColWith->rect.x > (posp.x - mycol->rect.w) && ColWith->rect.x < (posp.x + (mycol->rect.w / 2)))
		{
			if (ColWith->rect.y <= (posp.y - ColWith->rect.h) + 5)
			{
				LOG("Collision desde arriba!");
				return from = updir;
			}
			else if (ColWith->rect.y >= (posp.y + mycol->rect.h) - 5)
			{
				LOG("Collision desde abajo!");
				return from = downdir;
			}
		}
		if (ColWith->rect.y > (posp.y - ColWith->rect.h) + 5 && ColWith->rect.y < (posp.y + mycol->rect.h) - 5)
		{
			if (ColWith->rect.x < posp.x - (mycol->rect.w / 2) - ColWith->rect.w + 5)
			{
				LOG("Collision desde izquierda!");
				return from = leftdir;
			}
			else if (ColWith->rect.x >(posp.x + (mycol->rect.w / 2) - 5))
			{
				LOG("Collision desde derecha!");
				return from = rightdir;
			}
		}
	}

};