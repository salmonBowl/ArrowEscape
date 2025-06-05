#include "GameScene.h"

#include <memory>
#include "GameObjectAdmin_GameScene.h"

GameScene::GameScene()
{
	pGameObjectAdmin = std::make_unique<GameObjectAdmin_GameScene>();
}
