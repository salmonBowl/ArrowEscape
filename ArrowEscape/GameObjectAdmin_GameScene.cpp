#include "GameObjectAdmin_GameScene.h"

#include <memory>
#include "AllGameObjects_GameScene.h"

void GameObjectAdmin_GameScene::InitAllGameObject()
{
	// �I�u�W�F�N�g�̔z�u���s���܂�

	Instantiate(AllGraphName::Background);
	
	Instantiate(AllGraphName::Player, Vector2f{ 6, 0 });

	GameObjectAdmin::InitAllGameObject();
}