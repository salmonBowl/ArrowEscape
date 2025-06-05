#include "GameObjectAdmin_GameScene.h"

#include <memory>

void GameObjectAdmin_GameScene::InitAllGameObject()
{
	// オブジェクトの配置を行います

	Instantiate(GameObjectType::Background);
	
	Instantiate(GameObjectType::Player, Vector2f{ 6, 0 });

	GameObjectAdmin::InitAllGameObject();
}