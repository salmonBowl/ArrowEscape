#pragma once
#include <memory>
#include "GameObject.h"
#include "Sprite.h"
#include "EnterValue.h"
#include "SingletonBase.h"

class GameObjectFactory : public SingletonBase<GameObjectFactory>
{
	friend class SingletonBase<GameObjectFactory>;
public:

	std::unique_ptr<GameObject> CreateGameObject(GameObjectType name);

private:

	std::unique_ptr<Sprite> CreateSprite(ImageAssetID name);
};