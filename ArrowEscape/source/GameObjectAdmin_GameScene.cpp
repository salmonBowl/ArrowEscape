#include "GameObjectAdmin_GameScene.h"

#include <memory>

void GameObjectAdmin_GameScene::InitAllGameObject()
{
	// �I�u�W�F�N�g�̔z�u���s���܂�

	Instantiate(GameObjectType::Background);
	
	Instantiate(GameObjectType::Player, Vector2f{ 6, 0 });

	GameObjectAdmin::InitAllGameObject();
}