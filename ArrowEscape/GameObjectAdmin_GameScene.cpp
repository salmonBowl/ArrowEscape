#include "GameObjectAdmin_GameScene.h"

#include <memory>
#include "AllGameObjects_GameScene.h"

void GameObjectAdmin_GameScene::InitAllGameObject()
{
	// background //BackgroundÉNÉâÉXÇ…èCê≥ó\íË
	Instantiate(std::make_unique<Sprite>("background.png", EnterValue::GameScene::Background::ImageMagnification, EnterValue::GameScene::Background::Offset));
	
	// Player
	Instantiate(std::make_unique<Player>(), Vector2f{ 6, 0 });

	GameObjectAdmin::InitAllGameObject();
}