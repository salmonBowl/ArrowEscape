#include "Player.h"
#include "ImageManager.h"
#include "EnterValue.h"

Player::Player()
{
	ImageManager::GenerateInfo generateInfo = ImageManager::Instance()->GetInfo(AllGraphName::Player);;
	handle = generateInfo.handle;
	offset = generateInfo.offset;
}

void Player::Execute()
{

}