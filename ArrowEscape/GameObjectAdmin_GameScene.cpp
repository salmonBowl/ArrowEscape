#include "GameObjectAdmin_GameScene.h"

#include <memory>
#include "AllGameObjects_GameScene.h"

void GameObjectAdmin_GameScene::InitAllGameObject()
{
	// オブジェクトの配置を行います

	Instantiate(AllGraphName::Background);
	
	Instantiate(AllGraphName::Player, Vector2f{ 6, 0 });

	GameObjectAdmin::InitAllGameObject();
}