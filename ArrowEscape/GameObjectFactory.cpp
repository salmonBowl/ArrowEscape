#include "GameObjectFactory.h"

#include "Player.h"
#include "Background.h"

std::unique_ptr<GameObject> GameObjectFactory::Create(AllGraphName name)
{
	switch (name)
	{
	case AllGraphName::Player:
		return std::make_unique<Player>();
	case AllGraphName::Background:
		return std::make_unique<Background>();
	default:
		return nullptr;
	}
}