#include "GameObjectFactory.h"

#include "ImageManager.h"

#include "Player.h"
#include "Background.h"

std::shared_ptr<GameObjectFactory> GameObjectFactory::instance = nullptr;

std::shared_ptr<GameObjectFactory> GameObjectFactory::Instance()
{
	if (!instance)
	{
		instance = std::make_unique<GameObjectFactory>();
	}
	return instance;
}

std::unique_ptr<GameObject> GameObjectFactory::CreateGameObject(GameObjectType name)
{
	std::unique_ptr<Sprite> gameObject;

	switch (name)
	{
	case GameObjectType::Player:
		gameObject = CreateSprite(ImageAssetID::PlayerImage);
		break;
	case GameObjectType::Background:
		gameObject = CreateSprite(ImageAssetID::BackgroundImage);
		break;
	default:
		return nullptr;
		break;
	}

	return gameObject;
}
std::unique_ptr<Sprite> GameObjectFactory::CreateSprite(ImageAssetID name)
{
	std::unique_ptr<Sprite> sprite;

	switch (name)
	{
	case ImageAssetID::PlayerImage:
		sprite = std::make_unique<Player>();
		break;
	case ImageAssetID::BackgroundImage:
		sprite = std::make_unique<Background>();
		break;
	default:
		return nullptr;
		break;
	}

	auto imageManager = ImageManager::Instance();

	// 開始時に全て読み込んであるためもう不要
	//imageManager->LoadIfNeeded(name);

	const auto& info = imageManager->GetInfo(name);

	sprite->SetInitalState_Sprite(info.handle, info.offset);

	return sprite;
}