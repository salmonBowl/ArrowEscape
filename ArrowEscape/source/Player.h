#pragma once
#include "Sprite.h"

class Player : public Sprite
{
public:
	Player();

	void Execute() override;
};
