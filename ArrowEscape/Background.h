#pragma once
#include "GameObject.h"
#include "EnterValue.h"

class Background : GameObject
{
public:
	float stageWidth = EnterValue::GameScene::Background::StageWidth;
	float stageHeight = EnterValue::GameScene::Background::StageHeight;
};