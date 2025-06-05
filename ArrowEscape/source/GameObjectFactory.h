#pragma once
#include <memory>
#include "GameObject.h"
#include "Sprite.h"
#include "EnterValue.h"

class GameObjectFactory
{
public:
	
	static std::shared_ptr<GameObjectFactory> Instance();

	std::unique_ptr<GameObject> CreateGameObject(GameObjectType name);

private:
	
	static std::shared_ptr<GameObjectFactory> instance;

	std::unique_ptr<Sprite> CreateSprite(ImageAssetID name);
};