#pragma once
#include <memory>
#include "GameObject.h"
#include "ImageManager.h"

class GameObjectFactory
{
public:
	static std::unique_ptr<GameObject> Create(AllGraphName name);
};