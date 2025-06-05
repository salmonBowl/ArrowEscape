#pragma once
#include "Sprite.h"
#include "EnterValue.h"

class Background : public Sprite
{
public:
	Background() { }

	float stageWidth = EnterValue::GameScene::Background::StageWidth;
	float stageHeight = EnterValue::GameScene::Background::StageHeight;
};