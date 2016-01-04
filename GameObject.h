#pragma once
#include "Animation.h"
#include "Globals.h"
#include "Point.h"
#include <vector>

class GameObject
{
public:
	GameObject() {}
	//~GameObject() {}

	fPoint posp;
	fPoint localpos;
	bool visible = false;
	GameObject* parent = NULL;
	item_type type;
	float xoffset;
	float yoffset;
	bool deleteme = false;


	virtual void OnCollisionEnter(GameObject* ColWith)
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


};