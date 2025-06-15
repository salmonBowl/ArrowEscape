#pragma once
#include "Sprite.h"
#include "Vector2.h"
#include "EnterValue.h"

class Background : public Sprite
{
public:
	Background() { }

	float Width = EnterValue::GameScene::Background::StageWidth;
	float Height = EnterValue::GameScene::Background::StageHeight;

	float GroundLevel = EnterValue::GameScene::Background::GroundLevel;
	Vector2f GravityForce = { 0, -EnterValue::GameScene::Background::GravityVolume };
};