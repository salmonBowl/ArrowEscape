#include "Player.h"
#include "Image.h"
#include "EnterValue.h"

Player::Player()
{
	handle = Image::Instance()->LoadGraph("player.png", EnterValue::GameScene::Player::ImageMagnification);
	offset = EnterValue::GameScene::Player::Offset;
}

void Player::Execute()
{

}